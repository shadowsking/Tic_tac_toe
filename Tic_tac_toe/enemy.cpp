#include "enemy.h"
#include "QDebug"
_Enemy::_Enemy()
{

}


QString _Enemy::CompMove(Mark *field)
{/*
    if (n==0) return "11";
    for(int i=0; i<3; i++){
        bool findOneNullMark = false;
        bool findTwoMark = false;
        Mark temp;
        QString coord;
        for(int j=0; j<3; j++){
            if (j == 0){
                if (field[i*3+j]!=Mark::N) temp = field[i*3+j];
                else {
                    findOneNullMark = true;
                    coord = QString::number(i)+QString::number(j);
                }
            }
            else {
                if (field[i*3+j]==Mark::N && !findOneNullMark) {
                    findOneNullMark = true;
                    coord = QString::number(i)+QString::number(j);
                }else if (field[i*3+j]==Mark::N && findOneNullMark) {
                    findOneNullMark = false;
                    break;
                }
                if (field[i*3+j]!=temp) break;
                else findTwoMark = false;
            }
        }
        if (findTwoMark && findOneNullMark) return coord;
    }
    return QString::number(rand()%2)+QString::number(rand()%2);*/
    /*
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            if(field[i*3+j]==Mark::N) return
        }

    }*/

    while(true){
        int i = rand()%3;
        int j = rand()%3;
        if(field[i*3+j]==Mark::N) return QString::number(i)+QString::number(j);
    }
}
