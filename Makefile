##
## Makefile for  in /Users/sofiane/Documents/ETNA/C
## 
## Made by MECHAT Guillaume
## Login   <mechat_g@etna-alternance.net>
## 
## Started on  Sat Oct 24 23:10:00 2015 MECHAT Guillaume
## Last update Mon Mar 21 11:21:32 2016 MECHAT Guillaume
##

CC	=	gcc
NAME	=	fondation
SRC	=	main.c		\
		my_putchar.c	\
		my_putstr.c	\
		my_strcmp.c	\

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
