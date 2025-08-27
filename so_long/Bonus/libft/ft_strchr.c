
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (c > 255)
		c = c - 256;
	while (*s)
	{
		if (*s == c)
			return ((char *)(s));
		s++;
	}
	if (*s == c)
		return ((char *)(s));
	return (0);
}
