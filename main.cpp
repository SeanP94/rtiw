#include <iostream>
#include "vec3d.h"
#include "color.h"
#include "ray.h"

//This creates a simple ray casted gradient background.
color ray_background_gradient(const ray& r) {
	vec3d unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	return (1.0-t)*color(1.0,1.0,1.0) + t*color(0.5,0.7,1.0);
}

int main() {
	auto ray_fun = ray_background_gradient;
	//Image data:
	const auto aspect_ratio = 16.0 / 9.0;
	const int img_width = 400;
	const int img_height = static_cast<int>(img_width / aspect_ratio);

	//Camera data:
	const auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	//Origin of camera
	auto origin = point3(0,0,0);
	auto horiz  = vec3d(viewport_width,0,0);
	auto vert   = vec3d(0,viewport_height,0);
	auto lower_left_corner = origin - horiz/2 - vert/2 - vec3d(0,0,focal_length);

	//Rendering:
	std::cout << "P3\n" << img_width <<  ' ' << img_height << "\n255\n";
	
	//Loop to create the image
	for (int i = img_height-1; i >= 0; --i) {
		//Create a Progress indicator.
		std::cerr << "\rScalines remaining: " << i << ' ' << std::flush;
		for (int j = 0; j < img_width; ++j) {
			auto u = double(j) / (img_width-1);
			auto v = double(i) / (img_height-1);
			ray r(origin, (lower_left_corner + u*horiz + v*vert - origin));
			color pixel_color = ray_fun(r);
			write_color(std::cout, pixel_color);
		}
	}
	std::cerr << "\nFile complete.\n";
}
