# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:14:39 by pepaloma          #+#    #+#              #
#    Updated: 2025/01/15 01:38:41 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The Target Binary Program
NAME	= libft.a

# Directories
SRC_DIR		= src
INC_DIR		= inc
BUILDDIR	= obj

# Compiler, flags includes
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
HEADERS			= -I$(INC_DIR)

#-------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#-------------------------------------------------------------------------------

SRC		= $(wildcard src/*/*.c src/*.c)
OBJ		= $(SRC:.c=.o)

.PHONY: all re clean fclean
#.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -rf $(OBJ)
