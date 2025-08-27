/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:29:42 by npetitpi          #+#    #+#             */
/*   Updated: 2022/09/23 14:30:49 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_rest(int fd, char *rest_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rest_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		rest_str = ft_strjoin(rest_str, buff);
	}
	free (buff);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest_str[fd] = ft_read_to_rest(fd, rest_str[fd]);
	if (!rest_str[fd])
		return (NULL);
	line = ft_get_line(rest_str[fd]);
	rest_str[fd] = ft_new_str(rest_str[fd]);
	return (line);
}
