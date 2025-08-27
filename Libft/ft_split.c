/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:04:55 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/21 15:28:54 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (str[i + 1] == '\0' || str[i + 1] == c)
				count++;
			i++;
		}
	}
	return (count);
}

static int	ft_count_letter(char *str, char c, int n)
{
	int	i;
	int	count;
	int	letter;

	i = 0;
	count = 0;
	letter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (count == n)
				letter++;
			i++;
		}
		count++;
	}
	return (letter);
}

static char	*ft_putword_intab(char *str, char *word, char c, int n)
{
	int	i;
	int	count;
	int	letter;

	i = 0;
	count = 0;
	letter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (count == n)
			{
				word[letter] = str[i];
				letter++;
			}
			if (str[i + 1] == '\0' || str[i + 1] == c)
				count++;
			i++;
		}
	}
	word[letter] = '\0';
	return (word);
}

static char	**free_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_word((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_count_word((char *)s, c))
	{
		tab[i] = malloc(sizeof(char) * (ft_count_letter((char *)s, c, i) + 1));
		if (!tab[i])
			return (free_malloc(tab));
		tab[i] = ft_putword_intab((char *)s, tab[i], c, i);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
