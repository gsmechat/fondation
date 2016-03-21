/*
** my_putchar.c for  in /Users/sofiane/Documents/ETNA/C
**
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
**
** Started on  Mon Oct 19 09:44:53 2015 MECHAT Guillaume
** Last update Mon Oct 19 11:47:07 2015 MECHAT Guillaume
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
