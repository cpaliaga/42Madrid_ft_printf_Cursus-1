# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 17:58:52 by caliaga-          #+#    #+#              #
#    Updated: 2023/03/23 19:53:26 by caliaga-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC = ./
FILES_SRC = ft_printf.c ft_util_char.c ft_util_number.c
SRC = $(addprefix $(DIR_SRC), $(FILES_SRC))

DIR_INC = ./
FILES_INC = ft_printf.h
INC = $(addprefix $(DIR_INC), $(FILES_INC))

DIR_LIB = ./
NAME = libftprintf.a

OBJ = $(subst .c,.o,$(SRC))
CFLAGS = -Wall -Wextra -Werror

#### REGLAS ####
all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "library $(NAME) created & indexed"
	
$(filter-out %.o, $(SRC)): $(filter-out %.c, $(SRC))
	@gcc $(CFLAGS) $(BUF) -I$(DIR_INC) -c $^ -o $@

clean:
	@rm -fr $(SRC:.c=.o)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -fr $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
