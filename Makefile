# CXX = clang++
# CXXFLAGS = -Wall -Werror -Wextra

# FW_PATH =  framework

# INCLUDES = -I src/ -I src/core/ -I src/modules/ -I src/display/  -I $(FW_PATH)/SFML.framework/Headers
# RAW_SRC = main core/Logger
# SRC = $(addprefix src/, $(addsuffix .cpp, $(RAW_SRC)))
# OBJ = $(addprefix build/, $(addsuffix .o, $(RAW_SRC)))
# LDLIBS = -lncurses -lsfml-system -lsfml-window  -lsfml-graphics  -F$(FW_PATH) -framework SFML -rpath $(FW_PATH) 
# LDFLAGS =

# EXEC = ft_gkrellm

# all: $(EXEC)

# $(EXEC): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

# ./build/%.o: ./src/%.cpp
# 	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

# clean:
# 	/bin/rm $(OBJ)

# fclean:
# 	/bin/rm $(OBJ) $(EXEC)

# re: fclean all

# .PHONY = all clean fclean re


.PHONY: all, re, clean, fclean, lib

NAME = ocam

UNAME := $(shell uname)

FRAMEWORK_PATH = frameworks
SDL = SFML
SDL_INC = $(FRAMEWORK_PATH)/$(SDL).framework/Headers/
FLAG_SDL = -F$(FRAMEWORK_PATH) -framework $(SDL) -rpath $(FRAMEWORK_PATH)


CC = clang++
CC_FLAGS = -Wall -Werror -Wextra


SRC_NAME =	main.cpp

SRC_PATH =	src

INC_NAME =	

INC_PATH =	includes

INCLUDES =	-I$(INC_PATH) -I$(SDL_INC) -I src/core/

OBJ_NAME =	$(SRC_NAME:.cpp=.o)
OBJ_PATH =	obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

FLAG_LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: message $(NAME)

message:
	@make -q $(NAME) && echo "\033[1mLe projet est deja a jour\033[0m" || true

$(NAME): $(OBJ)
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	@ $(CC) $(CC_FLAGS) $(OPTI_FLAG) -o $@ $(OBJ) $(INCLUDES) $(FLAG_LIB) $(FLAG_SDL)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-20s\033[0m ✅\n" $< $@
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ_PATH)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
