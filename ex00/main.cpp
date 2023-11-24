#include "BitcoinExchange.hpp"

// #include <string>

int main(int argc, char** argv)
{
	try
	{
		///TODO: qu exception@ sarqi, coz subjct example
		if (argc != 2)
			throw (std::runtime_error("Error: could not open file.")); 

		// strm.is_open();
		// strm.is_open();

		///TODO: vrode ban chi lini ete class ch haytararem u tupo map@ ogtagortsem che?

		///TODO: parsing code here

		
		
		BitcoinExchange b(argv[1]);	
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}