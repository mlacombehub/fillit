# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 17:23:16 by xbarthe           #+#    #+#              #
#    Updated: 2019/02/27 15:35:22 by mlacombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME= fillit

# compiler
CC= gcc
override CFLAGS += -Wall -Wextra -Werror
LIB=ft
DEP_PREFIX= lib
DEP_NAME=ft
SRC_SUFFIX=.c
DEP_SUFFIX=.a
OBJ_SUFFIX=.o

RM= rm -f

# dependancy paths etc.
DEPENDANCY= $(DEP_FOLDER)/$(DEP_PREFIX)$(DEP_NAME)$(DEP_SUFFIX)
DEP_FOLDER= $(DEP_PREFIX)$(DEP_NAME)

# resources
SRC_PATH= srcs/
INCL_PATH= includes/
OBJ_PATH= objects/

# files
SRC= 	main.c \
		checker.c \
		slicer.c \
		solver.c

# sources and objects construction
SRCFILES = $(SRC:%$(SUFFIX)=$(SRC_PATH)%$(SRC_SUFFIX))
OBJ = $(addprefix $(OBJ_PATH), $(SRC:$(SRC_SUFFIX)=$(OBJ_SUFFIX)))

# default rule
all: $(NAME)

# program creation
$(NAME): $(DEPENDANCY) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#dependancy
$(DEPENDANCY): FORCE
	$(MAKE) -C $(DEP_FOLDER)
	@echo "-- Library " $(DEPENDANCY) " generated"

$(OBJ_PATH):
	mkdir -p $@

# object creation
$(OBJ_PATH)%$(OBJ_SUFFIX): $(SRC_PATH)%$(SRC_SUFFIX) | $(OBJ_PATH)
	$(CC) -I $(INCL_PATH) $(CFLAGS) -c -o $@ $<

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
	$(RM) -R $(OBJ) $(OBJ_PATH)
	$(MAKE) clean -C $(DEP_FOLDER)

# clean program and objects
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(DEP_FOLDER)

# clean ALL and remake all
re: fclean
	$(MAKE)

FORCE:

.PHONY : all clean fclean re test FORCE
