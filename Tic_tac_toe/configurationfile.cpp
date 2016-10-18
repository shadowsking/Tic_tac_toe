#include "configurationfile.h"

ConfigurationFile::ConfigurationFile()
{

}

ConfigurationFile::Enemy ConfigurationFile::getEnemy()
{
    return enemy;
}

void ConfigurationFile::setEnemy(Enemy value)
{
   enemy = value;
}

_Mark::Mark ConfigurationFile::getMarkPlayer()
{
    return markPlayer;
}

void ConfigurationFile::setMarkPlayer(Mark value)
{
    markPlayer = value;
}
