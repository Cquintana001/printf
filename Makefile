# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 17:45:50 by caquinta          #+#    #+#              #
#    Updated: 2022/06/11 12:06:22 by caquinta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a

SRC = libftprintf.c\
	  printchar.c\
	  printinteger.c\
	  printstring.c\
	  printunsignedinteger.c\
	  ft_printf_xxp.c\
	  

OBJ = $(SRC:.c=.o)

INCLUDES = ft_printf.h

CC = gcc 
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
MAKE = make

all: $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $(SRC)  

$(NAME): $(OBJ) $(INCLUDES)
	$(MAKE) -C	Libft
	cp Libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ) 

 

clean:
	$(RM) $(OBJ)  

fclean: clean
	$(RM) $(NAME) libft.a


re: fclean all

.PHONY: all clean fclean re bonus