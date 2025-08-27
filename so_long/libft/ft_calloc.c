
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if ((nmemb * size) / size != nmemb)
		return (0);
	p = malloc(nmemb * size);
	if (!p)
		return (p);
	ft_bzero(p, nmemb * size);
	return (p);
}
