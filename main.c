/*
** main.c for  in /home/guillaume/mechat_g
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Mon Mar 21 11:18:11 2016 MECHAT Guillaume
** Last update Thu Mar 24 12:53:13 2016 MECHAT Guillaume
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

int handle_command(int sock)
{
  char *cmd;

  while (42)
    {
      my_putstr("Enter command:\n");
      my_putstr("> ");

      cmd = readLine();

      if (my_strlen(cmd) > 250)
	my_putstr("Command too long (250 characters max allowed)\n");
      else if (my_strlen(cmd) > 0)
	{
	  if (my_strcmp("/bye", cmd) == 0)
	    {
	      my_putstr("Bye bye !\n");
	      close(sock);
	      return (EXIT_SUCCESS);
	    }

	  my_send(sock, cmd);
	  my_recv(sock);
	}
      my_bzero(cmd);
    }
}

int my_send(int sock, char * str)
{
  int result;
  result = write(sock, str, my_strlen(str));

  return (result);
}

int my_recv(int sock)
{
  char *buffer;
  int len;
  int done;

  buffer = malloc(BUFFER_SIZE);

  while ((len = read(sock, buffer, BUFFER_SIZE)) > 0)
    {
      done = handle_data(buffer);
      if (done == 1)
	return (EXIT_SUCCESS);
    }

  free(buffer);

  return (EXIT_SUCCESS);
}

int handle_data(char *buffer)
{
  int i;
  for (i = 0; i < my_strlen(buffer); i++) {
    if (buffer[i] == '\n')
      {
	my_putchar('\n');
	return (1);
      }
    if (buffer[i] == '#')
      {
	my_putchar('\n');
      }
    my_putchar(buffer[i]);
  }

  return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
  if ((argv[1] != 0 && my_strcmp(argv[1], "--ip") == 0)
      && (argv[3] != 0 && my_strcmp(argv[3], "--port") == 0) && argc > 4)
    {
      int i;
      int sock;
      i = atoi(argv[4]);
      sock = init_connection(argv[2], i);
      if (sock == 0)
	return (0);
      else
	{
	  handle_command(sock);
	  close(sock);
	}
    }
  else
    my_putstr(SYNTAX_ERROR);
  return (0);
}
