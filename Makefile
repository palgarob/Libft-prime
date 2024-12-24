# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:14:39 by pepaloma          #+#    #+#              #
#    Updated: 2024/12/24 12:56:19 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC_DIR	= src
INC_DIR	= inc

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
HEADERS			= -I$(INC_DIR)

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
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)
