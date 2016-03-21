/*
** my_putstr.c for  in /Users/sofiane/Documents/ETNA/C/j03/my_putstr
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Wed Oct 21 09:02:59 2015 MECHAT Guillaume
** Last update Wed Oct 21 09:27:52 2015 MECHAT Guillaume
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      i += 1;
    }
}
