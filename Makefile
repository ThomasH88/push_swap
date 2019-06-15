# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2019/06/15 15:06:04 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[1;32m
YELLOW = \033[1;33m
ORANGE = \033[1;31m
BLUE = \033[1;36m
GREY = \033[1;30m
NC = \033[0m

NAME1 = checker

NAME2 = push_swap

IDIR = includes

HEADER = $(addprefix $(IDIR)/, push_swap.h)

CC = gcc

LIB1 = libft/libft.a

LIB2 = ft_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -I$(IDIR)

ODIR = objs

SDIR = srcs

OBJ1 = $(addprefix $(ODIR)/, checker.o)

OBJ2 = $(addprefix $(ODIR)/, push_swap.o)

OBJS = $(addprefix $(ODIR)/, list.o \
	   lstdel.o \
	   lstextras.o \
	   side_funct.o \
	   offset.o \
	   instructions_a.o \
	   instructions_b.o \
	   multi_operations.o \
	   print_list.o \
	   resolve.o \
	   resolve_small.o)


$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
	mkdir -p objs
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME1): $(OBJ1) $(OBJS) $(LIB1) $(LIB2)
	$(CC) -o $@ $^ $(FLAGS)

$(NAME2): $(OBJ2) $(OBJS) $(LIB1) $(LIB2)
	$(CC) -o $@ $^ $(FLAGS)

$(LIB1):
	make -C libft/

$(LIB2):
	make -C ft_printf/

all: $(NAME1) $(NAME2)

san: fclean
	make -C libft/
	make -C ft_printf/
	gcc -fsanitize=address -g $(FLAGS) $(NAME1) $(SRCS) $(SRC1) $(LIB1) $(LIB2) -I=$(HEADER)
	gcc -fsanitize=address -g $(FLAGS) $(NAME2) $(SRCS) $(SRC2) $(LIB1) $(LIB2) -I=$(HEADER)

clean:
	make clean -C libft/
	make clean -C ft_printf/
	/bin/rm -rf objs $(SRCO) checker.o push_swap.o

fclean: clean
	make fclean -C libft/
	make fclean -C ft_printf/
	/bin/rm -rf $(NAME1) $(NAME2) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
