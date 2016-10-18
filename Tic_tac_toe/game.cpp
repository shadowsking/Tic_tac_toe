#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    for (int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            field[i][j] = Mark::N;
    nextMark = Mark::X;
    SMapper = new QSignalMapper(this);
    connect(SMapper, SIGNAL(mapped(QString)), this, SLOT(pressButton(QString)));
}

Game::~Game()
{
}

QSignalMapper *Game::getSMapper() const
{
    return SMapper;
}

void Game::setButtons(QPushButton **buttons)
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m_buttons[i][j] = buttons[i*3+j];
        }
    }
}

void Game::config(ConfigurationFile value)
{
    cfg = value;
    if (cfg.getEnemy()==cfg.Enemy::Computer){
        if (cfg.getMarkPlayer()==Mark::O) markEnemy=Mark::X;
        else markEnemy=Mark::O;
    }
    if (cfg.getMarkPlayer()==Mark::O && cfg.getEnemy()==cfg.Enemy::Computer) pressButton(_enemy.CompMove(&field[0][0]));
}

void Game::pressButton(QString str)
{
    int i = QString(str[0]).toInt();
    int j = QString(str[1]).toInt();


    if(field[i][j] != Mark::N){
        return;
    }

    if (field[i][j]!=nextMark){
        field[i][j] = nextMark;
        m_buttons[i][j]->setText(getMark(nextMark));
        if (countMoves>=3){
            if(check()){
                message(nextMark);
                return;
            } else if (countMoves==8){
                message(Mark::N);
            }
        }
        nextMark = swapMark(nextMark);
    }

    if (nextMark==markEnemy && countMoves!=8) pressButton(_enemy.CompMove(&field[0][0]));
    ++countMoves;
}

void Game::message(Mark mark)
{
    QString str;
    if(mark!=Mark::N){
        str="Победитель : " + getMark(mark) + " !!! ";
    }else str = "Ничья !!! ";
    int result = QMessageBox::information(0,"Игра окончена ", str + "Хотите повторить?",
         QMessageBox::Yes | QMessageBox::Default,
             QMessageBox::No | QMessageBox::Escape);
    switch (result) {
        case QMessageBox::Yes:
            restart();
        break;
        case QMessageBox::No:
            closeGame();
        break;
    }
}


bool Game::check()
{
    for(int i=0; i<3; ++i){
            if((field[0][i]!=Mark::N && field[1][i]!=Mark::N && field[2][i]!=Mark::N)
                &&(field[0][i]==field[1][i] && field[1][i] == field[2][i])){
                return true;
            }
            else if((field[i][0]!=Mark::N && field[i][1]!=Mark::N && field[i][2]!=Mark::N)
                &&(field[i][0]==field[i][1] && field[i][1] == field[i][2])){
                return true;
            }
    }

    if ((field[0][0]!=Mark::N && field[1][1]!=Mark::N && field[2][2]!=Mark::N)
          &&(field[0][0] == field[1][1] && field[0][0]== field[2][2])){
        return true;
    }
    if ((field[0][2]!=Mark::N && field[1][1]!=Mark::N && field[2][0]!=Mark::N)
        &&(field[0][2] == field[1][1] && field[0][2]== field[2][0])){
        return true;
    }
    return false;

}



