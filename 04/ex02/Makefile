# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:24:45 by dgoremyk          #+#    #+#              #
#    Updated: 2023/07/06 16:52:09 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism
SRCS = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
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