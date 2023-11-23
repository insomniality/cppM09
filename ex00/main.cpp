#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	try
	{
		///TODO: qu exception@ sarqi
		if (argc != 2)
			throw (std::exception()); 

		std::fstream data;
		std::fstream inpt;
		
		data.open("./data.csv", std::ios_base::in);
		// strm.is_open();
		inpt.open(argv[1], std::ios_base::in);
		// strm.is_open();


		inpt.close();
		// strm.is_open();
		data.close();
		// strm.is_open();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}