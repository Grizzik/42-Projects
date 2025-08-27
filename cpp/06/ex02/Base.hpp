# include <iostream>
# include <cmath>

#ifndef BASE_HPP
# define BASE_HPP


class Base
{
	public:

		virtual ~Base(void);

		static Base	*generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);
};

#endif