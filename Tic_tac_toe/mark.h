#ifndef MARK_H
#define MARK_H
#include "QString"

class _Mark
{
public:
    _Mark();
    enum class Mark{X, O, N};

    Mark swapMark(Mark mark);
    QString getMark(Mark mark);

};

#endif // MARK_H
