# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 08:12:52 by lprunier          #+#    #+#              #
#    Updated: 2018/05/30 08:12:53 by lprunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = attack
CC = g++
FLG = -Wall -Wextra -Werror

SRC = FragTrap.cpp\
	main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLG) $(OBJ) -o $(NAME)

%.o: %.cpp
		@$(CC) -o $@ -c $< $(FLG)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
