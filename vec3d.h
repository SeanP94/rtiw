#ifndef _VEC3D_H_
#define _VEC3D_H_

#include <cmath>
#include <iostream>

class vec3d {
public:
    //Default init
    vec3d() : loc{0,0,0} {}
    //Init vector
    vec3d(const double &loc1,const double &loc2,const double &loc3) : loc{loc1, loc2, loc3} {}

    //Vec3D getters.
    double x() const {return loc[0];}
    double y() const {return loc[1];}
    double z() const {return loc[2];}

    //Opp overloaders
    //Returns negative version of vec3d
    vec3d operator-() const {return vec3d(-loc[0],-loc[1],-loc[2]);}
    double operator[](int i) const {return loc[i];}
    double & operator[](int i) {return loc[i];}

    vec3d& operator += (const vec3d &v) {
        for( int i = 0; i < *(&loc + 1) - loc; i++ )
            loc[i] += v[i];
        return *this;
    }

    vec3d& operator *= (const double v) {
        for( int i = 0; i < *(&loc + 1) - loc; i++ )
            loc[i] *= v;
        return *this;
    }

    vec3d& operator /=(const double v) { return *this *= 1/v; }

    double length() const { return std::sqrt(length_squared());}
    
    double length_squared() const {
        return loc[0]*loc[0] + loc[1]*loc[1] + loc[2]*loc[2];
    }

private:
    //Vector Location.
    double loc[3];
};


#endif /*_VEC3D_H_*/