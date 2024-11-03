# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 18:47:11 by mbany             #+#    #+#              #
#    Updated: 2024/11/03 14:09:43 by mbany            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable
NAME = push_swap

# Compiler and flags
CC = cc
FLAGS = -Wall -Werror -Wextra -Iincludes -g

# Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC_DIR = src/
SRC = operations_rotate.c operations_rrotate.c operations_push_swap.c \
	push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c \
	push_swap_utils4.c sort_for_3.c sort_4_to_9.c sort_4_more.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

# Object files
OBJ_DIR = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

# Colors & symbols
GREEN 	= 	\033[0;32m
CYAN	=	\033[0;36m
NC		= 	\033[0m
TICK	=	✅

define PRINT_LOADING
	@printf "$(CYAN)["
	@for i in $$(seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n"
endef

# Target for all
all: $(LIBFT) $(OBJS) $(NAME)

# Rule for the final executable
$(NAME): $(OBJS)
	@echo "$(CYAN)Compiling libs & program...$(NC)"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lXext -lX11 -lm
	@$(PRINT_LOADING)
	@echo "$(GREEN)Program compilation successful		$(TICK)$(NC)"

# Ensure the object directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build the library
$(LIBFT):
	@make -sC $(LIBFT_DIR)

# Rule to build object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	
# Full clean, including the executable and libft
fclean: clean
	@echo "$(CYAN)Cleaning up all files...$(NC)"
	@$(PRINT_LOADING)
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full clean completed $(TICK)$(NC)"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
