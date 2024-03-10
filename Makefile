NAME	= $(BIN_DIR)/philo

BIN_DIR	= bin
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= inc

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
SANITIZE_FLAGS	= -O1 -g -fsanitize=thread
# VALGRIND_FLAGS = -O0 -g

FILES	=	clear_lunch.c \
			getset.c \
			init_lunch.c \
			main.c \
			monitors.c \
			parse_args.c \
			philo.c \
			routine.c \
			utils.c
SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) -I$(INC_DIR) -c $< -o $@

fclean : clean
	$(RM) $(BIN_DIR)

clean :
	$(RM) $(OBJ_DIR)

re : fclean all
