#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
	public:
		///TODO: partadir piti pirvate liner?
		std::map<std::string, float> mp;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange();
};