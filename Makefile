# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/11/03 21:08:57 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

HEADER = push_swap.h

LIB1 = libft/libft.a

LIB2 = libft/b_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -o

SRC1 = checker.c

SRC2 = push_swap.c

SRCS = list.c \
	   lstdel.c \
	   operations.c \
	   multi_operations.c \
	   print_list.c \

SRCO = $(SRCS:.c=.o)

$(NAME1):
	make -C libft/
	gcc $(FLAGS) $(NAME1) $(SRCS) $(SRC1) $(LIB1) $(LIB2) -I=$(HEADER)
	gcc $(FLAGS) $(NAME2) $(SRCS) $(SRC2) $(LIB1) $(LIB2) -I=$(HEADER)

all: $(NAME1)

san: fclean
	make -C libft/
	gcc -fsanitize=address -g $(FLAGS) $(NAME1) $(SRCS) $(SRC1) $(LIB1) $(LIB2) -I=$(HEADER)
	gcc -fsanitize=address -g $(FLAGS) $(NAME2) $(SRCS) $(SRC2) $(LIB1) $(LIB2) -I=$(HEADER)

clean:
	make clean -C libft/
	/bin/rm -f $(SRCO) checker.o push_swap.o

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME1) $(NAME2) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
