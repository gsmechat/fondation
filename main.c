/*
** main.c for  in /home/guillaume/mechat_g
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Mon Mar 21 11:18:11 2016 MECHAT Guillaume
** Last update Sat Apr  2 01:06:06 2016 MECHAT Guillaume
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
      perror(__FUNCTION__);
      return (-1);
    }
  serveur.sin_addr.s_addr = inet_addr(ip);
  serveur.sin_port        = htons(port);
  serveur.sin_family      = AF_INET;
  co = connect(my_socket, (t_sockaddr *) &serveur, sizeof(t_sockaddr));
  if (co == -1)
    {
      perror(__FUNCTION__);
      return(EXIT_FAILURE);
    }
  return (my_socket);
}

int handle_command(int my_socket)
{
  char *input;
  
  while (42)
    {
      my_putstr(PROMPT_CMD);
      input = readLine();
      my_put_nbr(my_strlen(input));
      if (my_strcmp(input, "/bye") == 0)
	{
	  my_putstr(MSG_BYE);
	  free(input);
	  close(my_socket);
	  return (EXIT_SUCCESS);
	}
      if (my_strlen(input) >= MAX_BUFFER)
	{
	  my_putstr(MAX_LENGTH_CHAR);
	}
      //else if (my_strlen(input) > 0)
      else
	{
	  my_putchar('\n');
	  //my_send(my_socket, input);
	  write(my_socket, input, my_strlen(input));
	  my_recv(my_socket);
	}
      free(input);
    }
}

void my_send(int sock, char * str)
{
  write(sock, str, my_strlen(str));
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
      free(buffer);
      if (done == 1)
	return (EXIT_SUCCESS);
    }

  free(buffer);

  return (EXIT_SUCCESS);
}

int handle_data(char *buff)
{
  int i;

  for (i = 0; i < my_strlen(buff); i++) {
    if (buff[i] == '\n')
      {
	my_putchar('\n');
	return (1);
      }
    my_putchar(buff[i]);
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
    my_putstr(SYN_ERR);
  return (0);
}
