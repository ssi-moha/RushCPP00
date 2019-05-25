.PHONY: clean $(NAME) fclean re all

CC		=	clang++

FLAG	=	-Wall -Wextra -Werror

NAME    =	ponymorph

SRC     =   srcs/main.cpp		\
			srcs/Sorcerer.cpp	\
			srcs/Victim.cpp		\
			srcs/Peon.cpp		\
			srcs/Fish.cpp
            
OBJ     =	$(patsubst srcs/%.cpp,obj/%.o,$(SRC))

INCLUDE	=	includes/Sorcerer.hpp	\
			includes/Victim.hpp		\
			includes/Peon.hpp		\
			includes/Fish.hpp

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