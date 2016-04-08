/*
** main.c for  in /home/guillaume/mechat_g
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Mon Mar 21 11:18:11 2016 MECHAT Guillaume
** Last update Wed Apr  6 19:08:42 2016 MECHAT Guillaume
*/

#include "header.h"
int		init_connection(char *ip, int port);
int		command(int my_socket);

/*void	error()
{
  char	*action;

  action = "Connection";
  perror(__FUNCTION__);
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
}*/


int		main(int argc, char **argv)
{
  int		i;
  int		sock;
  
  if ((argv[1] != 0 && my_strcmp(argv[1], "--ip") == 0)
      && (argv[3] != 0 && my_strcmp(argv[3], "--port") == 0) && argc > 4)
    {
      i = my_getnbr(argv[4]);
      sock = init_connection(argv[2], i);
      if (sock == 1)
	return (EXIT_SUCCESS);
      else
	{
	  command(sock);
	  close(sock);
	}
    }
  else
    my_putstr(SYN_ERR);
  return (EXIT_SUCCESS);
}
