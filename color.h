#ifndef _COLOR_H_
#define _COLOR_H_

#include "vec3d.h"
#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
    //Write to out the translated [0,255] values to each of the color components.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif /*_COLOR_H_*/