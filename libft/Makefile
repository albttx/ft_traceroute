# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: world42 <world42@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:57:53 by world42           #+#    #+#              #
#*   Updated: 2017/02/21 14:20:46 by ale-batt         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NNAME = ft

INCLUDE = ./includes
SOURCES = ./sources
OBJECT  = ./.objs

TAGS = etags --declarations
CFLAGS = -Wall -Werror -Wextra 
# -ansi -pedantic
C = \033[1;34m

# make [[OPT]] [[MODE]=1] ...]
# ex: make re V=1
# Verbose mode
V = 0
# debug mode
G = 0
# create emacs TAGS file
T = 0
# N = 0

SILENCE_1 :=
SILENCE_0 :=@
SKIP_1 :=
SKIP_0 := \033[A
STAT_1 := displaystat
STAT_0 :=
NORC_1 := norme
NORC_0 :=
DEBUG_1 := -g
DEBUG_0 :=
TAG_1 := tag
TAG_0 :=
TAG = $(TAG_$(T))
STAT = $(STAT_$(S))
SKIP = $(SKIP_$(V))
DEBUG = $(DEBUG_$(G))
SILENCE = $(SILENCE_$(V))
NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf

FILES = $(shell find $(SOURCES) -type f -follow | sed "s/.\/[^\/]*//")

OF=$(FILES:%.c=%.o)
O_FILES = $(addprefix $(OBJECT), $(OF))
C_FILES = $(addprefix $(SOURCES), $(FILES))

DIRS = $(shell find $(SOURCES) -type d -follow -print | sed "s/.\/[^\/]*//" | cut -d'/' -f2)
O_DIRS= $(addprefix $(OBJECT)/, $(DIRS))

SRCS = $(shell find $(SOURCES) -type f -follow -exec basename {} \;)

H_FILES = $(shell find $(INCLUDE) -type f -follow -print | grep ".*\.h$$")

W := o
BART := $(shell echo '$(O_FILES)'|wc -w|tr -d ' ')
BARC = $(words $W)$(eval W := o $W)
BAR = $(shell printf "%`expr $(BARC) '*' 100 / $(BART)`s" | tr ' ' '=')

U = $(C)[$(NAME)]----->\033[0m

.PHONY: all clean fclean re tag norme

all: $(O_DIRS) $(NORC) $(NAME) $(STAT) $(TAG)

$(O_DIRS):
	@mkdir -p  $(OBJECT) $(O_DIRS)

$(NAME): $(O_FILES) $(H_FILES)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	@$(LIB) $(NAME) $(O_FILES)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m\033[K"

$(OBJECT)/%.o: $(SOURCES)/%.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	@$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@ -I$(INCLUDE) 
	@printf "\033[1;31m[%-100s] %s%%\n" $(BAR) `echo $W|wc -w|tr -d ' '`
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJECT)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

tag:
	@echo "$(U)$(C)[TAGING]\033[0;32m"
	$(SILENCE)$(TAGS) $(C_FILES)
	@echo "$(SKIP)$(U)$(C)[TAGING:\033[1;32m DONE$(C)]\033[0m"

norme:
	@norminette $(C_FILES) $(H_FILES)
