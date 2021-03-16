#ifndef __SRC_DEFS_H__
#define __SRC_DEFS_H__

#include <cmath>
#include "Eigen/Core"

using namespace std;

namespace fitting
{

enum CURVE_TYPE
{
    LINE = 0,
    ARC,
    CLOTHOID
};

enum PARAMETER_TYPE
{
    X = 0,
    Y,
    ANGLE,
    LENGTH,
    CURVATURE,
    DCURVATURE
};

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::AutoAlign, 2, 6> ParamDer;

template <typename T> class Point2D
{
public:
    Point2D(T x, T y):_x(x), _y(y)
    {

    }

    virtual ~Point2D()
    {

    }

    T getX() const { return _x; }
    T getY() const { return _y; }

    void setX(T x) { _x = x; }
    void setY(T y) { _y = y; }

    T norm() { return pow(_x*_x + _y*_y, 0.5); }

private:
    T _x;
    T _y;
};

}

#endif
