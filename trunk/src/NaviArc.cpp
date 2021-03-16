#include "NaviArc.h"
#include <cmath>

using namespace std;

namespace fitting
{

NaviArc::NaviArc(const Eigen::Vector2d &startPos, double startAngle, double length, double curvature)
{
    _startPos = startPos;
    _c        = startAngle;
    _b        = curvature;
    _length   = length;
}

NaviArc::~NaviArc()
{

}

bool NaviArc::pos(Eigen::Vector2d &pos, double s)
{
    if (s < 0 || s > _length)
        return false;

    double retX(.0);
    double retY(.0);

    double theta = _b * s + _c;
    retX = _startPos[0] + (sin(theta) - sin(_c))/_b;
    retY = _startPos[1] + (cos(_c) - cos(theta))/_b;

    pos[0] = retX;
    pos[1] = retY;

    return true;
}

bool NaviArc::derivate(ParamDer &der, double s)
{
    if (s < 0 || s > _length)
        return false;

    /* X(s) = x0 + sin(b * s + c) / b ¨C sin(c) / b;
       Y(s) = y0 ¨C cos(b * s + c) / b + cos(c) / b;
     **/
    der = ParamDer::Zero(2, 6);
    double theta = _b * s + _c;
    double sinDiff = sin(theta) - sin(_c);
    double cosDiff = cos(theta) - cos(_c);

    der(0, X)          =  sinDiff / _b;
    der(1, Y)          = -cosDiff / _b;
    der(0, ANGLE)      =  cosDiff / _b;
    der(1, ANGLE)      =  sinDiff / _b;
    der(0, LENGTH)     =  cos(theta);
    der(1, LENGTH)     =  sin(theta);
    der(0, CURVATURE)  =  cos(theta) * s / _b - sinDiff / _b / _b;
    der(1, CURVATURE)  =  sin(theta) * s / _b + cosDiff / _b / _b;
    der(0, DCURVATURE) = -sinDiff / _b / _b;
    der(1, DCURVATURE) =  cosDiff / _b / _b;

    return true;
}
}
