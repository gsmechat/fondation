##
## Makefile for  in /Users/sofiane/Documents/ETNA/C
## 
## Made by MECHAT Guillaume
## Login   <mechat_g@etna-alternance.net>
## 
## Started on  Sat Oct 24 23:10:00 2015 MECHAT Guillaume
## Last update Wed Apr  6 19:00:17 2016 MECHAT Guillaume
##

CC	=	gcc
NAME	=	fondation
SRC	=	main.c		\
		my_putchar.c	\
		my_putstr.c	\
		my_strcmp.c	\
		readline.c	\
		my_strlen.c	\
		my_getnbr.c	\
		communication.c	\
		connection.c	\

CFLAG	=	-W -Wall -Werror
OBJS	=	$(SRC:%.c=%.o)
RM	=	rm -rf

$(NAME):	$(OBJS)
		$(CC) $(SRC) -o $(NAME) $(CFLAG)

all:		$(NAME)

clean:
		$(RM) *.o log.txt

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
