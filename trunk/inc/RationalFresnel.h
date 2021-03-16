#ifndef __SRC_RATIONAL_FRESNEL_H__
#define __SRC_RATIONAL_FRESNEL_H__

#include "Eigen/Core"

using namespace Eigen;

namespace navi
{

class RationalFresnel
{
public:
    RationalFresnel();
    virtual ~RationalFresnel();

    Vector2d operator()(double a, double b, double s);

private:
    const double PI;
};

}
#endif