#ifndef __SRC_CENTER_OF_MASS_CALCULATOR_H__
#define __SRC_CENTER_OF_MASS_CALCULATOR_H__

#include <vector>
#include "Eigen/Core"
#include "Eigen/StdVector"

namespace fitting
{

class CenterofMassCalculator
{
public:
    CenterofMassCalculator();
    virtual ~CenterofMassCalculator();

    void calcClothoid(
        Eigen::Vector2d &ret,
        const Eigen::Vector2d &beginPos, 
        double a, 
        double b, 
        double c, 
        double length);

    void calcClothoid(Eigen::Vector2d &ret, const std::vector<Eigen::Vector2d> &pts);
};


}


#endif
