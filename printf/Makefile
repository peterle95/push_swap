# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 13:31:36 by pmolzer           #+#    #+#              #
#    Updated: 2024/06/20 18:06:11 by pmolzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	printf.a

SRC	=	ft_printf.c			    \
		ft_putchar_printf.c		\
		ft_putstr_printf.c		\
		ft_putnbr_printf.c		\
		ft_putuint_printf.c		\
		ft_puthex_printf.c		\
		ft_putptr_printf.c		\
		ft_aux_printf.c			\

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re
	
