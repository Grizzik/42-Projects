/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:10:20 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/26 16:14:05 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;
	return ;
}

Base	*Base::generate(void)
{
	srand(time(NULL));
	int randomNbr = rand() % 3;
	if (randomNbr == 0)
		return (new A());
	else if (randomNbr == 1)
		return (new B());
	return (new C());
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Le type de p est A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Le type de p est B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Le type de p est C" << std::endl;
	else
		std::cerr << "Le type de p est inconnu" << std::endl;
}

void	Base::identify(Base& p)
{
	identify(&p);
}


int	main(void)
{
	Base	*obj = Base::generate();

	Base::identify(obj);
	Base::identify(*obj);
	delete (obj);
	return (0);
}

/*
Unlike other casts, a dynamic_cast involves a run-time type check. 
If the object bound to the pointer is not an object of the target type, 
it fails and the value is 0. 
If it's a reference type when it fails, then an exception of type bad_cast is thrown. 
*/