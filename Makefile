.PHONY: clean $(NAME) fclean re all

CC		=	clang++

FLAG	=	-Wall -Wextra -Werror -lncurses

NAME    =	R-Type

SRC     =   main.cpp						\
			Model/MovingObject/AMovingObject.cpp 		\
			Model/MovingObject/Enemy.cpp         		\
			Model/Object.cpp        		\
			Model/ObjectList.cpp    		\
			Model/Player.cpp        		\
			Vue/Render.cpp        		\
			Model/Vector.cpp				\
			Model/MovingObject/Spaceship.cpp

            
OBJ     =	$(patsubst srcs/%.cpp,obj/%.o,$(SRC))

			Model/MovingObject/AMovingObject.hpp			\
			Model/MovingObject/Enemy.hpp         		\
			Model/Object.hpp        		\
			Model/ObjectList.hpp    		\
			Model/Player.hpp        		\
			Vue/Render.hpp        		\
			Model/Vector.hpp				\
			Model/MovingObject/Spaceship.hpp


			

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