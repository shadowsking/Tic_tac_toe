#include "widget.h"
#include "QDebug"
#include "QString"

Widget::Widget(QWidget *parent): QDialog(parent)
{
    setFixedSize(300, 300);
    setWindowTitle("Tic Tac Toe");

    game = new Game();

    Glayout = new QGridLayout();
    Glayout->setSpacing(0);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            Glayout->addWidget(btn[i][j] = new QPushButton(""), i, j);
            btn[i][j]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            connect(btn[i][j], SIGNAL(clicked()), game->getSMapper(), SLOT(map()));
            //game->getSMapper()->setMapping(btn[i][j], i*3+j);
            game->getSMapper()->setMapping(btn[i][j], QString::number(i)+QString::number(j));

        }
    }
    game->setButtons(&btn[0][0]);

    this->setLayout(Glayout);

    connect(game,SIGNAL(closeGame()),this, SLOT(reject()));
}

Widget::~Widget()
{

}
