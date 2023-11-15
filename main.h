#ifndef MAIN_H
#define MAIN_H

#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

extern char **environ;


int pos_num(char *str);
int _atoi(char *str);
char *_itoa(int num);
int s_len(char *str);
int s_cmp(char *str1, char *str2);
char *s_dup(const char *str);
char *s_copy(char *x, char *y);
char *s_cat(char *x, char *y);

char **tok_command(char *line);
char *read_command(void);
char *g_env(char *val);
char *g_pth(char *commond);

int exe_command(char **com, char **av, int ln);
void ch_process(char **com, char *pth);

void b_exit(char **com, char **av, int *stat, int ln);
void b_env(char **com, int *stat);
void bulitin_com(char **com, char **av, int *stat, int ln);
int bulitin(char *com);

void p_err(char *val, char *com, int ln);
void exit_err(char **com, char **av, int ln);
#endif
