NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf

SRCS = srcs/main.c srcs/build_stack.c srcs/errors.c srcs/push_swap_utils.c \
	srcs/operations.c srcs/sort_simple.c srcs/stack_operations.c \
	srcs/operations2.c srcs/operations3.c srcs/sort_medium.c \
	srcs/check_arg.c srcs/sort_complex.c \
	srcs/sort_adaptive.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
