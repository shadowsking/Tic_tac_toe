#include "mainmenu.h"
#include "QDebug"

mainMenu::mainMenu(QWidget *parent) : QWidget(parent)
{
    setFixedSize(150, 150);
    setWindowTitle("Tic Tac Toe");
    btn_start = new QPushButton("Start");
    btn_opiton = new QPushButton("Option");
    btn_exit = new QPushButton("Exit");

    menuLayout = new QVBoxLayout();
    menuLayout->addWidget(btn_start);
    menuLayout->addWidget(btn_opiton);
    menuLayout->addWidget(btn_exit);
    setLayout(menuLayout);

    connect(btn_start, SIGNAL(clicked()), this, SLOT(start()));
    connect(btn_exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(btn_opiton, SIGNAL(clicked()), this, SLOT(optionShow()));
}

mainMenu::~mainMenu()
{

}

void mainMenu::start()
{
    qDebug() << "start widget";
    widget = new Widget();
    widget->game->config(option->getCfg());
    widget->show();
    this->hide();

    connect(widget, SIGNAL(rejected()), this, SLOT(deleteWidget()));
    connect(widget->game, SIGNAL(restart()), this, SLOT(restart()));
}

void mainMenu::deleteWidget()
{
    delete widget;
    this->show();
}

void mainMenu::restart()
{
    deleteWidget();
    start();
}

void mainMenu::optionShow()
{
    option->show();
}
