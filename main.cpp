#include <iostream>


int main() {
	//Set size of img
	const int img_width = 256;
	const int img_height = 256;
	//Setting P3 are set to this standard:
	//ASCII 3 columns, 2 rows.
	std::cout << "P3\n" << img_width <<  ' ' << img_height << "\n255\n";
	
	//Loop to create the image
	for (int i = img_height-1; i >= 0; --i) {
		//Create a Progress indicator.
		std::cerr << "\rScalines remaining: " << i << ' ' << std::flush;

		for (int j = 0; j < img_width; ++j) {
			auto r = double(j) / (img_width -1);
			auto g = double(i) / (img_height-1);			
			auto b = 0.25;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << std::endl;	
		}
	}
	std::cerr << "\nFile complete.\n";
}
