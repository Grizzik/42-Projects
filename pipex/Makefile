NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS =     pipex_utils.c \
		pipex.c \
		pipex2.c \
		pipex_utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all