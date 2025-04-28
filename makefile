# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 17:30:07 by raosmona          #+#    #+#              #
#    Updated: 2025/04/28 15:41:30 by raosmona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === Output binary name ===
NAME = so_long

# === Project directories ===
SRCS_DIR = main
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

# === Source files ===
SRCS = \
	$(SRCS_DIR)/main.c \
	$(SRCS_DIR)/so_long.c \
	$(SRCS_DIR)/so_long_func.c \
	$(SRCS_DIR)/render.c \
	$(SRCS_DIR)/window_func.c \
	$(SRCS_DIR)/texture_func.c \
	$(SRCS_DIR)/check.c \
	$(SRCS_DIR)/err_func.c \


OBJS = $(SRCS:.c=.o)

# === Libraries ===
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

# === Compiler and flags ===
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(SRCS_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)
LIBS = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -lm

# === Colors ===
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

# === Rules ===

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)[ MLX ]$(RESET) 🔧 Building MiniLibX..."
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "$(BLUE)[ FT_PRINTF ]$(RESET) 🔧 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)[ LINK ]$(RESET) 🚀 Linking executable..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) -o $(NAME) $(LIBS)
	@echo "$(GREEN)✔ Done:$(RESET) $(NAME) is ready!"


%.o: %.c
	@echo "$(YELLOW)[ COMPILE ]$(RESET) 🔧 $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)🧼 Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "$(RED)🗑️ Binary removed$(RESET)"

re: fclean all

install_mlx:
	@echo "$(BLUE)[INSTALL] Checking if minilibx-linux is already installed...$(RESET)"
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "$(GREEN)[SUCCESS] minilibx-linux is already installed!$(RESET)"; \
	else \
		echo "$(BLUE)[INSTALL] Cloning minilibx-linux...$(RESET)"; \
		git clone https://github.com/42paris/minilibx-linux.git; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)[SUCCESS] minilibx-linux successfully cloned!$(RESET)"; \
		else \
			echo "$(RED)[ERROR] Failed to clone minilibx-linux!$(RESET)"; \
		fi; \
	fi


.PHONY: all clean fclean re
