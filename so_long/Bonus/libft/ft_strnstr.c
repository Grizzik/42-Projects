
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size_l;
	size_t	count;

	size_l = ft_strlen(little);
	if (!size_l)
		return ((char *)(big));
	count = 0;
	while (*big && size_l <= len && count < len)
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, size_l) == 0 \
				&& size_l <= len - count)
				return ((char *)big);
		}
		big++;
		count++;
	}
	return (0);
}
