CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
FW_PATH =  $(HOME)/Library/Frameworks
INCLUDES = -I src/ -I src/core/ -I src/modules/ -I src/display/  -I $(FW_PATH)/SFML.framework/Headers
RAW_SRC = main core/Logger
SRC = $(addprefix src/, $(addsuffix .cpp, $(RAW_SRC)))
OBJ = $(addprefix build/, $(addsuffix .o, $(RAW_SRC)))
LDLIBS = -lncurses -lsfml-system -lsfml-window  -lsfml-graphics  -F$(FW_PATH) -framework SFML -rpath $(FW_PATH) 
LDFLAGS =

EXEC = ft_gkrellm

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

./build/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	/bin/rm $(OBJ)

fclean:
	/bin/rm $(OBJ) $(EXEC)

re: fclean all

.PHONY = all clean fclean re