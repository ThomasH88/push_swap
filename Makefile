# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2019/06/15 16:06:04 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

IDIR = include

HEADER = $(addprefix $(IDIR)/, push_swap.h)

CC = gcc

LIB1 = libft/libft.a

LIB2 = ft_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -I$(IDIR)

ODIR = obj

SDIR = src

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
	mkdir -p obj
	$(CC) -c -o $@ $< $(FLAGS)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(OBJS) $(LIB1) $(LIB2)
	$(CC) -o $@ $^ $(FLAGS)

$(NAME2): $(OBJ2) $(OBJS) $(LIB1) $(LIB2)
	$(CC) -o $@ $^ $(FLAGS)

$(LIB1):
	make -C libft/

$(LIB2):
	make -C ft_printf/

clean:
	make clean -C libft/
	make clean -C ft_printf/
	/bin/rm -rf obj $(SRCO) checker.o push_swap.o

fclean: clean
	make fclean -C libft/
	make fclean -C ft_printf/
	/bin/rm -rf $(NAME1) $(NAME2) *.out* *.dSYM

re: fclean all

.PHONY: all clean fclean re
