##
## EPITECH PROJECT, 2024
## B-PSU-200-RUN-2-1-42sh-nicolas.samy
## File description:
## Makefile
##

MAIN = main.c

EXEC = 42sh

SRC = $(wildcard src/*.c)

LIB = ./src/utile

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIB:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror

TFLAGS = -W -Wall -Wextra -Werror -lcriterion --coverage

all: makelib $(OBJ)
	gcc $(MAIN) $(OBJ) -o $(EXEC) $(CFLAGS) -L $(LIB) -lmy -Iinclude -g3

makelib:
	cd $(LIB) && $(MAKE)

clean:
	rm -f $(OBJ)
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf unit_test
	cd $(LIB) && $(MAKE) clean

fclean: clean
	rm -f $(EXEC)
	cd $(LIB) && $(MAKE) fclean

re: fclean all

tests_run : all
	gcc $(SRC) -L $(LIB) -lmy -Linclude tests/test.c $(TFLAGS) -o unit_test
			./unit_test
