#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <iostream>

template<typename T> void	swap(T &a, T &b) //Thing bc it return a thing
{
	T	tmp;

	std::cout << "Swaping" << std::endl;
	tmp = b;
	b = a;
	a = tmp;
}

template<typename T> const T &max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template<typename T> const T &min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

#endif