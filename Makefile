# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:51:45 by pmolzer           #+#    #+#              #
#    Updated: 2024/06/20 17:51:45 by pmolzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a 
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

PRINTF_PATH	= printf/
PRINTF_NAME	= printf.a 
PRINTF		= $(PRINTF_PATH)$(PRINTF_NAME)

INC		=	-I .includes/\
			-I $(LIBFT_PATH)\
			-I $(PRINTF_PATH)\

SRC_PATH = sources/
SRC =  $(wildcard sources/algorithm/*.c sources/utils/*.c)
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRCS:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(PRINTF) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(PRINTF):
		@make -sC $(PRINTF_PATH)

$(LIBFT):
		@make -sC $(LIBFT_PATH_PATH)


$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(INC)
	@echo "Fractol ready."

RM = rm -rf

clean: 
	@$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	@${RM} ${NAME}
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean	

re: fclean all

.PHONY: all clean fclean re