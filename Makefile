NAME		= push_swap
BONUS NAME	= checker

CC 		= cc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= push_operations.c \
		  push_swap_bench.c \
		  push_swap_parsing.c \
		  push_swap_utils.c \
		  push_swap_utils_memory.c \
		  reverse_rotate_operations.c \
		  rotate_operations.c \
		  sorting_algorithms.c \
		  swap_operations.c
BONUS_SRCS	= checker.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

all:	$(NAME)

$(NAME): $(OBJS) $(LIIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft  -o $(NAME)

# Regola fondamentale richiesta per il bonus
bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
