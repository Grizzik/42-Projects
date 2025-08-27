CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		= ./whatever
NAME_SHORT	= whatever

INCS_DIR	= ./
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

SRCS_DIR 	= ./
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS_DIR	= ./
OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

_OK			= [\033[32mOK\033[0m]

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJS_DIR)
			@$(CC) $(MAIN_INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean:
		@${RM} $(OBJS)

fclean:		clean
		@${RM} ${NAME}
		@echo "Everything cleaned"

re			: fclean all

.PHONY		: all clean fclean re