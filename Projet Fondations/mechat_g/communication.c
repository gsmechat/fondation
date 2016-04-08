/*
** communication.c for  in /home/guillaume/Fondation
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Wed Apr  6 18:49:29 2016 MECHAT Guillaume
** Last update Wed Apr  6 19:06:57 2016 MECHAT Guillaume
*/

#include "header.h"

int		command(int my_socket)
{
  char		*input;

  while (42)
    {
      my_putstr(PROMPT_CMD);
      input = readLine();
      if (my_strlen(input) >= MAX_BUFFER)
        {
          my_putstr(MAX_LENGTH_CHAR);
        }
      else if (my_strcmp(input, "/bye") == 0)
        {
          my_putstr(MSG_BYE);
          free(input);
          close(my_socket);
          return (EXIT_SUCCESS);
        }
      else
        {
          //my_putchar('\n');
          write(my_socket, input, my_strlen(input));
          receive_data(my_socket);
	}
      free(input);
    }
  return (EXIT_SUCCESS);
}

int		handle_data(char *buff)
{
  int		i;

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

void		send_data(int sock, char * str)
{
  write(sock, str, my_strlen(str));
}

int		receive_data(int sock)
{
  char		*buffer;
  int		len;
  int		done;

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
