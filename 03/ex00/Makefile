# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:24:27 by dgoremyk          #+#    #+#              #
#    Updated: 2023/07/08 19:22:47 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRCS = main.cpp ClapTrap.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

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