# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 15:15:28 by npetitpi          #+#    #+#              #
#    Updated: 2022/07/22 14:29:57 by npetitpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME 		= libftprintf.a

FLAGS		= -Wall -Wextra -Werror

FT_DIR		= Utils/

SRCS 		=	${FT_DIR}ft_hexa.c \
				${FT_DIR}ft_percent.c \
				${FT_DIR}ft_ptr_hexa.c \
				${FT_DIR}ft_putchar.c \
				${FT_DIR}ft_putnbr.c \
				${FT_DIR}ft_putstr.c \
				${FT_DIR}ft_uns_nbr.c \
				ft_printf.c \

OBJS 		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean