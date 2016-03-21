/*
** my_strcmp.c for  in /Users/sofiane/Documents/ETNA/C/j04/my_strcmp
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Thu Oct 22 13:57:32 2015 MECHAT Guillaume
** Last update Thu Oct 22 21:55:13 2015 MECHAT Guillaume
*/

int	my_strcmp(char *s1, char *s2)
{
  if (s1 && s2)
    {
      while (*s1 == *s2)
	{
	  if (*s1 == '\0')
	    return (0);
	  s1++;
	  s2++;
	}
      if (*s1 > *s2)
	return (1);
      else
	return (-1);
    }
  return (0);
}
