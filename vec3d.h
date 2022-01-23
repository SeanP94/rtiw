/*
Code based on https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage
*/

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

    friend std::ostream& operator<<(std::ostream &, const vec3d &) ;
    friend vec3d operator+(const vec3d &, const vec3d &);
    friend vec3d operator-(const vec3d &, const vec3d &);
    friend vec3d operator*(const double&, const vec3d &);
    friend double dot(const vec3d &, const vec3d &);
    friend vec3d cross(const vec3d &, const vec3d &);
};

//Type Alliases
using point3 = vec3d;
using color = vec3d;

inline std::ostream& operator<<(std::ostream &out, const vec3d &v) {
    return out << v.loc[0] << ' ' << v.loc[1] << ' ' << v.loc[2];
}

inline vec3d operator+(const vec3d &u, const vec3d &v) {
    return vec3d(u.loc[0]+v.loc[0], u.loc[1]+v.loc[1], u.loc[2]+v.loc[2]);
}

inline vec3d operator-(const vec3d &u, const vec3d &v) {
    return vec3d(u.loc[0]-v.loc[0], u.loc[1]-v.loc[1], u.loc[2]-v.loc[2]);
}

inline vec3d operator*(const double& u, const vec3d &v) {
    return vec3d(u * v.loc[0], u * v.loc[1], u * v.loc[2]);
}



inline double dot(const vec3d &u, const vec3d &v) {
    return u.loc[0] * v.loc[0]
         + u.loc[1] * v.loc[1]
         + u.loc[2] * v.loc[2];
}

inline vec3d cross(const vec3d &u, const vec3d &v) {
    return vec3d(u.loc[1] * v.loc[2] - u.loc[2] * v.loc[1],
                u.loc[2] * v.loc[0] - u.loc[0] * v.loc[2],
                u.loc[0] * v.loc[1] - u.loc[1] * v.loc[0]);
}


inline vec3d operator*(const vec3d &u, const vec3d &v){ 
    return u * v; //Doesnt need to be a friend.
}

inline vec3d operator/(vec3d v, const double &u) {
    return (1/u) * v; //Doesnt need to be a friend.
}

inline vec3d unit_vector(vec3d v) {
    return v / v.length(); //Doesn't need to be a friend.
}

#endif /*_VEC3D_H_*/