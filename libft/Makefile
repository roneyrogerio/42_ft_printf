# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 15:07:48 by rde-oliv          #+#    #+#              #
#    Updated: 2020/02/14 14:00:49 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
INC		= libft.h
SRC		= ft_strmapi.c ft_split.c ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_strnstr.c ft_memcmp.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_memcpy.c ft_memset.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c
OBJS	= $(SRC:.c=.o)
CCFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CCFLAGS) -c $(SRC) -I $(INC)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all
