# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 11:03:36 by asabri            #+#    #+#              #
#    Updated: 2023/07/08 14:18:45 by yelwadou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/env/env.c src/env/env_utils.c src/main.c src/token/tokenizing.c gc/ft_malloc.c gc/utils_malloc.c\
		src/built_ins/cd.c src/built_ins/echo.c src/built_ins/env.c src/built_ins/exit.c src/built_ins/export.c\
		src/built_ins/pwd.c src/built_ins/unset.c
 
CC = cc
CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf
HEADER = includes/minishell.h includes/ft_malloc.h includes/token.h

OBJS = $(SRC:.c=.o)

all : $(NAME)

libftrule :
	make -C libft-42

%.o : %.c $(HEADER) libft-42/libft.h
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS) $(HEADER) libftrule
		$(CC) $(CFLAGS) $(OBJS) libft-42/libft.a -o $@ -lreadline
clean :
	$(RM) $(OBJS) 
	make clean -C libft-42

fclean : clean
	$(RM) $(NAME) 
	make fclean -C libft-42
	
re : fclean all