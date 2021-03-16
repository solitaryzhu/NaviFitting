#ifndef __SRC_NAVI_CLOTHOID_H__
#define __SRC_NAVI_CLOTHOID_H__

#include "NaviCurvePrimitive.h"
#include "Eigen/Core"

namespace fitting
{

class NaviClothoid : public NaviCurvePrimitive
{
public:
    NaviClothoid(
        const Eigen::Vector2d &startPos, 
        double startCurve,
        double endCurve,
        double startAngle,
        double length);

    virtual ~NaviClothoid();

    bool pos(Eigen::Vector2d &pos, double s);

    bool derivate(ParamDer &der, double s);

private:
    double _a;
    double _b;
    double _c;
    double _length;
    Eigen::Vector2d _startPos;
    Eigen::Vector2d _shift;

    double _scale;
    Eigen::Matrix2d _mat;
    const double PI;
};



}



#endif
