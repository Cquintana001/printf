LIB = ar rcs
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC =	libftprintf.c
OBJ = $(SRC:.c=.o)
INCLUDE = libftprintf.h


BONUSOBJ = $(BONUSSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus