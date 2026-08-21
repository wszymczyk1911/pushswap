NAME = checker

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft

PRINTF_DIR = ../ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf

SRCS = main.c build_stack.c errors.c push_swap_utils.c \
	operations.c stack_operations.c \
	operations2.c operations3.c \
	check_arg.c sort_stack.c

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
