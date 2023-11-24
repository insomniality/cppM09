#include "PmergeMe.hpp"

void PmergeMe::validator(char** argv)
{
	for (size_t i = 1; argv[i] != NULL; i++)
		for (size_t j = 0; argv[i][j] != '\0'; j++)
			if(argv[i][j] < '0' || argv[i][j] > '9')
				throw (std::runtime_error("Wrong input"));
}

template<typename T>
void PmergeMe::sorter(char** argv, T& cont)
{
	///TODO: jamanak hashvel
	for (size_t i = 1; argv[i] != NULL; i++)
		for (size_t j = 0; argv[i][j] != '\0'; j++)
			cont.push_back(atoi(argv[i]));
}

template<typename T>
void PmergeMe::pmergeme(T& cont)
{
	T big;
	T smol;

	if (cont.size() == 1)
		return ;

	for (size_t i = 0; i < cont.size() - 1; i++)
	{
		if (i % 2 == 0)
		{
			if (cont[i] > cont[i + 1])
			{
				big.push_back(cont[i]);
				smol.push_back(cont[i + 1]);
			}
			else
			{
				big.push_back(cont[i + 1]);
				smol.push_back(cont[i]);
			}
		}
	}
	if (cont.size() % 2 == 1)
		smol.push_back(cont[cont.size() - 1]);

	pmergeme(big);
	binary_insert(big, smol);

	cont = big;
	// for (size_t i = 0; i < big.size(); i++)
	// {
	// 	std::cout << big[i] << " ";
	// }
	// std::cout << "\n";
	// for (size_t i = 0; i < smol.size(); i++)
	// {
	// 	std::cout << smol[i] << " ";
	// }
	// std::cout << "\n";
}

template<typename T>
void PmergeMe::binary_insert(T& big, T& smol)
{
	size_t start = 0;
	size_t end = 0;
	size_t next_pow = 2;
	size_t num = 2;

	if (smol.size() == 1)
	{
		big.insert(std::upper_bound(big.begin(), big.end(), smol[0]), smol[0]);
		return ;
	}

	bool a = false;

	for (; smol.size() != 0 ;)
	{
		end = start;
		start = start + num;
		num = pow(2, next_pow) - num;
		if (start >= smol.size())
		{
			start = smol.size();
			a = true;
		}
		for (size_t j = start - 1; ; j--)
		{
			big.insert(std::upper_bound(big.begin(), big.end(), smol[j]), smol[j]);
			if (j == end || j == SIZE_MAX)
				break ;
		}
		if (a)
			break ;
		++next_pow;
	}
}

//////////////////////////////////////////

PmergeMe::PmergeMe()
{
	
}

double	gettime(struct timeval start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((double)((now.tv_sec - start.tv_sec) * 1000)
		+ ((double)(now.tv_usec - start.tv_usec) / 1000)));
}

PmergeMe::PmergeMe(char **argv)
{
	validator(argv);

	struct timeval start;
	gettimeofday(&start, NULL);
	sorter(argv, v);
	std::cout << "Vector: ";

	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << "\n";
	pmergeme(v);
	std::cout << "Time needed for vector: " << gettime(start) << "\nSorted vector: ";
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << "\n";

	gettimeofday(&start, NULL);
	sorter(argv, d);
	std::cout << "Deque: ";
	for (size_t i = 0; i < d.size(); ++i)
	{
		std::cout << d[i] << " ";
	}
	std::cout << "\n";
	pmergeme(d);
	std::cout << "Time needed for deque: " << gettime(start) << "\nSorted Deque: ";
	for (size_t i = 0; i < d.size(); ++i)
	{
		std::cout << d[i] << " ";
	}
	std::cout << "\n";
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	d = obj.d;
	v = obj.v;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this == &obj)
		return (*this);
	d = obj.d;
	v = obj.v;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}