# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:55:55 by tnagoshi          #+#    #+#              #
#    Updated: 2021/01/26 17:23:26 by tnagoshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_initialize.c ft_printf.c ft_utils.c print_address.c print_char.c \
		print_number_utils.c print_number.c print_string.c
HEADER = ./includes/
SRCSDIR = ./srcs/
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(HEADER)
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS:%.o=$(SRCSDIR)%.o)
	ar rc $(NAME) $^

clean:
	$(RM) $(OBJS:%.o=$(SRCSDIR)%.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re