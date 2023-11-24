#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	openFile(DATABASE_DAFEULT_PATH);
	openInpt(INPUT_DEFAULT_PATH);
}

BitcoinExchange::BitcoinExchange(const char *input_path)
{
	openFile(DATABASE_DAFEULT_PATH);

	openInpt(input_path);
}

void BitcoinExchange::openFile(const char *path)
{
	std::string	key;

	std::string buff1;
	std::string	buff2;

	std::fstream inpt(path, std::ios_base::in);

	if (inpt.fail())
		throw std::runtime_error("Can't open file");

	std::getline(inpt, buff1);
	while (std::getline(inpt, buff1, ','))
	{
		std::getline(inpt, buff2);
		database.insert(std::make_pair(buff1, atof(buff2.c_str())));
	}

	cont::iterator end = database.begin();

	std::advance(end, 10);
}

void BitcoinExchange::validDate(std::string& str)
{
	unsigned int y;
	unsigned int m;
	unsigned int d;

	str = trim(str);

	if (str.empty())
		throw std::runtime_error("Bad input => ''");

	for (size_t i = 0; i < str.size(); i++)
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			throw (std::runtime_error("Error: bad input => " + str));
	if (std::count(str.begin(), str.end(), '-') != 2)
		throw (std::runtime_error("Error: bad input => " + str));

	if (*str.begin() == '-' || *(str.end() - 1) == '-')
		throw (std::runtime_error("Error: bad input => " + str));
	if(str.find("--") != std::string::npos)
		throw (std::runtime_error("Error: bad input => " + str));

	std::string a, b, c;

	a = str.substr(0, str.find_first_of('-'));
	b = str.substr(str.find_first_of('-') + 1, str.find_last_of('-') - str.find_first_of('-') - 1);
	c = str.substr(str.find_last_of('-') + 1);

	if (a.size() != 4 || b.size() != 2 || c.size() != 2)
		throw (std::runtime_error("Error: bad input => " + str));

	y = atoi(a.c_str());
	m = atoi(b.c_str());
	d = atoi(c.c_str());

	if (d < 1 || m < 1 || y < 2000 || y > 2025 || m > 12)
		throw (std::runtime_error("Error: bad input => " + str));
	if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31) 
		throw (std::runtime_error("Error: bad input => " + str));
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) 
		throw (std::runtime_error("Error: bad input => " + str));
	if(m == 2 && ((LEAP_YEAR(y) && d > 29) || (!LEAP_YEAR(y) && d > 28)))
		throw (std::runtime_error("Error: bad input => " + str));
}

std::string BitcoinExchange::trim(std::string to_trim)
{
	std::string ret;

	size_t i = 0;

	while (to_trim[i] && ::isspace(to_trim[i])) ++i;

	while (to_trim[i] && !isspace(to_trim[i])) ret.push_back(to_trim[i++]);

	return ret;
}

void BitcoinExchange::openInpt(const char *path)
{
	std::string	key;

	std::string buff1;
	std::string	buff2;

	std::fstream inpt(path, std::ios_base::in);

	if (inpt.fail())
		throw std::runtime_error("Can't open file");
	
	std::getline(inpt, buff1);

	std::string line;

	while (std::getline(inpt, line))
	{
		try
		{
			std::stringstream s(line);
			std::getline(s, buff1, '|');
			std::getline(s, buff2);
			if (buff1.empty() || buff2.empty())
				throw std::runtime_error("Error: Bad input?");
			validDate(buff1);
			check_arg(buff2);
			findValue(buff1, buff2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		// std::cout << it->second * atof(buff2.c_str()) << std::endl;
		
		// database;
		// database.insert(std::make_pair(buff1, atof(buff2.c_str())));
	}
}

void BitcoinExchange::findValue(const std::string& date, const std::string& s)
{
	cont::iterator it = database.begin();
	cont::iterator end = database.end();

	double val = atof(s.c_str());

	if (val < 0 || val > 1000)
		throw std::runtime_error("Number out of range => " + s);

	if (date < it->first)
		throw std::runtime_error("Date doesn't exit");

	std::advance(end, -2);

	for (; it != end; ++it)
	{
		cont::iterator next = it;
		++next;

		if (date >= it->first && date <= next->first)
		{
			break ;
		}
	}

	if (it == database.end())
	{
		std::cout << "a\n";
		--it;
	}

	std::cout << date << ": " << it->second * val << "\n";
}

void BitcoinExchange::check_arg(const std::string& old_str)
{
	std::string str = trim(old_str);

	size_t start = (str[0] == '+' || str[0] == '-' ? 1 : 0);
	size_t end = (str[str.size() - 1] == 'f' ? str.size() - 2 : str.size());

	if (str.empty() || str.find('.') != str.rfind('.'))
		throw std::runtime_error("Bad Input => '" + str + "'");

	for (; start < end; ++start)
	{
		if (str[start] != '.' && (str[start] < '0' || str[start] > '9'))
			throw std::runtime_error("Bad Input => '" + str + "'");
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this == &obj)
		return(*this);
	return(*this);
}

BitcoinExchange::~BitcoinExchange()
{

}