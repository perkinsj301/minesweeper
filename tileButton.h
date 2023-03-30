//
// Created by perki on 2/23/2023.
//

#ifndef CARDMATCH_CARDBUTTON_H
#define CARDMATCH_CARDBUTTON_H

#include <QPushButton>
#include "tile.h"
#include <QWidget>
#include <QMouseEvent>


class tileButton : public QPushButton, public std::enable_shared_from_this<tileButton>{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *event) {
        {
            if (event->buttons() & Qt::LeftButton)
            {
                emit clicked();
            }
            else if (event->buttons() & Qt::RightButton)
            {
                emit rightClicked();
            }
        }
    }
signals:
    void rightClicked();

public slots:
    void setIconSlot(std::shared_ptr<Tile> tile){
        this->setIcon(tile->icon());
    }

};
#endif //CARDMATCH_CARDBUTTON_H
