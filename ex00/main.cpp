#include "BitcoinExchange.hpp"

// #include <string>

int main(int argc, char** argv)
{
	try
	{
		///TODO: qu exception@ sarqi, coz subjct example
		if (argc != 2)
			throw (std::exception()); 

		std::fstream data;
		std::fstream inpt;

		data.open("./data.csv", std::ios_base::in);
		// strm.is_open();
		inpt.open(argv[1], std::ios_base::in);
		// strm.is_open();

		///TODO: vrode ban chi lini ete class ch haytararem u tupo map@ ogtagortsem che?

		///TODO: parsing code here

		BitcoinExchange dbase;
		///
		{
			std::string	key;
			float 		value;
			char 		*buff1;
			char 		*buff2;
			// for (std::map<std::string, float>::iterator it = dbase.mp.begin(); it != dbase.mp.end(); ++it)
			for (size_t i = 0; i < std::count(std::istreambuf_iterator<char>(inpt),std::istreambuf_iterator<char>(), '\n'); i++)
			{

				inpt.getline(buff1, '|');
				inpt.getline(buff2, '\n');
				
				dbase.mp.insert(std::pair<std::string, float>(static_cast<std::string>(buff1), \
				static_cast<std::string>(buff2).find_first_of('.') != std::string::npos ? \
				atoi(buff2) : static_cast<float>(atof(buff2))));
			}
		}
		
		for (std::map<std::string, float>::iterator it = dbase.mp.begin(); it != dbase.mp.end(); ++it)
		{

		}

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