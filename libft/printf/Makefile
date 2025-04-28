NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		for_char.c \
		for_digit.c \
		for_string.c \
		for_ptr.c \
		for_hex.c

OBJ = $(SRC:.c=.o)

# === Colors ===
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)[ AR ]$(RESET) Creating archive $(NAME)..."
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	@echo "$(YELLOW)[ COMPILE ]$(RESET) Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[ CLEAN ]$(RESET) Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[ FCLEAN ]$(RESET) Library removed"

re: fclean all

.PHONY: all clean fclean re
