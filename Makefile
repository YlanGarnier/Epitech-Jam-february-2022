##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## rule them all
##

CC	=	gcc

FILE	=	sources/rect.c  \
		sources/clock.c \
		sources/sprite.c        \
		sources/pos.c   \
		sources/sound.c \
		sources/event.c \
		sources/display.c       \
		sources/window.c        \
		sources/usage.c \
		sources/main.c

NAME	=	success_clicker

OBJ	=	$(FILE:.c=.o)

VALGRIND	=	-g

CFLAGS	=	-Wextra -Wall

CSFMLFLAGS	=	-l csfml-window -l csfml-system -l csfml-audio -l csfml-graphics

CPPFLAGS	=	-I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CSFMLFLAGS)
	@echo -e "\n\e[92mSuccessfully compiled\e[0m"

clean:
	rm -f *.o
	rm -f sources/*.o

fclean:	clean
	rm -f $(NAME)
	@echo -e "\n\e[92mSuccessfully cleaned\e[0m"

re:	fclean all

.PHONY: success_clicker clean fclean re all clicker
