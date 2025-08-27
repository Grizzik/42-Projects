
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (0);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
