NAME = 	pipex

BUILD_DIR = build
BONUS_BUILD_DIR = build_bonus
SRCS_DIR = src
BONUS_SRCS_DIR = src_bonus

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

BONUS_SRCS	=	main_bonus.c \
			get_path_bonus.c \
			init_pipex_bonus.c \
			create_pipes_bonus.c \
			clean_up_bonus.c \
			call_execve_bonus.c \
			start_process_bonus.c \
			ft_join_strings_bonus.c \
			first_child_process_bonus.c \
			last_child_process_bonus.c \
			middle_child_process_bonus.c \
			close_pipes_bonus.c \
			wait_processes_bonus.c \
			print_execve_error_bonus.c \
			ft_exit_bonus.c \
			ft_isspace_bonus.c \
			ft_parse_cmd_bonus.c

OBJS	= $(SRCS:%.c=$(BUILD_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=$(BONUS_BUILD_DIR)/%.o)

CC	= cc

#remove -g flag before submitting
#remove -fsanitize=address flag before submitting
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR)

YELLOW = \033[0;33m
END = \033[0m

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)$(NAME) created mandatory ✅ ${END}"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_BUILD_DIR)/%.o: $(BONUS_SRCS_DIR)/%.c
	@mkdir -p $(BONUS_BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJS)
	touch .bonus
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)$(NAME) created bonus ✅ $(END)"

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(BUILD_DIR) $(BONUS_BUILD_DIR)
	rm -f .bonus

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f *.bonus

re: fclean all

.PHONY: bonus all clean fclean re
