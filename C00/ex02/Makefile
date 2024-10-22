CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -Wconversion -Wshadow -Wpedantic -std=c++11 -g

NAME = account

RM = rm -rf

OBJ_DIR = obj

SRC_DIR = src

SRCS = $(SRC_DIR)/Account.cpp\
$(SRC_DIR)/tests.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:

	$(RM) $(OBJS)

fclean: clean

	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean