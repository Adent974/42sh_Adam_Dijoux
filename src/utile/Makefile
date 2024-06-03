##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## azdezfefze
##

NAME 	=	libmy.a

SRCS 	=	$(wildcard *.c)

OBJS 	= 	$(SRCS:.c=.o)

CFLAGS 	= 	-W -Wall -Wextra -Werror

INCLUDES = 	-I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	cp $(NAME) ../

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f ../libmy.a

re: fclean all
