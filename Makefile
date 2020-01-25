CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra --std=c++98 -F$(HOME)/Library/Frameworks

INCLUDES = -I src/ -I src/core/ -I src/modules/ -I src/display/ -I src/display/ncurses -I src/display/ncurses/widgets -I src/display/sfml

RAW_SRC = main										\
		core/Logger									\
		modules/HostnameModule						\
		display/ncurses/CursesDisplay				\
		display/sfml/SFMLDisplay					\
		core/Monitor								\
		modules/OSInfoModule						\
		modules/CpuUsageModule						\
		modules/CpuInfoModule						\
		modules/DateModule							\
		modules/RamModule							\
		core/Config


SRC = $(addprefix src/, $(addsuffix .cpp, $(RAW_SRC)))
OBJ = $(addprefix build/, $(addsuffix .o, $(RAW_SRC)))
LDLIBS = -lncurses
LDFLAGS = -framework SFML -framework sfml-graphics -framework sfml-window -framework sfml-audio -framework sfml-system

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
