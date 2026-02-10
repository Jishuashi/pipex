NAME = pipex

LIB = pipex.a

LIBFT = libft

MAIN = pipex.c

SRCS_P =	check_files.c		ft_free_all.c	create_tab.c	\
			get_nb_arg.c		check_pid.c		cmd_is_empty.c	\
			utils.c

OBJ_P = $(SRCS_P:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME): makelib
	cc $(CFLAGS) $(MAIN) $(LIB) -o $(NAME)

makelib: $(OBJ_P)
	$(MAKE) -C $(LIBFT) all
	cp libft/libft.a $(NAME).a
	ar rcs $(NAME).a $(OBJ_P)

clean:
	rm -f $(OBJ_P)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	$(MAKE) -C $(LIBFT) fclean

re: fclean clean all
	$(MAKE) -C $(LIBFT) re

.PHONY: all clean fclean re makelib