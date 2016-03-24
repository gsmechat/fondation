/*
** my_strlen.c for  in /Users/sofiane/Documents/ETNA/C/j03/my_strlen
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Wed Oct 21 09:31:38 2015 MECHAT Guillaume
** Last update Wed Oct 21 09:41:32 2015 MECHAT Guillaume
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      i += 1;
    }
  return (i);
}
