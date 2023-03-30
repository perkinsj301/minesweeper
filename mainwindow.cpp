#include <cassert>
#include <algorithm>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const QSize TILE_SIZE(20, 20);
    const QSize CARD_SIZE(20, 20);
    const QSize BUTTON_SIZE(22,22);
    const QString button_style = "border: 2px solid black";

    ui->gridLayout->setSpacing(0);
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);


    //create all the tiles and add corresponding buttons to the window
    for (int i = 0; i < NUMBER_OF_TILES; ++i) {

        //create new blank tile
        const QString tile_name = ":/unclicked.png";
        auto tile = std::make_shared<Tile>(tile_name,Tile::blank);
        m_tiles.push_back(tile);

        //create and style new button
        auto button = std::make_shared<tileButton>();
        button->setIcon(tile->icon());
        button->setIconSize(CARD_SIZE);
        button->setFlat(true);
        button->setFixedSize(BUTTON_SIZE);
        button->setStyleSheet(button_style);
        m_buttons.push_back(button);

        //add button to layout
        int row = i / NUMBER_OF_COLUMNS;
        int column = i % NUMBER_OF_COLUMNS;
        ui->gridLayout->addWidget(m_buttons.back().get(), row, column);
    }

    //determine where bombs should go
    for(int i = 0; i < 40; i++){
        int bombIndex = rand() % NUMBER_OF_TILES;
        //if number generated is already used, generate new ones till  a unique on comes out
        while(bombIndices.find(bombIndex) != bombIndices.end()){
            bombIndex = rand() % NUMBER_OF_TILES;
        }
        bombIndices.insert(bombIndex);
        //turn the appropriate tile into a bomb
        m_tiles[bombIndex]->setTile(Tile::bomb);
    }

    //add tiles to grid
    for(int i = 0; i < NUMBER_OF_TILES; ++i){
        int row = i / NUMBER_OF_COLUMNS;
        int column = i % NUMBER_OF_COLUMNS;
        grid[column][row] = m_tiles[i];
    }

    //iterate through tiles and check all neighbors for bombs
    updateBombBorder();


    //connect signals and slots between the buttons, tiles, and main window
    connectButtons(true);
    
    //connect the game control buttons
    QObject::connect(ui->shuffleButton, SIGNAL(clicked()),
                     this, SLOT(shuffleSlot()));
    QObject::connect(ui->quitButton, SIGNAL(clicked()),
                     this, SLOT(quit()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::quit() {
    QApplication::quit();
}

void MainWindow::sync() {
    // synchronize the button icons with the cards
    auto tileIt = m_tiles.begin();
    auto buttonIt = m_buttons.begin();
    //for (auto& button : m_buttons){button->disconnect(SIGNAL(clicked))}
    while (tileIt != m_tiles.end()) {
        auto card = tileIt->get(); //prolly gonna change vector to shared ptr,hopefully doesn't break
        (*buttonIt)->setIcon(card ->icon());
        ++tileIt;
        ++buttonIt;
    }
    assert(buttonIt == m_buttons.end());
}

void MainWindow::floodFill(std::shared_ptr<Tile> tile) {
    //add tile to m_flooded so it doesn't try to get flooded by neighbors
    m_flooded.insert(tile);

    //first, find the tile in the grid
    int tileRow;
    int tileColumn;
    for(int i = 0; i < NUMBER_OF_TILES; ++i) {
        int row = i / NUMBER_OF_COLUMNS;
        int column = i % NUMBER_OF_COLUMNS;
        if(grid[column][row] == tile){
            tileRow = row;
            tileColumn = column;
            break;
        }
    }
    std::vector<std::shared_ptr<Tile>> neighbors;
    //if tile is blank, it's safe to reveal all neighboring tiles-------
    if(grid[tileColumn][tileRow]->getType() == Tile::blank) {
        //all tiles in left column-----------------
        if (tileColumn > 0 && m_flooded.find(grid[tileColumn - 1][tileRow]) == m_flooded.end()) {
            //west
            neighbors.push_back(grid[tileColumn - 1][tileRow]);
            neighbors.back()->reveal();

            //northwest
            if (tileRow > 0 && m_flooded.find(grid[tileColumn - 1][tileRow - 1]) == m_flooded.end()) {
                neighbors.push_back(grid[tileColumn - 1][tileRow - 1]);
                neighbors.back()->reveal();
            }
            //southwest
            if (tileRow < NUMBER_OF_COLUMNS - 1  && m_flooded.find(grid[tileColumn - 1][tileRow + 1]) == m_flooded.end()) {
                neighbors.push_back(grid[tileColumn - 1][tileRow + 1]);
                neighbors.back()->reveal();
            }
        }
        //all tiles in current column------------
        //north
        if (tileRow > 0 && m_flooded.find(grid[tileColumn][tileRow - 1]) == m_flooded.end()) {
            neighbors.push_back(grid[tileColumn][tileRow - 1]);
            neighbors.back()->reveal();
        }
        //south
        if (tileRow < NUMBER_OF_COLUMNS - 1 && m_flooded.find(grid[tileColumn][tileRow + 1]) == m_flooded.end()) {
            neighbors.push_back(grid[tileColumn][tileRow + 1]);
            neighbors.back()->reveal();
        }

        //all tiles in right column------------------
        if (tileColumn < NUMBER_OF_COLUMNS - 1  && m_flooded.find(grid[tileColumn + 1][tileRow]) == m_flooded.end()) {
            //east
            neighbors.push_back(grid[tileColumn + 1][tileRow]);
            neighbors.back()->reveal();

            //northeast
            if (tileRow > 0  && m_flooded.find(grid[tileColumn + 1][tileRow - 1]) == m_flooded.end()) {
                neighbors.push_back(grid[tileColumn + 1][tileRow - 1]);
                neighbors.back()->reveal();
            }
            //southeast
            if (tileRow < NUMBER_OF_COLUMNS - 1 && m_flooded.find(grid[tileColumn + 1][tileRow + 1]) == m_flooded.end()) {
                neighbors.push_back(grid[tileColumn + 1][tileRow + 1]);
                neighbors.back()->reveal();
            }
        }
    }

    //for each neighboring tile, check if its also blank
    auto tileIt = neighbors.begin();
    while (tileIt != neighbors.end()) {
        //if neighboring tile is also blank, recursively call on neighbor
        if(tileIt->get()->getType() == Tile::blank)
            floodFill((*tileIt));
        ++tileIt;
    }
}

void MainWindow::tileUpdated(std::shared_ptr<Tile> tile) {
    //if blank tile is clicked, do flood fill
    if(tile->getState() == Tile::clicked && tile->getType() == Tile::blank) {
        floodFill(tile);
        firstClickTaken = true;
    }
    //if bomb is clicked, the game is lost (unless first click)
    else if(tile->getState() == Tile::clicked && tile->getType() == Tile::bomb){
        //if a bomb is clicked on first turn, move the bomb
        if(!firstClickTaken){
            //generate new index
            int bombIndex = rand() % NUMBER_OF_TILES;
            //if number generated is already used, generate new ones till  a unique on comes out
            while(bombIndices.find(bombIndex) != bombIndices.end()){
                bombIndex = rand() % NUMBER_OF_TILES;
            }
            bombIndices.insert(bombIndex);
            //turn the appropriate tile into a bomb
            m_tiles[bombIndex]->setTile(Tile::bomb);

            tile->setTile(Tile::one); //just makes tile something other than bomb so updateBombBorder works right
            updateBombIndices();
            updateBombBorder();
            tile->iconUpdateFunc();
        }
        else {
            revealBombs();
            QMessageBox Msgbox;
            Msgbox.setText("You lost!");
            Msgbox.exec();
            shuffle();
            resetBoard();
        }

    }
    else{
        firstClickTaken = true;
    }

    //make sure the counts of flags and cleared tiles are updated
    updateStats();

    //make sure not too many flags are used
    if (numFlags > numBombs){
        tile->toggleFlagFunc(); //pretty sure tileUpdated gets called again , but still works tho
    }

    //update status bar
    QString text = "Flags: " + QLocale().toString(numFlags) + "/40 - Cleared: " + QLocale().toString(numCleared) + "/216";
    ui->Stats->setText(text);

    //check to see if the game was won
    if(numCleared == (NUMBER_OF_TILES - numBombs)){
        QMessageBox Msgbox;
        Msgbox.setText("You win!");
        Msgbox.exec();
        shuffle();
        resetBoard();
    }


}

void MainWindow::updateStats() {
    int cleared = 0;
    int flagged = 0;
    auto tileIt = m_tiles.begin();
    while (tileIt != m_tiles.end()){
       auto tile = tileIt->get();
       if(tile->getType() != Tile::bomb && tile->getState() == Tile::clicked)
           ++cleared;
       else if(tile->getState() == Tile::flagged)
           ++flagged;
        ++tileIt;
    }
    numFlags = flagged;
    numCleared = cleared;
}

void MainWindow::revealBombs() {
    auto bombIt = bombIndices.begin();
    while (bombIt != bombIndices.end()){
        m_tiles[(*bombIt)]->setState(Tile::unclicked);
        m_tiles[(*bombIt)]->reveal();
        ++bombIt;
    }
}

void MainWindow::resetBoard() {
    auto bombIt = m_tiles.begin();
    while (bombIt != m_tiles.end()){
        bombIt->get()->resetTile();
        ++bombIt;
    }
    m_flooded.clear();
    firstClickTaken = false;
}

void MainWindow::shuffle(){
    connectButtons(false);

    //shuffle tile vector
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(m_tiles),std::end(m_tiles),rng);

    //add tiles to grid
    for(int i = 0; i < NUMBER_OF_TILES; ++i){
        int row = i / NUMBER_OF_COLUMNS;
        int column = i % NUMBER_OF_COLUMNS;
        grid[column][row] = m_tiles[i];
    }

    updateBombIndices();

    updateBombBorder();

    connectButtons(true);

    //update buttons of clicked tiles to show right icon
    auto tileIt = m_tiles.begin();
    while (tileIt != m_tiles.end()){
        if(tileIt->get()->getState() == Tile::clicked)
            tileIt->get()->iconUpdateFunc();
        ++tileIt;
    }

    sync();

}

void MainWindow::updateBombIndices() {
    bombIndices.clear();
    int j = 0;
    auto it = m_tiles.begin();
    while (it != m_tiles.end()){
        if(it->get()->getType() == Tile::bomb)
            bombIndices.insert(j);
        ++it;
        ++j;
    }
}


void MainWindow::updateBombBorder() {
    for(int i = 0; i < NUMBER_OF_TILES; ++i){
        int row = i / NUMBER_OF_COLUMNS;
        int column = i % NUMBER_OF_COLUMNS;
        int bombCount = 0;

        //if tile isn't already a bomb, check to see how many bombs it borders
        if(grid[column][row]->getType() != Tile::bomb) {
            //all tiles in left column-----------------
            if (column > 0) {
                //west
                if (grid[column - 1][row]->getType() == Tile::bomb)
                    bombCount++;
                //northwest
                if (row > 0) {
                    if (grid[column - 1][row - 1]->getType() == Tile::bomb)
                        bombCount++;
                }
                //southwest
                if (row < NUMBER_OF_COLUMNS - 1) {
                    if (grid[column - 1][row + 1]->getType() == Tile::bomb)
                        bombCount++;
                }
            }
            //all tiles in current column------------
            //north
            if (row > 0) {
                if (grid[column][row - 1]->getType() == Tile::bomb)
                    bombCount++;
            }
            //south
            if (row < NUMBER_OF_COLUMNS - 1) {
                if (grid[column][row + 1]->getType() == Tile::bomb)
                    bombCount++;
            }
            //all tiles in right column------------------
            if (column < NUMBER_OF_COLUMNS - 1) {
                //east
                if (grid[column + 1][row]->getType() == Tile::bomb)
                    bombCount++;
                //northeast
                if (row > 0) {
                    if (grid[column + 1][row - 1]->getType() == Tile::bomb)
                        bombCount++;
                }
                //southeast
                if (row < NUMBER_OF_COLUMNS - 1) {
                    if (grid[column + 1][row + 1]->getType() == Tile::bomb)
                        bombCount++;
                }
            }
            grid[column][row]->setTile((Tile::tile_t) bombCount);
        }
    }
}

void MainWindow::connectButtons(bool enabled) {
    if(enabled){
        auto tileIt = m_tiles.begin();
        auto buttonIt = m_buttons.begin();
        while (tileIt != m_tiles.end()) {
            auto tile = tileIt->get();
            QObject::connect(buttonIt->get(), SIGNAL(rightClicked()),
            tile, SLOT(toggleFlag()));
            QObject::connect(buttonIt->get(), SIGNAL(clicked()),
            tile, SLOT(revealSlot()));
            QObject::connect(tile, SIGNAL(iconUpdated(std::shared_ptr<Tile>)),
            buttonIt->get(), SLOT(setIconSlot(std::shared_ptr<Tile>)));
            QObject::connect(tile, SIGNAL(tileClicked(std::shared_ptr<Tile>)),
            this, SLOT(tileUpdated(std::shared_ptr<Tile>)));

            ++tileIt;
            ++buttonIt;
        }
    }
    else{
        auto tileIt = m_tiles.begin();
        auto buttonIt = m_buttons.begin();
        while (tileIt != m_tiles.end()) {
            auto tile = tileIt->get();
            QObject::disconnect(buttonIt->get(), SIGNAL(rightClicked()),
            tile, SLOT(toggleFlag()));
            QObject::disconnect(buttonIt->get(), SIGNAL(clicked()),
            tile, SLOT(revealSlot()));
            QObject::disconnect(tile, SIGNAL(iconUpdated(std::shared_ptr<Tile>)),
            buttonIt->get(), SLOT(setIconSlot(std::shared_ptr<Tile>)));
            QObject::disconnect(tile, SIGNAL(tileClicked(std::shared_ptr<Tile>)),
            this, SLOT(tileUpdated(std::shared_ptr<Tile>)));

            ++tileIt;
            ++buttonIt;
        }
    }
}









