NAME		= push_swap
CC			= clang
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS_LIST	= main.c init_options.c operations.c operations_2.c operations_3.c sort.c utils.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJ_LIST 	= $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
INC_DIR		= inc
SRCS_DIR	= srcs
OBJ_DIR		= obj
all : 		$(NAME)
$(NAME) :	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
$(OBJ_DIR) :
			@mkdir -p $@
clean :
			@$(RM) $(OBJ_DIR)
fclean : 	clean
			@$(RM) $(NAME)
re :			fclean all
.PHONY :	all clean fclean re
