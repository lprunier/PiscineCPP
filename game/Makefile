CCFLAGS= -Wall -Wextra -Werror

CMD=ft_retro

SRC=src/main.cpp \
		src/System.class.cpp \
		src/Utils/Utils.class.cpp \
		src/GameEntities/AEntity.class.cpp \
		src/GameEntities/Position.class.cpp \
		src/GameEntities/Shootzone.class.cpp \
		src/GameEntities/Shoot/Shoot.class.cpp \
		src/GameEntities/Player/Player.class.cpp \
		src/GameEntities/Enemy/Enemy.class.cpp \
		src/GameEntities/StaticObject/StaticObject.class.cpp \
		src/Engine/Engine.class.cpp \

COMPILER=clang++

OBJ=$(SRC:.cpp=.o)

.PHONY: all clean fclean

all: $(CMD)

$(CMD): $(OBJ)
	@$(COMPILER) -lncurses $^ -o $@  $(CCFLAGS)

%.o: %.cpp
	@$(COMPILER) -o $@ -c $< $(CCFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(CMD)

re: fclean all
