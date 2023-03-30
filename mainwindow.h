#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <memory>
#include "tile.h"
#include <random>
#include "tileButton.h"
#include <map>
#include <set>
#include <QTimer>
#include <QStatusBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private:
    void floodFill(std::shared_ptr<Tile> tile);
    void revealBombs();
    void updateStats();
    void resetBoard();
    void shuffle();
    void updateBombBorder();
    void connectButtons(bool enabled);
    void updateBombIndices();


private slots:

    static void quit();

    void sync();

    void tileUpdated(std::shared_ptr<Tile> tile);

    void shuffleSlot(){shuffle();};

private:
    Ui::MainWindow* ui;
    std::vector<std::shared_ptr<tileButton>> m_buttons; //maybe change to shared pointer
    std::vector<std::shared_ptr<Tile>> m_tiles;
    std::set<std::shared_ptr<Tile>> m_flooded; //NOTE: possibly remove. just dont call flood on tiles that are revealed
    std::shared_ptr<Tile> grid[16][16];
    std::set<int> bombIndices;
    int numCleared = 0;
    int numFlags = 0;
    bool firstClickTaken = false;

    const int numBombs = 40;
    const int NUMBER_OF_COLUMNS = 16;
    const int NUMBER_OF_TILES = NUMBER_OF_COLUMNS * NUMBER_OF_COLUMNS;

};

#endif // MAINWINDOW_H