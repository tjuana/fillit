# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 13:19:12 by tjuana            #+#    #+#              #
#    Updated: 2019/05/11 17:03:47 by tjuana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CCFLAGS	= gcc -Wall -Wextra -Werror

SRCS		= check_file.c error.c fillit.c game.c store_block.c solution.c

OBJECTS = $(subst .c,.o,$(subst /,,$(SRCS)))

all : $(NAME)

$(NAME) : lib $(OBJECTS)
	@$(CCFLAGS) -o $(NAME) $(OBJECTS) -L libft -lft

$(OBJECTS) :
	@$(CCFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	@make -C libft

clean:
	@rm -rf $(OBJECTS)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
