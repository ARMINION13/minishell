# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 10:00:24 by mmateo-t          #+#    #+#              #
#    Updated: 2022/01/24 12:32:53 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:= files/srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c) $(wildcard $(SRCS_DIR)builtins/*.c)
OBJS := $(SRCS:%.c=%.o)
NAME:= minishell
CC:= gcc
DEBUG_FLAG:= -g
CFLAGS:= -g #-Wall -Werror -Wextra
MACBOOK:= -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
SYS_LIB:= -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
LIBFT_PATH:= files/lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
RM := rm -rvf
UNAME_S := $(shell uname -s)
ifeq (${UNAME_S}, Darwin)
	LEAKS:= leaks minishell
else
	LEAKS:= valgrind --leak-check=full ./minishell
endif

all:	libft $(NAME) msg

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB) -lreadline

$(%.o): $(%.c)
			$(CC) -c $^ -o $@
					@echo "Creating objects"

libft:
			make bonus -C $(LIBFT_PATH)

leaks:	all
		$(LEAKS)

run:	all
		./minishell

clean:
			@echo "Removing objects"
					$(RM) $(OBJS)
fclean:
			make clean
			cd $(LIBFT_PATH) && $(MAKE) fclean
			$(RM) $(NAME)

msg:

	@echo	"																										"
	@echo	"\033[1;34m██████   ██████ █████ ██████   █████ █████  █████████  █████   █████ ██████████ █████       █████      \033[0m"
	@echo	"\033[1;34m░░██████ ██████ ░░███ ░░██████ ░░███ ░░███  ███░░░░░███░░███   ░░███ ░░███░░░░░█░░███       ░░███      \033[0m"
	@echo	"\033[1;34m░███░█████░███  ░███  ░███░███ ░███  ░███ ░███    ░░░  ░███    ░███  ░███  █ ░  ░███        ░███       \033[0m"
	@echo	"\033[1;34m░███░░███ ░███  ░███  ░███░░███░███  ░███ ░░█████████  ░███████████  ░██████    ░███        ░███       \033[0m"
	@echo	"\033[1;34m░███ ░░░  ░███  ░███  ░███ ░░██████  ░███  ░░░░░░░░███ ░███░░░░░███  ░███░░█    ░███        ░███       \033[0m"
	@echo	"\033[1;34m░███      ░███  ░███  ░███  ░░█████  ░███  ███    ░███ ░███    ░███  ░███ ░   █ ░███      █ ░███      █\033[0m"
	@echo	"\033[1;34m█████     █████ █████ █████  ░░█████ █████░░█████████  █████   █████ ██████████ ███████████ ███████████\033[0m"
	@echo	"\033[1;34m░░░░░     ░░░░░ ░░░░░ ░░░░░    ░░░░░ ░░░░░  ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░░░░░░░ ░░░░░░░░░░░\033[0m"
	@echo	"																										"
	@echo	"Usage -> \033[1;36m./minishell\033[0m"
	@echo	"																										"

re:
		make fclean all
			@echo "All files has been deleted and recompiled"

.PHONY: clean fclean all re objects debug libft msg run leaks
