CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -Wconversion -Wshadow -Wpedantic -std=c++11 -g

NAME = ./phonebook

RM = rm -rf

OBJ_DIR = obj

SRC_DIR = src

SRCS = $(SRC_DIR)/Phonebook.cpp\
$(SRC_DIR)/Contact.cpp\
$(SRC_DIR)/main.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

BOLD = \033[1m
GREEN = \033[0;32m
RED = \033[0;31m
RESET= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Compilation Success$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "$(RED)$(BOLD)Removed Oject Files$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)$(BOLD)Removed Executable$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
