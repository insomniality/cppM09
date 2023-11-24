#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::deque<int> d;
		std::vector<int> v;
	public:
		void validator(char**);
	
		template<typename T>
		void sorter(char**, T&);
	
		template<typename T>
		void pmergeme(T&);

		template<typename T>
		void insertion_sort(T&);

		template<typename T>
		void binary_insert(T&, T&);
	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
};
