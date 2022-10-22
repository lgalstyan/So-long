NAME 	= so_long
SRCS 	= $(shell find "./src" -name "*.c")
OBJS 	= $(SRCS:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
INCLUDE = -I./include
LINKER	= -L./libft -lft
M_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM		= rm -f

.c.o:
	$(CC) $(FLAGS) $(INCLUDE) -Imlx -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft 
	$(CC) $(FLAGS) $(INCLUDE) $(LINKER) $(OBJS) $(M_FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
