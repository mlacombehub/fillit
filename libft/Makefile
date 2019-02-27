# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:32:14 by mlacombe          #+#    #+#              #
#    Updated: 2019/02/26 14:17:29 by mlacombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
override CFLAGS += -Wall -Wextra -Werror
ARFLAGS = rs

SRC =	ft_bzero.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strchrnul.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strmapi.c\
		ft_strnstr.c\
		ft_strlcpy.c\
		ft_isspace.c\
		ft_strctrim.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_strrev.c\
		ft_swap.c\
		ft_sqrt.c\
		ft_reversed_bits.c\
		ft_print_bits.c\
		ft_swap_bits.c\
		ft_strcntc.c\
		ft_strndup.c\
		ft_strnlen.c\
		ft_min.c\
		ft_max.c\
		get_next_line.c\
		ft_putendl_nbr.c\
		ft_putendl_nbr_fd.c\
		ft_power.c\
		ft_puterror.c\
		ft_print_bytes.c\
		ft_free_return.c\

SRC_DIR = srcs/
OBJ_DIR = objects/
INCLUDES = includes/

OBJ := $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

SRC := $(SRC:%=$(SRC_DIR)%)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) -R $(OBJ) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
