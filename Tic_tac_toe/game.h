#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "QMessageBox"
#include "QSignalMapper"
#include "QString"
#include "QPushButton"
#include "QDebug"
#include "configurationfile.h"
#include "enemy.h"
#include "mark.h"

class Game : public QObject, public _Mark//, public ConfigurationFile
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    ~Game();

    QSignalMapper *getSMapper() const;    
    void setButtons(QPushButton **buttons);
    void config(ConfigurationFile value);

private:
    QSignalMapper *SMapper;
    QPushButton *m_buttons[3][3];
    Mark field[3][3];
    Mark nextMark;
    Mark markEnemy;
    int countMoves = 0;
    void message(Mark mark);
    bool check();
    _Enemy _enemy;
    ConfigurationFile cfg;

signals:
    virtual void closeGame();
    virtual void restart();
public slots:
    void pressButton(QString str);
};

#endif // GAME_H
