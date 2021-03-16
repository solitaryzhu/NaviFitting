#ifndef __SRC_GAUSS_PROJECTOR_H__
#define __SRC_GAUSS_PROJECTOR_H__


namespace fitting
{

class GaussProjector
{
public:
    GaussProjector();
    virtual ~GaussProjector();

    bool forwardProject(double &x, double &y, double lon, double lat, int projNo);
    bool inverseProject(double &lon, double &lat, double x, double y, int projNo);
    int getProjectNo(double longitude);
};


}


#endif
