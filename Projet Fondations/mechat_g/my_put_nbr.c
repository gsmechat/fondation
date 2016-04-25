/*
** my_put_nbr.c for  in /Users/sofiane/Documents/ETNA/C/j05/my_put_nbr
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Fri Oct 23 14:16:36 2015 MECHAT Guillaume
** Last update Thu Apr 21 14:01:51 2016 MECHAT Guillaume
*/

#include <unistd.h>

void		my_putchar(char c);
void		my_putstr(char *str);

void		my_put_nbr(int n)
{
  if (n == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (n < 0)
	{
	  my_putchar('-');
	  n = n * -1;
	}
      if (n >= 10)
	my_put_nbr(n / 10);
      my_putchar((n % 10) + 48);
    }
}
