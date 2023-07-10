# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:22:42 by dgoremyk          #+#    #+#              #
#    Updated: 2023/07/10 09:31:08 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

FLAGS = -Wall -Werror -Wextra -std=c++98 # -pedantic

CPP = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
	
# mkdir -p $(OBJ_DIR) creates the obj directory if it does not already exist, 
# and -p ensures that mkdir does not raise an error if the directory already exists.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) -c $(FLAGS) $< -o $@

fclean: clean
	@$(RM) $(NAME)
	
clean:
	@$(RM) $(OBJ)
	
re: fclean all

.PHONY: all clean fclean re