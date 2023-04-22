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

DIR_SRC = ../
FILES_SRC = ft_printf.c ft_util_char.c ft_util_number.c
SRC = $(addprefix $(DIR_SRC), $(FILES_SRC))

DIR_INC = ../
INC_H = ft_printf.h
INC = $(addprefix $(DIR_INC), $(INC_H))

DIR_LIB = ../
NAME = ../libftprintf.a

OBJ = $(subst .c,.o,$(SRC))
CFLAGS = -Wall -Wextra -Werror
ST = -pedantic -g3
SA = -fsanitize=address

DIR_TEST_A = ./
FILES_TEST_A = tester_print.c
TEST_A = $(addprefix $(DIR_TEST_A), $(FILES_TEST_A))

DIR_EXE = ./
FILE_EXE = m_test
EXEC = $(addprefix $(DIR_EXE), $(FILE_EXE))

#### REGLAS ####
all: $(NAME)

$(NAME): $(OBJ)
	@cd ..;$(MAKE)
	@gcc $(CFLAGS) $(TEST_A) -L$(DIR_LIB) -lftprintf -o $(EXEC)
	@./m_test

$(filter-out %.o, $(SRC)): $(filter-out %.c, $(SRC))
	@gcc $(CFLAGS) -I$(DIR_INC) -c $^ -o $@

nor:
	@norminette $(SRC)$(INC)

clean:
	@rm -fr $(SRC:.c=.o)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -fr $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
