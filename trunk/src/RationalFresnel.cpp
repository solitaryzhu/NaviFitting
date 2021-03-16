#include "RationalFresnel.h"
#include <cmath>

using namespace std;

namespace navi
{

RationalFresnel::RationalFresnel()
    : PI(3.14159265359)
{
}

RationalFresnel::~RationalFresnel()
{
}

Eigen::Vector2d RationalFresnel::operator()(double a, double b, double s)
{
    Vector2d ret;

    double factor = pow(2*abs(a)*PI, 0.5);
    double ot = (b + 2*a*s) / factor;
    double t = abs(ot);

    double rt = ((((0.0433995*t + 0.1339259)*t + 0.3460509)*t + 0.6460117)*t + 0.7769507)*t + 1;
    rt /= ((((((0.13634704*t + 0.4205217)*t + 1.0917325)*t) + 1.9840524)*t + 2.7196741)*t + 2.5129806)*t + pow(2, 0.5);

    double at = ((((0.0241212*t + 0.068324)*t) + 0.2363641)*t + 0.1945161)*t + 1;
    at /= ((((((0.118247*t + 0.356681)*t) + 0.978113)*t + 1.875721)*t + 2.7570246)*t + 2.9355041)*t +2;

    double ct = 0.5 - rt*sin(0.5*PI*(at - pow(t, 2)));
    double st = 0.5 - rt*cos(0.5*PI*(at - pow(t, 2)));

    if (ot < 0)
    {
        ct = -ct;
        st = -st;
    }

    ret[0] = ct;
    ret[1] = st;

    return ret;
}

}