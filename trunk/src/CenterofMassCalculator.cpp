#include "CenterofMassCalculator.h"
#include <cmath>
#include "RationalFresnel.h"

using namespace std;

namespace fitting
{

CenterofMassCalculator::CenterofMassCalculator()
{

}

CenterofMassCalculator::~CenterofMassCalculator()
{

}

void CenterofMassCalculator::calcClothoid(
    Eigen::Vector2d &ret, 
    const Eigen::Vector2d &beginPos, 
    double a, 
    double b, 
    double c, 
    double length)
{
    RationalFresnel rationalFresnel;
    Eigen::Vector2d p1 = rationalFresnel(a, b, 0);
    Eigen::Vector2d p2 = rationalFresnel(a, b, length);

    double x = (sin(c) - sin(c + length*(b + a*length))) / (2*a);
    x += ((2*a*length + b)*p2[0] - b*p1[0]) / (2*a);
    x /= length;

    double y = (cos(c + length*(b + a*length)) - cos(c)) / (2*a);
    y += ((2*a*length + b)*p2[1] - b*p1[1]) / (2*a);
    y /= length;

    ret[0] = x + beginPos[0];
    ret[1] = y + beginPos[1];
}

void CenterofMassCalculator::calcClothoid(
    Eigen::Vector2d &ret,
    const std::vector<Eigen::Vector2d> &pts)
{
    if (pts.size() < 2) { return; }

    Eigen::Vector2d centerOfMass(.0, .0);
    double length(.0);

    size_t size = pts.size();
    for (size_t i=1; i<size; ++i)
    {
        Eigen::Vector2d vtr = pts.at(i) - pts.at(i-1);
        Eigen::Vector2d mas = pts.at(i) + pts.at(i-1);

        double norm = vtr.norm();
        centerOfMass += norm*0.5*mas;

        length += norm;
    }

    ret = centerOfMass / length;
}

}
