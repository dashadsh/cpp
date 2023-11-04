NAME = PmergeMe

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# Define source files
SRCS = main.cpp PmergeMe.cpp

# Define object files based on source files
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

# Default target (build the executable)
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $@

# Clean up object files
clean:
	@$(RM) -r $(OBJ_DIR)

# Clean up object files and the executable
fclean: clean
	@$(RM) $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re