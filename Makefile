NAME      = ex00
HEADER    = Account.hpp Bank.hpp
FLAGS     = -Wall -Wextra -Werror -std=c++98
OBJ_PATH  = ./objects
SRC       = Account.cpp Bank.cpp main.cpp
OBJ       = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

all: $(NAME)

$(OBJ_PATH)/%.o: %.cpp $(HEADER)
	mkdir -p $(OBJ_PATH)
	c++ $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all