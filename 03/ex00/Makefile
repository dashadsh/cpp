# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:24:27 by dgoremyk          #+#    #+#              #
#    Updated: 2023/07/04 14:24:28 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap
SRCS = main.cpp ClapTrap.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: all clean re