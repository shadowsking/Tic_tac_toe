#ifndef _ENEMY_H
#define _ENEMY_H
#include "mark.h"

class _Enemy: public _Mark
{
public:
    _Enemy();
    QString CompMove(Mark *field);
};

#endif // _ENEMY_H
