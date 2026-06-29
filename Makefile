NAME		= push_swap
BONUS_NAME	= checker

CC 		= cc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= main.c \
 		  push_operations.c \
 		  push_swap_bench.c \
 		  push_swap_parsing.c \
 		  push_swap_utils_1.c \
 		  push_swap_utils_memory.c \
 		  reverse_rotate_operations.c \
 		  rotate_operations.c \
 		  swap_operations.c \
		  simple_sort.c \
		  medium_sort.c \
		  radix_sort.c
BONUS_SRCS	= checker.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

OBJS_NOMAIN	= $(filter-out main.o,$(OBJS))

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Regola fondamentale richiesta per il bonus
bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(OBJS_NOMAIN) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_NOMAIN) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

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
