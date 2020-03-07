# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 13:57:03 by rde-oliv          #+#    #+#              #
#    Updated: 2020/03/05 02:52:56 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c func/ft_str2lst.c func/ft_lstnew.c func/ft_lstlast.c func/ft_lstadd_back.c func/ft_istype.c func/ft_putargs.c func/ft_put_stype.c func/ft_put_dtype.c func/ft_flag2struct.c func/ft_nbrlen.c func/ft_padding.c func/ft_put_ctype.c func/ft_putlongnbr_fd.c func/ft_put_utype.c func/ft_ifnegstar.c func/ft_dec2base.c func/ft_put_ptype.c func/ft_put_pcttype.c func/ft_put_xtype.c func/ft_lstfree.c
INC = ft_printf.h
FLAGS = -Wall -Werror -Wextra
NOBJS := $(SRC:func/%=%)
OBJS = $(NOBJS:.c=.o)
LIBFT = libft

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
