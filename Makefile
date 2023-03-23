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

SRC_DIR = ./
SRC_FILES = ft_printf.c ft_util_char.c ft_util_number.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

TEST_DIR = ./
TEST_Alpha = tester_print.c
TEST_A = $(addprefix $(TEST_DIR), $(TEST_Alpha))

INC_D = ./
INC_H = ft_printf.h
INC = $(addprefix $(INC_D), $(INC_H))

OBJ = $(subst .c,.o,$(SRC))
OBJ_B = $(subst .c,.o,$(BONUS))
CFLAGS = -Wall -Wextra -Werror
SA = -fsanitize=address
BUF = -DBUFFER_SIZE=4

LIB = ./
NAME = ./libftprintf.a
EXEC = ./ppp
HIDE = .

#### REGLAS ####
all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "library $(NAME) created & indexed"
	
$(filter-out %.o, $(SRC)): $(filter-out %.c, $(SRC))
	@gcc $(CFLAGS) $(BUF) -I$(INC_D) -c $^ -o $@

ex: $(NAME)
	@gcc $(CFLAGS) $(BUF) $(TEST_A) -L$(LIB) -lftprintf -o $(EXEC)

nor:
	@norminette $(SRC)$(INC)

clean:
	@rm -fr $(SRC:.c=.o)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -fr $(NAME)
	@echo "$(NAME) deleted"

re: fclean all ex

.PHONY: all ex clean fclean re
