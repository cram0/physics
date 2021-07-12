NAME        =       physics

SRC         =       $(shell find . -name '*.cpp')

OBJ         =       $(SRC:.cpp=.o)

CXXFLAGS    +=      -Wall
CXXFLAGS    +=      -Wextra
CXXFLAGS    +=      -Wno-unused-parameter

CXXFLAGS    +=      -I./include -I./lib

all         :       $(NAME)

$(NAME)     :       $(OBJ)
					g++ -o $(NAME) $(OBJ) -g -O0 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean       :
					find . -name "*.o" -type f -delete
					find . -name "vgcore.*" -type f -delete

fclean      :       clean
					rm -f $(NAME)

re          :       fclean all


launch      :       re clean
					./$(NAME)

vg          :       re clean
					valgrind ./$(NAME)