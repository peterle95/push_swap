# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:51:45 by pmolzer           #+#    #+#              #
#    Updated: 2024/08/15 14:32:36 by pmolzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  $(wildcard sources/algorithm/*.c sources/utils/*.c)

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

# The $ symbol:
#
# In Makefiles, $ is used for variable expansion.
# ${MAKE} is a way to reference the value of the MAKE variable.
# Typically, MAKE is an implicit variable in Make that contains the name of the make program being used (usually "make").
#			You could also write "make -C ./libft"
# Using ${MAKE} instead of directly writing "make" allows for flexibility if someone wants to use a different make program or specify a full path.
# 
# 
# The -C flag:
# 
# This is an option for the make command.
# -C dir tells make to change to directory dir before reading the makefile and doing anything else.
# In this case, -C ./libft means "change to the ./libft directory before executing make".
clean: 
	${MAKE} -C ./libft fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
