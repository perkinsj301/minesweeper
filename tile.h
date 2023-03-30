#ifndef CARD_H
#define CARD_H

#include <QIcon>
#include <QString>
#include <QObject>

class Tile : public QObject, public std::enable_shared_from_this<Tile>{

    Q_OBJECT

public:

    enum tile_t {
        blank = 0,
        one, two, three, four, five, six, seven, eight, bomb
    };
    enum state_t {
        unclicked = 0, flagged, clicked
    };

    explicit Tile(QString iconName, tile_t type);

    [[nodiscard]] const QIcon& icon() const {

        return m_icon;
    }

    void setTile(tile_t type){
        m_type = type;
    }

    void setState(state_t state){
        m_state = state;
    }

    void resetTile();

    tile_t getType(){
        return m_type;
    }

    state_t getState(){
        return m_state;
    }

    void reveal();

    void toggleFlagFunc();

    void iconUpdateFunc();

    public slots:

    void toggleFlag(){toggleFlagFunc();};

    void revealSlot(){
        reveal();
    emit tileClicked(shared_from_this());};

    signals:
    void iconUpdated(std::shared_ptr<Tile> tile);
    void flagToggled(std::shared_ptr<Tile> tile);
    void tileClicked(std::shared_ptr<Tile> tile);


private:
    tile_t m_type;
    state_t m_state = unclicked;
    QIcon m_icon;
};

#endif // CARD_H
