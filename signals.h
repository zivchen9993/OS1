#ifndef _SIGS_H
#define _SIGS_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "Jobs.h"
#include <iostream>
extern Jobs *my_jobs;
extern int smash_pid;
extern int current_pid;
void handler_ctrl_c(int signum);
void handler_ctrl_z(int signum);
#endif

