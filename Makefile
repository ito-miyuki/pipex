NAME = 	pipex

BUILD_DIR = build
LIBFT_DIR	= ./libft
LIBFT	= ./libft/libft.a

SRCS	=	main.c \
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
			print_execve_error.c \
			ft_exit.c \
			ft_isspace.c \
			ft_parse_cmd.c

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
			print_execve_error.c \
			ft_exit.c \
			ft_isspace.c \
			ft_parse_cmd.c

OBJS	= $(SRCS:%.c=$(BUILD_DIR)/%.o)

BONUS_OBJS	= $(BUNOS:%.c=$(BUILD_DIR)/%.o)

CC	= cc

#remove -g flag before submitting
#remove -fsanitize=address flag before submitting
CFLAGS = -g -Wall -Wextra -Werror -I/libft

RM	= rm -rf

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
