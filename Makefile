# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 10:05:37 by mpytienk          #+#    #+#              #
#    Updated: 2018/01/11 10:05:43 by mpytienk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =	main.c \
		lst_handler.c \
		error_handler.c \
		pars_param.c \
		init.c \
		bypass.c \
		display.c \
		display_misc.c \
		display_misc1.c \
		display_long.c \
		sort.c \
		sort_misc.c \
		len_handler.c \
		len_handler1.c \
		display_short.c \

OBJ = $(SRC:%.c=%.o)
INCLUDES = ft_ls.h
NAME = ft_ls
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
CC = gcc

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -I $(LIBDIR)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBDIR)/libft.a

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
