CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++17 -I/opt/homebrew/include -g
LFLAGS = -L/opt/homebrew/lib -lespeak-ng
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin
SRC = main.cpp chat.cpp Buffer.cpp VoiceEngine.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
NAME = $(BIN_DIR)/prog
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
