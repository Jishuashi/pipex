NAME        = pipex
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

MAIN        = pipex.c
SRCS        = check_pid.c utils.c utils_2.c err_sleep.c utils_3.c
OBJS        = $(SRCS:.c=.o)

GREEN       = \033[0;32m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MAIN)
	@echo -e "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Cleaning executable and library..."
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re