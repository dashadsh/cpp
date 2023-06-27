NAME = phonebook
SRCS = contact.cpp phoneBook.cpp main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 # conform to c++98
# SIC! - not all function are caught,  please refer to 
# https://learn.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-header-files?view=msvc-170

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: all clean re