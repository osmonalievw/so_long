NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
GNL_DIR = GetNextLine
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRC =        ft_atoi.c \
            ft_isalpha.c \
            ft_itoa.c \
            ft_memcpy.c \
            ft_putendl_fd.c \
            ft_strchr.c \
            ft_strlcpy.c \
            ft_strnstr.c \
            ft_tolower.c \
            ft_bzero.c \
            ft_isascii.c \
            ft_memmove.c \
            ft_putnbr_fd.c \
            ft_strdup.c \
            ft_strlen.c \
            ft_strrchr.c \
            ft_toupper.c \
            ft_calloc.c \
            ft_isdigit.c \
            ft_memchr.c \
            ft_memset.c \
            ft_putstr_fd.c \
            ft_strjoin.c \
            ft_strmapi.c \
            ft_strtrim.c \
            ft_isalnum.c \
            ft_isprint.c \
            ft_memcmp.c \
            ft_putchar_fd.c \
            ft_split.c \
            ft_strlcat.c \
            ft_strncmp.c \
            ft_substr.c \
			ft_striteri.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			$(GNL_DIR)/get_next_line_utils.c \
			$(GNL_DIR)/get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJ)
	cp $(PRINTF_LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re