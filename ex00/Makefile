CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -Wconversion -Wshadow -Wpedantic -std=c++11 -g
RM = rm -f
NAME =  megaphone
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(SRC_DIR)/megaphone.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

BOLD = \033[1m
GREEN = \033[0;32m
RED = \033[0;31m
RESET= \033[0m

all: $(NAME)

$(NAME):$(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Compilation Success$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)$(BOLD)Removed Oject Files$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(BOLD)Removed Executable$(RESET)"

re: fclean all

.PHONY: all re fclean clean
