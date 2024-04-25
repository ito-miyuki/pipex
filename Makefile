NAME = 	pipex

LIBFT_DIR	= ./libft
LIBFT	= ./libft/libft.a

#SRCS	= main.c

BONUS	=	main_bonus.c \
			get_path.c \
			init_pipex.c \
			create_pipes.c \
			clean_up.c \
			call_execve.c \
			start_process.c \
			ft_join_strings.c \
			first_child_process.c \
			last_child_process.c \
			middle_child_process.c \
			close_pipes.c \
			wait_processes.c \
			split_space_quote.c \
			print_execve_error.c \
			ft_exit.c

#OBJS	= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

CC	= cc

#remove -g flag before submitting
#remove -fsanitize=address flag before submitting
#add -Werror
CFLAGS = -g -fsanitize=address -Wall -Wextra -I/libft

RM	= rm -rf

all:	$(NAME)

#$(NAME): $(LIBFT) $(OBJS)
#	$(NAME) $(OBJS)

$(NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#bonus:	$(BONUS_OBJS)
#	$(NAME) $(BONUS_OBJS)

#clean:
#	$(RM) $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re