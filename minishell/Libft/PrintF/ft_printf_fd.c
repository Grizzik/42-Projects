/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:45:42 by npetitpi          #+#    #+#             */
/*   Updated: 2023/12/02 16:17:39 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libftfull.h"

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	args;
	t_print	param;
	int		nb_char;

	if (!is_all_coherent(str))
		return (0);
	va_start(args, str);
	nb_char = 0;
	while (*str)
	{
		if (*str != '%')
			str = print_str_classic(str, &nb_char, fd);
		else
		{
			str++;
			init_param(&param);
			str = parse_param(&param, str, args);
			if (!str)
				return (0);
			param.fd = fd;
			print_param(param, args, &nb_char);
		}
	}
	va_end(args);
	return (nb_char);
}
