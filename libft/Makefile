# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 15:33:24 by lgalstya          #+#    #+#              #
#    Updated: 2022/03/30 17:42:16 by lgalstya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=   libft.a
SRCS	=	$(shell find "." -name "*.c")
SRCS_B	=   ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	${LIBC} $(NAME) $(OBJS)

all: $(NAME) 

bonus: $(NAME) $(OBJS_B)
	${LIBC} $(NAME) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
    
re: fclean all

.PHONY: all bouns clean fclean re .c.o
