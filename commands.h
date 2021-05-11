#ifndef _COMMANDS_H
#define _COMMANDS_H
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Terminal_class.h"
#include <fstream>
#include "Jobs.h"
#include <chrono>

#define MAX_LINE_SIZE 80
#define MAX_ARG 20
extern int current_pid;
typedef enum { FALSE, TRUE } bool_;

int BgCmd(int num_args, char **args, char *cmdString, Jobs &my_jobs);

int ExeCmd(Jobs &jobs, char *lineSize, char *cmdString, Terminal &my_terminal);

void ExeExternal(char **args, char *cmdString, Jobs &my_jobs, bool bg_flag);
#endif

