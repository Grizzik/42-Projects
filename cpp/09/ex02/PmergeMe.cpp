#include "PmergeMe.hpp"

#include <iostream>
#include <ctime>
#include <climits> 

std::vector<int> generateJacobsthalIndices(int n)
{
	std::vector<int> jacobsthal;
	if (n <= 0)
		return jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (true)
	{
		int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >= n) break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

static void mergeInsertSortVector(std::vector<unsigned int> &vec, int left, int right) //tab dy
{
	if (right - left < 1)
		return;

	std::vector<int> jacobsthal = generateJacobsthalIndices(right - left + 1);

	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<unsigned int> sortedList;
	bool hasSingle = ((right - left + 1) % 2 != 0);
	unsigned int singleElement = 0;
//1) Paire
	for (int i = left; i + 1 <= right; i += 2)
	{
		if (vec[i] > vec[i + 1]) 
			std::swap(vec[i], vec[i + 1]);
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}

	if (hasSingle)
		singleElement = vec[right];

//2) Insertion premier groupe
	for (size_t i = 0; i < pairs.size(); i++)
	{
		sortedList.push_back(pairs[i].first);
	}
	std::stable_sort(sortedList.begin(), sortedList.end());  // C++98-compatible

//3) Insertion nb sup
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::vector<unsigned int>::iterator pos = sortedList.begin();
		while (pos != sortedList.end() && *pos < pairs[i].second)
			++pos;
		sortedList.insert(pos, pairs[i].second);
	}

//4) Insertion last solo
	if (hasSingle)
	{
		std::vector<unsigned int>::iterator pos = sortedList.begin();
		while (pos != sortedList.end() && *pos < singleElement)
			++pos;
		sortedList.insert(pos, singleElement);
	}

//Copie dans vec
	std::copy(sortedList.begin(), sortedList.end(), vec.begin() + left);
}


static std::list<unsigned int> mergeInsertSortList(std::list<unsigned int> &lst) //lst d chaine
{
	if (lst.size() < 2)
		return lst;

	std::vector<int> jacobsthal = generateJacobsthalIndices(lst.size());

	std::list<std::pair<unsigned int, unsigned int> > pairs;
	std::list<unsigned int> sortedList;
	bool hasSingle = (lst.size() % 2 != 0);
	unsigned int singleElement = 0;

	std::list<unsigned int>::iterator it = lst.begin();
	//1) Paire
	while (it != lst.end())
	{
		unsigned int first = *it++;
		if (it != lst.end())
		{
			unsigned int second = *it++;
			if (first > second) std::swap(first, second);
				pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			singleElement = first;
			hasSingle = true;
		}
	}

//2) Insertion premier groupe
	for (std::list<std::pair<unsigned int, unsigned int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
	{
		sortedList.push_back(p->first);
	}
	sortedList.sort();

//3) Insertion nb sup manuelle
	for (std::list<std::pair<unsigned int, unsigned int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
	{
		std::list<unsigned int>::iterator pos = sortedList.begin();
		while (pos != sortedList.end() && *pos < p->second)
			++pos;
		sortedList.insert(pos, p->second);
	}

//4) Insertion last solo
	if (hasSingle)
	{
		std::list<unsigned int>::iterator pos = sortedList.begin();
		while (pos != sortedList.end() && *pos < singleElement)
			++pos;
		sortedList.insert(pos, singleElement);
	}
	return sortedList;
}


void PMM::sort()
{
	std::clock_t start;

	start = std::clock();
	mergeInsertSortVector(vec, 0, vec.size() - 1);
	vecTime = (std::clock() - start) * 1000.0 / CLOCKS_PER_SEC;

	start = std::clock();
	lst = mergeInsertSortList(lst);
	lstTime = (std::clock() - start) * 1000.0 / CLOCKS_PER_SEC;
}
