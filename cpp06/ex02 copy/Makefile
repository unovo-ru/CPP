NAME = ex02
LIBRARY = lib
CPP = c++
INCLUDES = include
FLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
C98 = -std=c++98

SRC = src/main.cpp src/Base.cpp src/A.cpp src/B.cpp src/C.cpp

OBJ = $(SRC:src/%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(LIBRARY)
	$(CPP) $(FLAGS) $(C98) $(LIBRARY) -o $(NAME)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CPP) $(FLAGS) $(C98) -c $< -o $@

$(LIBRARY): $(OBJ)
	ar rcs $(LIBRARY) $(OBJ)

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBRARY)

re: fclean all

.PHONY: all clean fclean re library
