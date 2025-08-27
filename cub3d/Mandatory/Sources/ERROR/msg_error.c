/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:00:15 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/29 15:47:19 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	msg_error(char *s1, char *s2, int ret_val)
{
	write(STDOUT_FILENO, "Error\n", 6);
	if (s1)
		write(STDOUT_FILENO, s1, ft_strlen(s1));
	if (s2)
		write(STDOUT_FILENO, s2, ft_strlen(s2));
	write(STDOUT_FILENO, "\n", 1);
	return (ret_val);
}
