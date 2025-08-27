CFLAGS	= -Wall -Werror -Wextra
CC		= cc $(CFLAGS)
MLX		= -lm  -lXext -lX11 -Lmlx -lmlx

NAME =	so_long
LIBFT =	libft/libft.a
SRCS =	ft_check_error.c ft_check_map.c ft_draw_map.c ft_handle_event.c ft_handle_images.c \
		ft_handle_map.c ft_player_moves.c main.c
SRCS_BONUS = Bonus/b_ft_check_error.c b_ft_check_map.c b_ft_draw_map.c b_ft_handle_event.c b_ft_handle_images.c \
		b_ft_handle_map.c b_ft_player_moves.c b_main.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

bonus:		$(OBJS) $(OBJS_BONUS)
	$(../NAME) $(OBJS) $(OBJS_BONUS)

$(LIBFT):
	cd libft && $(MAKE)

%.o: %.c
	$(CC) -c $^

clean:
	rm -f $(OBJ) $(OBJS_BONUS)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re