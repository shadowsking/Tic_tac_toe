#ifndef CONFIGURATIONFILE_H
#define CONFIGURATIONFILE_H
#include "mark.h"
#include "enemy.h"
#include "QDebug"

class ConfigurationFile: public _Mark
{
public:
    explicit ConfigurationFile();
    enum class Enemy{Player, Computer};

    Enemy getEnemy();
    void setEnemy(Enemy value);

    Mark getMarkPlayer();
    void setMarkPlayer(Mark value);
private:
    Enemy enemy = Enemy::Player;
    Mark markPlayer = Mark::X;
};

#endif // CONFIGURATIONFILE_H
