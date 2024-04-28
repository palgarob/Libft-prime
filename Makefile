# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:14:39 by pepaloma          #+#    #+#              #
#    Updated: 2024/04/28 12:50:09 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= inc

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
VALGRIND_FLAGS	= -O0 -g

FILES	= $(notdir $(wildcard src/*.c))
SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

Y	= "\033[33m"
R	= "\033[31m"
G	= "\033[32m"
B	= "\033[34m"
M	= "\033[35m"
MB	= "\033[45m"
X	= "\033[0m"
UP	= "\033[A"
CUT	= "\033[K"
BL	= "\033[G"

.PHONY: all re clean fclean intro outro
.SILENT :

all : intro $(NAME) outro

$(NAME) : $(OBJ)
	echo $(UP)$(CUT)$(B)"Compiling source files: "$(G)"<<DONE>>"$(X)
	echo $(B)"Creating ft library..."$(X)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	echo $(UP)$(CUT)$(B)"Compiling source files: "$(Y)$@$(X)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(VALGRIND_FLAGS) -c $< -o $@

intro :
	echo $(MB)$(Y)"Making libft...\n"$(X)

outro :
	echo $(MB)$(Y)"Static library generated\n"$(X)

re : fclean all

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ_DIR)
