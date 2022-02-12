##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## rule them all
##

FILE	=	sources/clicker_heroes	\

NAME	=	success_clicker

OBJ	=	$(FILE:.c=.o)

CFLAGS 	=	-g -Wextra -Wall

CSFMLFLAGS	=	-l csfml-window -l csfml-system -l csfml-audio -l csfml-graphics

all:	clicker

clicker:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS)
	@echo -e "\n\e[92mSuccessfully compiled\e[0m"

clean:
	rm -f *.o
	rm -f sources/*.o

fclean:	clean
	rm -f $(NAME)
	@echo -e "\n\e[92mSuccessfully cleaned\e[0m"

re:	fclean all

.PHONY: success_clicker clean fclean re all clicker
