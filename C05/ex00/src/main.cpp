#include "../incl/Bureaucrat.hpp"
#include <iostream>

int main(){
	try {
		Bureaucrat John("John", 14);
		Bureaucrat Melody("Melody", 1);
		Bureaucrat Sara("Sara", 150);
		// Bureaucrat Manuel("Manuel", 150);
		// Bureaucrat Alex("Pascal", -14);
		// Bureaucrat Alex("Alex", 151);
		// Bureaucrat Martin(Bureaucrat("Martin", 15));

		std::cout << John;
		std::cout << Melody;
		std::cout << Sara;
		Sara.increment(1);
		std::cout << Sara;
		// std::cout << Alex;
		// std::cout << Martin;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}