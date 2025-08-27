#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <set>

class FileException : public std::exception
{
private:
	std::string message;
public:
	FileException(const char* msg) : message(msg) {}
	~FileException() throw() {}
	virtual const char* what() const throw() { return message.c_str(); }
};

class PMM
{
private:
	std::vector<unsigned int> vec;
	clock_t vecTime;
	std::vector<unsigned int> tempVec;
	clock_t tempVecTime;
	std::list<unsigned int> lst;
	clock_t lstTime;

public:
	PMM() {}
	~PMM() {}
	PMM(PMM const& p) { *this = p; }
	PMM& operator=(PMM const& p)
	{
		if (this != &p)
		{
			vec = p.vec;
			lst = p.lst;
		}
		return *this;
	}

	void push(unsigned int n)
	{
	static std::set<unsigned int> uniqueValues;
	if (!uniqueValues.insert(n).second) {
		throw FileException("Error: Duplicate value detected!");
	}
	vec.push_back(n);
	lst.push_back(n);
}

// void showSequence(const std::string &label) const
//{
//     std::cout << label;
//     if (!vec.empty()) {
//         for (size_t i = 0; i < vec.size(); i++)
//{
//             std::cout << vec[i] << " ";
//         }
//     }
//     if (!lst.empty())
//{
//         for (std::list<unsigned int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
//             std::cout << *it << " ";
//         }
//     }
//     std::cout << std::endl;
// }

	void showSequence(const char* msg)
	{
		std::cout << msg;
		for (size_t i = 0; i < vec.size() && i < 5; i++)
			std::cout << vec[i] << " ";
		if (vec.size() > 5)
			std::cout << "[...]";
		std::cout << "\t(" << vec.size() << ")" << std::endl;
	}

	void sort();
	clock_t getVecTime() { return vecTime; }
	clock_t getTempVecTime() { return tempVecTime; }
	int getVecSize() { return vec.size(); }
	void printLst() { std::cout << "List size: " << lst.size() << std::endl; }
	clock_t getLstTime() { return lstTime; }
	int getLstSize() { return lst.size(); }
};