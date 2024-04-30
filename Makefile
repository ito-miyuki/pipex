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

BONUS_OBJS	= $(BONUS:%.c=$(BUILD_DIR)/%.o)

CC	= cc

#remove -g flag before submitting
#remove -fsanitize=address flag before submitting
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR)

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus:	$(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f *.o

re: fclean all

.PHONY: bonus all clean fclean re
