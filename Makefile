# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2021/11/16 17:31:41 by msierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	pipex

SRCS		=	./includes/ft_bzero.c		\
				./includes/ft_calloc.c		\
				./includes/ft_memcpy.c		\
				./includes/ft_putchar_fd.c	\
				./includes/ft_split.c		\
				./includes/ft_strchr.c		\
				./includes/ft_strjoin.c		\
				./includes/ft_strlen.c		\
				./includes/ft_strncmp.c		\
				./includes/ft_strnstr.c		\
				./includes/ft_substr.c		\
		  		./sources/ft_checker.c		\
		  		./sources/ft_children.c		\
		  		./sources/ft_errors.c		\
		  		./sources/ft_getargs.c		\
		  		./sources/ft_pipex.c		\
		  		./sources/ft_putstring.c	\

PINK = \033[1;35m
GREEN = \033[1;32m
BLUE = \033[1;36m
RESET = \033[0m

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra

all	:		$(NAME)

$(NAME)	:	start $(OBJS)
			@$(CC) $(OBJS) -o $(NAME) -fsanitize=address
			@echo "$(RESET)Done"
			@echo "$(GREEN)==========WELLDONE==========$(RESET)"
			@echo "Success creating $(NAME) file"

start:
			@echo "$(BLUE)==========CREATING: $(GREEN)$(NAME)$(BLUE)==========$(PINK)"

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
