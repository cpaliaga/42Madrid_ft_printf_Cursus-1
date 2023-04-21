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

DIR_TEST_A = ../
FILES_TEST_A = tester_print.c
TEST_A = $(addprefix $(DIR_TEST_A), $(FILES_TEST_A))

DIR_EXE = ../
FILE_EXE = try_print
EXEC = $(addprefix $(DIR_EXE), $(FILE_EXE))

DIR_INC = ./
INC_H = ft_printf.h
INC = $(addprefix $(DIR_INC), $(INC_H))

NAME = libftprintf.a
HIDE = .

OBJ = $(subst .c,.o,$(SRC))
OBJ_B = $(subst .c,.o,$(BONUS))
CFLAGS = -Wall -Wextra -Werror
SA = -fsanitize=address
BUF = -DBUFFER_SIZE=4

#### REGLAS ####
all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "library $(NAME) created & indexed"
	
$(filter-out %.o, $(SRC)): $(filter-out %.c, $(SRC))
	@gcc $(CFLAGS) $(BUF) -I$(DIR_INC) -c $^ -o $@

ex: $(NAME)
	@gcc $(CFLAGS) $(BUF) $(TEST_A) -L$(DIR_INC) -lftprintf -o $(EXEC)

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
