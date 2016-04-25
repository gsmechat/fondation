/*
** log.c for  in /home/guillaume/Fondation
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Wed Apr  6 19:50:13 2016 MECHAT Guillaume
** Last update Thu Apr 21 14:00:24 2016 MECHAT Guillaume
*/

#include "header.h"

void	error()
{
  char	*action;

  action = "Connection à Fondation";
  perror(action);
  error_log(action);
}

int	error_log(char *txt)
{
  int	id;

  id = open("log.txt", O_APPEND|O_CREAT|O_RDWR, 777);
  write_log(txt, id);
  write_log(": ", id);
  write_log(strerror(errno), id);
  write_log("\n", id);
  close(id);
  return (0);
}

int	write_log(char *txt, int id)
{
  write(id, txt, my_strlen(txt));
  return (0);
}
