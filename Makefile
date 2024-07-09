# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 20:26:20 by sabraham          #+#    #+#              #
#    Updated: 2023/08/24 20:26:21 by sabraham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_hex.c ft_print_putptr.c ft_print_unsigned.c ft_print_nbr.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re