CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -g

INCLUDES = -I src/ -I src/core/ -I src/modules/
RAW_SRC = main core/Logger
SRC = $(addprefix src/, $(addsuffix .cpp, $(RAW_SRC)))
OBJ = $(addprefix build/, $(addsuffix .o, $(RAW_SRC)))
LDLIBS = -lncurses

EXEC = ft_gkrellm

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDLIBS)

./build/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	/bin/rm $(OBJ)

fclean:
	/bin/rm $(OBJ) $(EXEC)

re: fclean all

.PHONY = all clean fclean re