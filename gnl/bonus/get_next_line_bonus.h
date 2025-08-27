/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:46:49 by npetitpi          #+#    #+#             */
/*   Updated: 2022/09/23 14:30:50 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_to_rest_str(int fd, char *rest_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *rest_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *rest_str);
char	*ft_new_str(char *rest_str);

#endif