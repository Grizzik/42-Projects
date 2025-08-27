#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct	Data
{
	std::string	str;
}				Data;

class Serializer
{
	private:
		Serializer(void);

	public:

		Serializer(Serializer const &copy);
		~Serializer(void);

		Serializer	&operator = (Serializer const &toCopy);

		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif