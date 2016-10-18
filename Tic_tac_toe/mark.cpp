#include "mark.h"

_Mark::_Mark()
{

}

_Mark::Mark _Mark::swapMark(_Mark::Mark mark)
{
    switch(mark){
        case Mark::X:
            return Mark::O;
        case Mark::O:
            return Mark::X;
        default:
            return Mark::N;
    }
}

QString _Mark::getMark(_Mark::Mark mark)
{
    switch(mark){
        case Mark::X:
            return "X";
        case Mark::O:
            return "O";
    default:
        return "N";
    }
}
