# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 12:04:25 by jrinna            #+#    #+#              #
#    Updated: 2022/03/01 15:11:57 by jrinna           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#### LIST ####
LST_SRC := child.c cmd_init.c ft_error.c get_path.c path_init.c pipex.c split.c strdup.c strjoin.c utils.c 
LST_SRC_BNS := child_bonus.c cmd_init_bonus.c ft_error_bonus.c get_path_bonus.c path_init_bonus.c pipex_bonus.c split_bonus.c strdup_bonus.c strjoin_bonus.c utils_bonus.c 
LST_OBJ := $(LST_SRC:.c=.o)
LST_OBJ_BNS := $(LST_SRC_BNS:.c=.o)
LST_INC := pipex.h
LST_INC_BNS := pipex_bonus.h
#### LIST ####

#### DIRECTORY ####
DIR_SRC := source
DIR_SRC_BNS := source_bonus
DIR_OBJ := .object
DIR_OBJ_BNS := .object_bonus
DIR_INC := include
DIR_INC_BNS := include_bonus
#### DIRECTORY ####

#### COMPLETE PATH ####
SRC := $(addprefix $(DIR_SRC)/,$(LST_SRC))
SRC_BNS := $(addprefix $(DIR_SRC_BNS)/,$(LST_SRC_BNS))
OBJ := $(addprefix $(DIR_OBJ)/,$(LST_OBJ))
OBJ_BNS := $(addprefix $(DIR_OBJ_BNS)/,$(LST_OBJ_BNS))
INC := $(addprefix $(DIR_INC)/,$(LST_INC))
INC_BNS := $(addprefix $(DIR_INC_BNS)/,$(LST_INC_BNS))
#### COMPLETE PATH ####

#### OTHER ####
CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := pipex
NAME_BNS := pipex_bonus
#### OTHER ####

#### STANDARD RULE ####
all : $(NAME) $(NAME_BNS)

bonus : $(NAME_BNS)

re : fclean all

clean :
	rm -rf $(DIR_OBJ)
	rm -rf $(DIR_OBJ_BNS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BNS)
#### STANDARD RULE ####

#### CORE RULE ####
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) -g

$(NAME_BNS) : $(OBJ_BNS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BNS) -g

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(INC) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)

$(DIR_OBJ_BNS)/%.o : $(DIR_SRC_BNS)/%.c $(INC_BNS) Makefile | $(DIR_OBJ_BNS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC_BNS)

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ_BNS) :
	mkdir -p $(DIR_OBJ_BNS)
#### CORE RULE ####

#### CUSTOM RULE ####
#gmk :
# echo "LST_SRC += " > Source.mk
# find source -name "*.c" | sed 's#.*/#LST_SRC += #g' >> Source.mk
#### CUSTOM RULE ####

#### UTILS ####
.PHONY : all re clean fclean
#### UTILS ####
