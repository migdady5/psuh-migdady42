NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
      operator1.c \
      operator2.c \
      operator3.c \
      disorder.c \
      stack_building/build_stack.c \
      stack_building/build_stack_utils.c \
      parsing/collect_tokens.c \
      parsing/collect_tokens_utils.c \
      parsing/error_utils.c \
      parsing/parse.c \
      parsing/validation.c

LIBFT_DIR = libft42
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re