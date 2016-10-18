#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QBoxLayout"
#include "QPushButton"
#include "game.h"

class Widget : public QDialog
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    Game *game;
private:
    QPushButton *btn[3][3];
    QGridLayout *Glayout;
};

#endif // WIDGET_H
