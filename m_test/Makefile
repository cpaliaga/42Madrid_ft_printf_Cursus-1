# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 17:58:52 by caliaga-          #+#    #+#              #
#    Updated: 2023/10/16 18:26:38 by caliaga-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC = ../M/
FILES_SRC = ft_printf.c ft_util_char.c ft_util_number.c
SRC = $(addprefix $(DIR_SRC), $(FILES_SRC))

DIR_INC = ../M/
INC_H = ft_printf.h
INC = $(addprefix $(DIR_INC), $(INC_H))

DIR_LIB = ../M/
LI = ftprintf
LIB = $(addprefix lib, $(LI))
NAME = $(addsuffix .a,$(addprefix $(DIR_LIB), $(LIB)))

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

$(NAME): $(TEST_A)
	@$(MAKE) -C $(DIR_LIB) 	
	@gcc $(CFLAGS) $(TEST_A) -L$(DIR_LIB) -l$(LI) -o $(EXEC)
	@./m_test

nor:
	@norminette $(SRC)
	@norminette $(INC)

clean:
	@cd ..;$(MAKE) clean

fclean:
	@$(MAKE) fclean -C $(DIR_LIB)

re: fclean all

.PHONY: all fclean re
