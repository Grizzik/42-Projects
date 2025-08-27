
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	if (size > i)
	{
		while (j < (size - i - 1) && src[j])
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	if (size > i)
		return (i + j);
	return (size + j);
}
