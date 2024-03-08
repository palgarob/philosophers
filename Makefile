# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 12:31:35 by pepaloma          #+#    #+#              #
#    Updated: 2024/01/31 14:06:48 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

NAME = $(BIN_DIR)/philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
# VALGRIND_FLAGS = -O0 -g
# las mierdas del sanitize

FILES = $(notdir $(wildcard src/*.c))
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	$(RM) $(BIN_DIR)

clean :
	$(RM) $(OBJ_DIR)

re : fclean all
