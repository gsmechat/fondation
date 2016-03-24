/*
** readline.c for  in /home/guillaume/mechat_g
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Thu Mar 24 11:40:33 2016 MECHAT Guillaume
** Last update Thu Mar 24 12:44:12 2016 MECHAT Guillaume
*/

#include <stdlib.h>
#include <unistd.h>

char		*readLine()
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof(*buff) * (255 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 255)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}
