# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 17:23:16 by xbarthe           #+#    #+#              #
#    Updated: 2019/02/22 15:44:40 by xbarthe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME= fillit

# compiler
CC= gcc
CFLAGS= -Wall -Wextra -Werror
DFLAGS= -g
SUFFIX= c
LIB=ft
DEP_PREFIX= lib
DEP_NAME=ft
DEP_SUFFIX=.a

# dependancy paths etc.
DEPENDANCY= $(DEP_FOLDER)/$(DEP_PREFIX)$(DEP_NAME)$(DEP_SUFFIX)
DEP_FOLDER= $(DEP_PREFIX)$(DEP_NAME)

# resources
SRC_PATH= srcs/
INCL_PATH= -Iincludes/
OBJ_PATH= objects/

# files
SRC= 	main.c \
		checker.c \
		slicer.c \
		solver.c

# sources and objects construction
SRCFILES = $(SRC:%.$(SUFFIX)=$(SRC_PATH)%.$(SUFFIX))
OBJ= $(addprefix $(OBJ_PATH), $(SRC:.$(SUFFIX)=.o))

# default rule
all: $(NAME)

# program creation
$(NAME): $(DEPENDANCY) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(DEPENDANCY)

#dependancy
$(DEPENDANCY):
	$(MAKE) -C $(DEP_FOLDER)
	@echo "-- Library " $(DEPENDANCY) " generated"

# object creation
objects/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< $(INCL_PATH)
	mv *.o $(OBJ_PATH)
# diagnostic
test:
	@echo "--- What will we compile ---"
	@echo "binary name: 		" $(NAME)
	@echo "dep:			" $(DEPENDANCY)
	@echo "objpath:			" $(OBJ_PATH)
	@echo "obj:			" $(OBJ)
	@echo "sources: 		" $(SRCFILES)

# clean the object files
clean:
	rm -f $(OBJ)
	cd $(DEP_FOLDER) && $(MAKE) clean

# clean program and objects
fclean: clean
	rm -f $(NAME)
	cd $(DEP_FOLDER) && $(MAKE) fclean
# clean ALL and remake all
re: fclean all

.PHONY : all clean fclean re test
