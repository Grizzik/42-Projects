# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:36:40 by npetitpi          #+#    #+#              #
#    Updated: 2022/11/07 15:37:24 by npetitpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIST_DIR		= List/
MOOV_DIR		= Moovs/
RESOLVE_DIR		= Resolve/


SRCS 		=	${LIST_DIR}bits.c \
				${LIST_DIR}ft_list.c \
				${LIST_DIR}list_moovs.c \
				${LIST_DIR}parsing.c \
				${MOOV_DIR}moovs.c \
				${MOOV_DIR}same_time.c \
				${RESOLVE_DIR}radix_sort.c \
				${RESOLVE_DIR}short_sort.c \
				${RESOLVE_DIR}sort_utils.c \
				main.c \

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wall

RM = rm -rf

${NAME}: ${OBJS}
	gcc -g3 ${SRCS} -o $@

all: ${NAME}

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} push_swap

re: fclean all

.PHONY: clean fclean re all 