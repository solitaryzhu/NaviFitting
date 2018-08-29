#ifndef __SRC_NAVI_CURVE_PRIMITIVE_H__
#define __SRC_NAVI_CURVE_PRIMITIVE_H__

#include "defs.h"
#include "Eigen/Core"

namespace navi
{

class NaviCurvePrimitive
{
public:
    NaviCurvePrimitive();
    virtual ~NaviCurvePrimitive();

    virtual bool pos(Eigen::Vector2d &pos, double s) = 0;

    virtual bool derivate(ParamDer &der, double s) = 0;
};



}



#endif