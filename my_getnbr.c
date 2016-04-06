/*
** my_getnbr.c for  in /Users/sofiane/Documents/etna/C/j05/my_getnbr
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Sat Oct 24 17:06:47 2015 MECHAT Guillaume
** Last update Sat Apr  2 22:18:13 2016 MECHAT Guillaume
*/

int	my_getnbr(char *str)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while ((*str == '+') || (*str == '-'))
    {
      if (*str == '-')
	{
	  i = -i;
	}
      str++;
    }
  while ((*str >= '0' && *str <= '9'))
    {
      j = (j * 10) + (*str - '0');
      str++;
    }
  return (j * i);
}
