#ifndef __SRC_NAVI_ARC_H__
#define __SRC_NAVI_ARC_H__

#include "NaviCurvePrimitive.h"
#include "Eigen/Core"

namespace fitting
{

class NaviArc : public NaviCurvePrimitive
{
public:
    NaviArc(
        const Eigen::Vector2d &startPos,
        double startAngle,
        double length,
        double curvature);
    virtual ~NaviArc();

    bool pos(Eigen::Vector2d &pos, double s);
    bool derivate(ParamDer &der, double s);

private:
    double _b;
    double _c;
    double _length;
    Eigen::Vector2d _startPos;

};


}


#endif
