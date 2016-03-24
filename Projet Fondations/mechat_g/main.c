/*
** main.c for  in /home/guillaume/mechat_g
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Mon Mar 21 11:18:11 2016 MECHAT Guillaume
** Last update Thu Mar 24 11:38:17 2016 MECHAT Guillaume
*/

#include "header.h"

int init_connection(char *ip, int port)
{
  int sock;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1)
    {
      my_putstr("KO");
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }

  t_sockaddr_in_client d;
  d.sin_addr.s_addr = inet_addr(ip);
  d.sin_port        = htons(port);
  d.sin_family      = AF_INET;

  int connection;

  connection = connect(sock, (t_sockaddr *) &d, sizeof(t_sockaddr));
  if (connection == -1)
    {
      perror(__FUNCTION__);
      return(EXIT_FAILURE);
    }
  return (sock);
}




int	main(int argc, char **argv)
{
  if ((argv[1] != 0 && my_strcmp(argv[1], "--ip") == 0)
      && (argv[3] != 0 && my_strcmp(argv[3], "--port") == 0) && argc > 4)
    {
      int i;
      i = atoi(argv[4]);
      init_connection(argv[2], i);
    }
  else
    my_putstr(SYNTAX_ERROR);
  return (0);
}
