#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QWidget>
#include "widget.h"
#include "option.h"
#include "QBoxLayout"
#include "QPushButton"

#include "configurationfile.h"

class mainMenu : public QWidget
{
    Q_OBJECT
public:
    mainMenu(QWidget *parent = 0);
    ~mainMenu();
private:
    QVBoxLayout *menuLayout;
    QPushButton *btn_start;
    QPushButton *btn_exit;
    QPushButton *btn_opiton;
    Widget *widget;
    Option *option = new Option();
public slots:
    void start();
    void deleteWidget();
    void restart();
    void optionShow();
};

#endif // MAINMENU_H
