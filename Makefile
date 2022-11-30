##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile generator
##

SRC =	\
		src/barrel_and_pit.c \
		src/check_map.c	 \
		src/descriptor.c \
		src/get_info.c	 \
		src/move_chara.c \
		src/my_sokoban.c \
		src/zevent.c	 \

NAME =	my_sokoban

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I include

all: 	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) -L lib/my -lmy -lncurses

clean:
	make clean -C lib/my/
	find . \( -name "#*#" -o -name "*~" -o -name "$(OBJ)" \) -delete

fclean:	clean
	make fclean -C lib/my
	find . \( -name  "vgcore.*" -o -name "*.log" -o -name "*.a" \) -delete
	find . \( -name "*.o" -o -name "$(NAME)" \) -delete

unit_test: fclean
		make unit_test -C tests/

run_test: unit_test
	tests/./unit_test

debug: CFLAGS += -g

debug: 	re

re:	fclean all
