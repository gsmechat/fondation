##
## Makefile for  in /Users/sofiane/Documents/ETNA/C
## 
## Made by MECHAT Guillaume
## Login   <mechat_g@etna-alternance.net>
## 
## Started on  Sat Oct 24 23:10:00 2015 MECHAT Guillaume
## Last update Sat Apr  2 00:23:00 2016 MECHAT Guillaume
##

CC	=	gcc
NAME	=	fondation
SRC	=	main.c		\
		my_putchar.c	\
		my_putstr.c	\
		my_strcmp.c	\
		readline.c	\
		my_strlen.c	\
		my_put_nbr.c	\

CFLAG	=	-W -Wall -Werror
OBJS	=	$(SRC:%.c=%.o)
RM	=	rm -rf

$(NAME):	$(OBJS)
		$(CC) $(SRC) -o $(NAME) $(CFLAG)

all:		$(NAME)

clean:
		$(RM) *.o

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
