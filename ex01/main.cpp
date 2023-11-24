#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error("Wrong input"));
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}