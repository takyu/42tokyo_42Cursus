# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 13:28:51 by tnagoshi          #+#    #+#              #
#    Updated: 2021/03/28 13:28:54 by tnagoshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c \
		srcs/error.c 

NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
RM = rm -f

LIBS = libft.a
MLBX = libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./minilibx_mms
	cp ./libft/libft.a libft.a
	cp ./minilibx_mms/libmlx.dylib libmlx.dylib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLBX)

clean: $(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibx_mms

fclean: clean
	make fclean -C ./libft
	$(RM) libmlx.dylib
	$(RM) libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re