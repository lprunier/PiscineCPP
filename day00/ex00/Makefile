
NAME = megaphone
CC = g++
FLG = -Wall -Wextra -Werror

SRC = megaphone.cpp

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