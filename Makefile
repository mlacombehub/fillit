# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 17:23:16 by xbarthe           #+#    #+#              #
#    Updated: 2019/02/21 17:54:52 by mlacombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
TARGET= fillit

# compiler
CC= gcc
CFLAGS= -Wall -Wextra -Werror
DFLAGS= -g
SUFFIX= c
LIB=ft
DEPENDANCY= $(DEP_PREFIX)$(DEP_NAME)/$(DEP_PREFIX)$(DEP_NAME)$(DEP_SUFFIX)
DEP_PREFIX= lib
DEP_NAME=ft
DEP_SUFFIX=.a

# resources
SRC_PATH= ./srcs/
INCL_PATH= ./includes/
OBJ_PATH= ./objects/

# files
SRC= 	main.c \
		checker.c \
		slicer.c \
		solver.c \
		utilities.c \

# sources and objects construction
SRCFILES = $(SRC:%.$(SUFFIX)=$(SRC_PATH)%.$(SUFFIX))
OBJ= $(SRC:.$(SUFFIX)=.o)
OBJ_D= $(SRC:.$(SUFFIX)=_debug.o)

TARGET_D=$(TARGET)_debug

# rules



# default rule
all: $(DEPENDANCY) $(TARGET)

#dependancy
$(DEPENDANCY):
	@cd $(DEP_FOLDER) && $(MAKE) && cp ./$(DEPENDANCY) ../ && cp ./$(LIB_HEAD) ../
	@echo "-- Library " $(DEPENDANCY) " generated and copied with header"


# program creation
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(DEPENDANCY)

# object creation
%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) $(DEPENDANCY) -c -I$(INCL_PATH) $<

#debug rule
debug: $(DEPENDANCY) $(TARGET_D)

# debug program creation
$(TARGET_D): clean $(OBJ)
	$(CC) $(CFLAGS) -g -o $(TARGET_D) $(OBJ) $(DEPENDANCY)

# debug object creation
%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) $(DEPENDANCY) -g -c -I$(INCL_PATH) $<


# diagnostic
test:
	@echo "--- What will we compile ---"
	@echo "binary name: 		" $(TARGET)
	@echo "sources: 		" $(SRCFILES)
	@echo "obj:			" $(OBJ)
	@echo "--- Debug options ---"
	@echo "debug binary name: 	" $(TARGET_D)
# clean the object files
clean:
	/bin/rm -rf $(OBJ)

# clean program and objects
fclean: clean
	/bin/rm -f $(TARGET) $(TARGET)_debug

# clean ALL and remake all
re: fclean all

.PHONY : debug all clean fclean re test
