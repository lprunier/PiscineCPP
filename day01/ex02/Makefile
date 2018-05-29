# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 09:12:56 by lprunier          #+#    #+#              #
#    Updated: 2018/05/29 09:12:58 by lprunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies
CC = g++
FLG = -Wall -Wextra -Werror

SRC = Zombie.cpp\
	ZombieEvent.cpp\
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
