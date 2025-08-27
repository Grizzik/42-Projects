CFLAGS	= -Wall -Werror -Wextra
CC		= cc $(CFLAGS)
MLX		= -lm  -lXext -lX11 -Lmlx -lmlx

NAME =	so_long_bonus
LIBFT =	libft/libft.a

SRCS_BONUS = b_ft_check_error.c b_ft_check_map.c b_ft_draw_map.c b_ft_handle_event.c b_ft_handle_images.c \
		b_ft_handle_map.c b_ft_handle_trap.c b_ft_player_moves.c b_ft_trap_moves.c b_main.c

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)

%.o: %.c
	$(CC) -c $^

clean:
	rm -f $(OBJS_BONUS)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re