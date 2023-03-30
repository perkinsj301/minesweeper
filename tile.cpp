#include "tile.h"
#include <cassert>

Tile::Tile(QString iconName, tile_t type) : m_icon(iconName) {
    assert(!m_icon.isNull());
    m_type = type;
    m_state = unclicked;
}

void Tile::toggleFlagFunc() {
    if (m_state == unclicked) {
        m_icon = QIcon(":/flag.png");
        m_state = flagged;
        emit iconUpdated(shared_from_this());
    }
    else if (m_state == flagged){
        m_icon = QIcon(":/unclicked.png");
        m_state = unclicked;
        emit iconUpdated(shared_from_this());
    }
    emit tileClicked(shared_from_this());
}

void Tile::iconUpdateFunc() {
    //set new icon to match the tile type
    switch (m_type) {
        case one:
            m_icon = QIcon(":/1.png");
            break;
        case two:
            m_icon = QIcon(":/2.png");
            break;
        case three:
            m_icon = QIcon(":/3.png");
            break;
        case four:
            m_icon = QIcon(":/4.png");
            break;
        case five:
            m_icon = QIcon(":/5.png");
            break;
        case six:
            m_icon = QIcon(":/6.png");
            break;
        case seven:
            m_icon = QIcon(":/7.png");
            break;
        case eight:
            m_icon = QIcon(":/8.png");
            break;
        case blank:
            m_icon = QIcon(":/blank.png");
            break;
        case bomb:
            m_icon = QIcon(":/bomb.png");
            break;
    }
    m_state = clicked;

    //notify corresponding button to change its icon
    emit iconUpdated(shared_from_this());
    //emit tileClicked(shared_from_this());
}

void Tile::reveal() {
    //only allow tile to be revealed if not flagged
    if(m_state == unclicked)
        iconUpdateFunc();
}

void Tile::resetTile(){
    m_state = unclicked;
    m_icon = QIcon(":/unclicked.png");
    emit iconUpdated(shared_from_this());
}