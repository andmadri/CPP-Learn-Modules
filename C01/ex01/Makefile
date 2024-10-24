NAME = zombie

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++11

RM = rm -rf

SRCS = $(SRC_DIR)/main.cpp\
$(SRC_DIR)/zombieHorde.cpp\
$(SRC_DIR)/Zombie.cpp

SRC_DIR = src

OBJ_DIR = obj

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):$(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re
