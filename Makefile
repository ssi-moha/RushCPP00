.PHONY: clean $(NAME) fclean re all

CC		=	clang++

FLAG	=	-Wall -Wextra -Werror -lncurses

NAME    =	R-Type

SRC     =   main.cpp						\
			Controller/Game.cpp				\
			Model/AMovingObject.cpp 		\
			Model/Enemy.cpp         		\
			Model/Object.cpp        		\
			Model/ObjectList.cpp    		\
			Model/Player.cpp        		\
			Model/Render.cpp        		\
			Model/Vector.cpp				\
			Model/Spaceship.cpp

            
OBJ     =	$(patsubst srcs/%.cpp,obj/%.o,$(SRC))

INCLUDE	=	Controller/Game.hpp				\
			Model/AMovingObject.hpp			\
			Model/Enemy.hpp         		\
			Model/Object.hpp        		\
			Model/ObjectList.hpp    		\
			Model/Player.hpp        		\
			Model/Render.hpp        		\
			Model/Vector.hpp				\
			Model/Spaceship.hpp


			

all: $(NAME) 

$(NAME): $(OBJ) $(INCLUDE)
		$(CC) $(FLAG) $(SRC) -o $(NAME)

obj/%.o: srcs/%.cpp
		mkdir -p obj
		$(CC) $(FLAG) -c $< -o $@

clean:
		/bin/rm -rf obj/

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

test: re
		./$(NAME)

all: $(NAME)