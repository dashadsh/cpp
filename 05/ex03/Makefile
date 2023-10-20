NAME = bureaucrat

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp Intern.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re