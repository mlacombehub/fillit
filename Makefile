# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/13 14:01:25 by mlacombe          #+#    #+#              #
#    Updated: 2019/01/25 17:51:22 by xbarthe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -Rf

SRC = main.c solver.c
INCLUDES = fillit.h

SRC_DIR = srcs/
OBJ_DIR = objects/
INC_DIR = includes/

OBJ := $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
SRC := $(addprefix $(SRC_DIR),$(SRC))
INCLUDES := $(addprefix $(INC_DIR),$(INCLUDES))

all: $(NAME)

$(OBJ_DIR):
	mkdir $@

$(SRC_DIR):
	mkdir $@
	cp $(SRC) $@
	rm $(SRC)

$(INC_DIR):
	mkdir $@
	cp $(INCLUDES) $@
	rm $(INCLUDES)

$(OBL_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAG) -o $@ -c $< -I $(INCLUDES)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(OBJ_DIR)
	cp -R $(SRC_DIR) ./
	$(RM) $(SRC_DIR)
	cp -R $(INC_DIR) ./
	$(RM) $(INC_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re