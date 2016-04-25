/*
** connection.c for  in /home/guillaume/Fondation
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Wed Apr  6 18:51:36 2016 MECHAT Guillaume
** Last update Thu Apr 21 13:58:42 2016 MECHAT Guillaume
*/

#include "header.h"

int			init_connection(char *ip, int port)
{
  t_sockaddr_serveur	serveur;
  int			my_socket;
  int			co;

  my_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (my_socket == -1)
    {
      error();
      return (EXIT_FAILURE);
    }
  serveur.sin_addr.s_addr = inet_addr(ip);
  serveur.sin_port        = htons(port);
  serveur.sin_family      = AF_INET;
  co = connect(my_socket, (t_sockaddr *) &serveur, sizeof(t_sockaddr));
  if (co == -1)
    {
      error();
      return (EXIT_FAILURE);
    }
  error();
  return (my_socket);
}
