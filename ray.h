#ifndef _RAY_H_
#define _RAY_H_

#include "vec3d.h"

class ray {
public:

    //Init
    ray(){}
    ray(const point3& origin, const vec3d& direction) : orig{origin}, dir(direction) {}

    point3 origin() const {return orig;}
    vec3d direction() const {return dir;}
    
    void set_origin(point3 origin) {orig = origin;}
    void set_direction(vec3d direction) {dir = direction;}

private:
    point3 orig;
    vec3d dir;
};


#endif /*_RAY_H_*/