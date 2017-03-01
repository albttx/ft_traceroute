# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: World 42  <world42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:55:19 by ale-batt          #+#    #+#              #
#*   Updated: 2017/03/01 13:40:39 by ale-batt         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	=	ft_traceroute

C_DIR	=	sources
O_DIR	=	.objs/
H_DIRS	=	includes

LIBFT	=	./libft
LIBNETWORK = ./libnetwork

CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
#FLAGS   +=  -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-parameter

C_DIRS	= $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$")
H_FILES = $(shell find includes -type f -follow -print | grep ".*\.h$$")
O_DIRS	= $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

# Verbose mode
V = 0
# debug mode
G = 0

LIB		+=	-L$(LIBNETWORK) -lnetwork
LIB		+=	-L$(LIBFT) -lft

INCLUDES =	-I./$(H_DIRS) -I$(LIBFT)/includes
INCLUDES +=	-I$(LIBNETWORK)/includes

C = \033[1;33m
U = $(C)[$(NAME)]----->\033[0m
SKIP = $(SKIP_$(V))
SKIP_1 :=
SKIP_0 := \033[A
W := o
BART := $(shell echo '$(O_FILES)'|wc -w|tr -d ' ')
BARC = $(words $W)$(eval W := o $W)
BAR = $(shell printf "%`expr $(BARC) '*' 100 / $(BART)`s" | tr ' ' '=')

#--------------------------------------------------------------------#

all		:	$(LIBFT)/libft.a $(LIBNETWORK)/libnetwork.a $(O_DIRS) $(NAME)

$(LIBFT)/libft.a:
			@make -C $(LIBFT)

$(LIBNETWORK)/libnetwork.a:
			@make -C $(LIBNETWORK)

$(O_DIRS):
			@mkdir -p $(O_DIR) $(O_DIRS)

$(NAME)	:	$(O_FILES)
			@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]"
			@echo "$(U)$(C)[BUILD]\033[0;32m"
			@$(CC) $(FLAGS) -o $(NAME) $(O_FILES) $(LIB)
			@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m\033[K"

$(O_DIR)%.o: $(C_DIR)%.c $(H_FILES)
			@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
			@echo "\033[0;32m"
			@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
			@printf "\033[1;31m[%-100s] %s%%\n" $(BAR) `echo $W|wc -w|tr -d ' '`
			@echo "$(SKIP)\033[A\033[2K$(SKIP)"
			
clean	:
			@rm -rf $(O_FILES)
			@echo "$(U)$(C)[CLEAN]\033[0;32m"
			@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"
#			@make -C $(LIBFT) clean
			@make -C $(LIBNETWORK) clean

fclean	:	clean
			@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
			@rm -rf $(NAME)
			@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"
#			@make -C $(LIBFT) fclean
			@make -C $(LIBNETWORK) fclean

lib		:
			@make -C $(LIBFT) re
			@make -C $(LIBNETWORK) re

re		:	fclean all

#------------------MY RULES ---------------------------------#

exe		:	all
			@./$(NAME)
norme	:
			norminette $(SRCS) $(HEADER)
gdb		:	all
			gdb $(NAME)

correc	:
			cat -e auteur
			norminette **/*.[ch]
