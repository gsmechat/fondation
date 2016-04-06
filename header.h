/*
** header.h for  in /home/guillaume/Bachelor - Octobre_2018/TIC/Reload/LibParse
** 
** Made by MECHAT Guillaume
** Login   <mechat_g@etna-alternance.net>
** 
** Started on  Tue Feb  9 04:35:10 2016 MECHAT Guillaume
** Last update Sat Apr  2 22:38:46 2016 MECHAT Guillaume
*/

#ifndef HEADER_H_
# define HEADER_H_

#define SYN_ERR "\033[31mError: ./fondation--ip 192.168.1.1 --port 4242\033[0m"
#define MAX_LENGTH_CHAR "\033[31mERROR: 250 lignes MAXIMUM\033[0m\n"
#define MSG_BYE "\033[34mAu revoir et a bientot ;)\033[0m\n"
#define PROMPT_CMD "\033[34mThe-Big-Quest\033[0m@localhost \033[32m~ \033[0m"
#define BUFFER_SIZE 1024
#define MAX_BUFFER 250

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

typedef struct sockaddr_in t_sockaddr_serveur;
typedef struct sockaddr t_sockaddr;
typedef struct in_addr t_in_addr;

int		my_strcmp(char *s1, char *s2);
void		my_putchar(char c);
void		my_putstr(char *str);
char		*readLine();
int		my_strlen(char *str);
void		my_send(int sock, char * str);
int		my_recv(int sock);
int		handle_data(char *buff);
int		write_log(char *txt, int id);
void		error();
int		error_log(char *txt);
int		my_getnbr(char *str);

#endif
