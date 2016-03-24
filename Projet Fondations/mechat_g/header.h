/*
** header.h for  in /home/guillaume/Bachelor - Octobre_2018/TIC/Reload/LibParse
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Tue Feb  9 04:35:10 2016 MECHAT Guillaume
** Last update Thu Mar 24 09:53:41 2016 MECHAT Guillaume
*/

#ifndef HEADER_H_
# define HEADER_H_

#define SYNTAX_ERROR "Syntax Error: ./fondation --ip 192.168.1.1 --port 4242"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		my_strcmp(char *s1, char *s2);
void		my_putchar(char c);
void		my_putstr(char *str);


#endif
