#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <cstdlib>

#define INPUT_DEFAULT_PATH "input.txt"
#define DATABASE_DAFEULT_PATH "data.csv"
#define LEAP_YEAR(x) (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))

class BitcoinExchange
{
	private:
		typedef std::map<std::string, double> cont;
		///TODO: partadir piti pirvate liner?
		std::map<std::string, double> database;
		void check_arg(const std::string& str);
		std::string trim(std::string to_trim);
		void openFile(const char *path);
		void openInpt(const char *path);
		void findValue(const std::string& date, const std::string& s);
		void validDate(std::string& str);
	public:
		BitcoinExchange();
		BitcoinExchange(const char *path);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange();
};