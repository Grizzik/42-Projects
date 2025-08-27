/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:24:52 by npetitpi          #+#    #+#             */
/*   Updated: 2022/07/22 12:54:05 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_putchar(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_ptr_hexa_len(unsigned long int num);
void	ft_ptr_hexa(unsigned long int num);
int		ft_put_ptr_hexa(unsigned long ptr);
void	ft_condition(long nb, int i, char *itoa);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_num_len(unsigned int num);
char	*ft_uns_itoa(unsigned int n);
int		ft_put_uns_nbr(unsigned int n);
int		ft_hexa_len(unsigned int num);
void	ft_hexa(unsigned int num, const char format);
int		ft_put_hexa(unsigned int num, const char format);
int		ft_percent(void);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);

#endif