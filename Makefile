# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:14:39 by pepaloma          #+#    #+#              #
#    Updated: 2024/03/09 11:06:12 by pepaloma         ###   ########.fr        #
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

.PHONY: all re clean fclean
#.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(VALGRIND_FLAGS) -c $< -o $@

re : fclean all

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ_DIR)
