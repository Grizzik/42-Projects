
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const void	*s;
	void		*d;

	if (src < dest && dest < src + n)
	{
		while (n--)
		{
			d = dest + n;
			s = src + n;
			*(char *)d = *(char *)s;
		}
		return (d);
	}
	return (ft_memcpy(dest, src, n));
}
