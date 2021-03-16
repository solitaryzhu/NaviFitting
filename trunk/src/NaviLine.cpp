#include "NaviLine.h"

namespace navi
{

NaviLine::NaviLine(const Eigen::Vector2d &startPos, double angle, double length)
{
    _startPos = startPos;
    _c        = angle;
    _length   = length;
}

NaviLine::~NaviLine()
{

}

bool NaviLine::pos(Eigen::Vector2d &pos, double s)
{
    if (s < .0 || s > _length)
        return false;

    double retX(.0);
    double retY(.0);

    retX = _startPos[0] + cos(_c) * s;
    retY = _startPos[1] + sin(_c) * s;

    pos[0] = retX;
    pos[1] = retY;

    return true;
}

bool NaviLine::derivate(ParamDer &der, double s)
{
    if (s < .0 || s > _length)
        return false;

    /* X(s) = x0 + cos(c) * s
     * Y(s) = y0 + sin(c) * s
     **/
    der = ParamDer::Zero(2, 6);
    der(0, X)      = 1;
    der(1, Y)      = 1;
    der(0, ANGLE)  = -sin(_c) * s;
    der(1, ANGLE)  =  cos(_c) * s;
    der(0, LENGTH) = cos(_c);
    der(1, LENGTH) = sin(_c);

    return true;
}

}