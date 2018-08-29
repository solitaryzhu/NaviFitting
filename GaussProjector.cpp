#include "GaussProjector.h"
#include "proj4/include/proj_api.h"
#include <stdio.h>

namespace navi
{

GaussProjector::GaussProjector()
{

}

GaussProjector::~GaussProjector()
{

}

bool GaussProjector::forwardProject(double &x, double &y, double lon, double lat, int projNo)
{
    char gauss[256] = {0};
    sprintf(gauss, "+proj=utm +ellps=WGS84 +zone=%dn +x_0=500000.0", projNo);
    projPJ gaussPrj = NULL;
    if (!(gaussPrj = pj_init_plus(gauss)))
    {
        return false;
    }

    projXY xy;
    projLP lonlat;
    lonlat.u = lon * DEG_TO_RAD;
    lonlat.v = lat * DEG_TO_RAD;
    xy = pj_fwd(lonlat, gaussPrj);
    x = xy.u;
    y = xy.v;
    pj_free(gaussPrj);

    return true;
}

bool GaussProjector::inverseProject(double &lon, double &lat, double x, double y, int projNo)
{
    char gauss[256] = {0};
    sprintf(gauss, "+proj=utm +ellps=WGS84 +zone=%dn +x_0=500000.0", projNo);
    projPJ gaussPrj = NULL;
    if (!(gaussPrj = pj_init_plus(gauss)))
    {
        return false;
    }

    projUV xy;
    projUV lonlat;

    xy.u = x;
    xy.v = y;

    lonlat = pj_inv(xy, gaussPrj);

    lon = lonlat.u / DEG_TO_RAD;
    lat = lonlat.v / DEG_TO_RAD;

    return true;
}

 int GaussProjector::getProjectNo(double longitude)
 {
    return int(longitude) / 6 + 31;
 }


}