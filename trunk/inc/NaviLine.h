#ifndef __SRC_NAVI_LINE_H__
#define __SRC_NAVI_LINE_H__

#include "NaviCurvePrimitive.h"
#include "Eigen/Core"

namespace fitting
{

class NaviLine : public NaviCurvePrimitive
{
public:
    NaviLine(const Eigen::Vector2d &startPos, double angle, double length);
    virtual ~NaviLine();

    bool pos(Eigen::Vector2d &pos, double s);
    bool derivate(ParamDer &der, double s);

private:
    double _c;
    double _length;
    Eigen::Vector2d _startPos;
};


}


#endif
