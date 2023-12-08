#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

#define DELIM " \t\n"

extern char **environ;

/* bltin.c */
int builtin(char *cmd);
void builtin_handle(char **cmd, char **argv, int *sta, int idx);

/* env.c */
char *_getenv(char *name);
void print_env(char **cmd, int *sta);
char *_getpath(char *cmd);

/* exit.c */
void exitsh(char **cmd, char **argv, int *s, int index);

/* get-exe.c */
int exec(char **command, char **argv, int idx);
char *get_line(void);

/* str.c */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/* str1.c */
int print_char(char c);
int print_str(char *str);
void str_rev(char *str, int len);
int _atoi(char *s);
char *_atoi_rev(int n);

/* tkn.c */
char **tkn(char *line);

/* tools.c */
void free_modified(char **arr);
void _perror(char *prog, char *cmd, int ctr);
int is_positive(char *str);

#endif
