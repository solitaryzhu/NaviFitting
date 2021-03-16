#include "NaviClothoid.h"
#include <cmath>
#include "RationalFresnel.h"

using namespace std;

namespace fitting
{

NaviClothoid::NaviClothoid(
    const Eigen::Vector2d &startPos, 
    double startCurve, 
    double endCurve, 
    double startAngle, 
    double length) : PI(3.14159265359)
{
    _startPos = startPos;
    _a        = (endCurve - startCurve) / (2*length);
    _b        = startCurve;
    _c        = startAngle;
    _length   = length;

    _scale = pow(abs(PI/(2*_a)), 0.5);
    if (_a > 0)
    {
        double theta = _c - pow(_b, 2) / (4*abs(_a));
        _mat << cos(theta), -sin(theta),
                sin(theta),  cos(theta);
    }
    else
    {
        double theta = _c + pow(_b, 2) / (4*abs(_a));
        _mat << -cos(theta), -sin(theta),
                -sin(theta),  cos(theta);
    }

    RationalFresnel rationalFresnel;
    Eigen::Vector2d begPos = rationalFresnel(_a, _b, .0);
    begPos = _scale * _mat * begPos;
    _shift =  _startPos - begPos;
}

NaviClothoid::~NaviClothoid()
{

}

bool NaviClothoid::pos(Eigen::Vector2d &pos, double s)
{
    if (s < 0 || s > _length)
        return false;

    RationalFresnel rationalFresnel;
    pos = rationalFresnel(_a, _b, s);

    pos = _shift + _scale * _mat * pos;

    return true;
}

bool NaviClothoid::derivate(ParamDer &der, double s)
{
    if (s < 0 || s > _length)
        return false;

    Eigen::Vector2d position;
    pos(position, s);
    Eigen::Vector2d diff = position - _startPos;

    double theta(.0);
    if (_a > 0)
        theta = _c - pow(_b, 2) / (4*abs(_a));
    else
        theta = _c + pow(_b, 2) / (4*abs(_a));

    der = ParamDer::Zero(2, 6);
    der(0, X) = 1;
    der(1, Y) = 1;
    der(0, ANGLE) = -diff[1];
    der(1, ANGLE) =  diff[0];
    der(0, LENGTH) = cos(theta);
    der(1, LENGTH) = sin(theta);

    return true;
}

}
