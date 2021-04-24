/*	smash.c
main file. This file contains the main function of smash
*******************************************************************/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "commands.h"
#include "signals.h"
#define MAX_LINE_SIZE 80
#define MAXARGS 20
#define MAXPATHLEN 2048
#include <iostream>
#include <string.h>
#include "Terminal_class.h"

char* L_Fg_Cmd;
void* jobs = NULL; //This represents the list of jobs. Please change to a preferred type (e.g array of char*)
char lineSize[MAX_LINE_SIZE];
//**************************************************************************************
// function name: main
// Description: main function of smash. get command from user and calls command functions
//**************************************************************************************
int main(int argc, char *argv[])
{
  char cmdString[MAX_LINE_SIZE];


  //signal declaretions
  //NOTE: the signal handlers and the function/s that sets the handler should be found in siganls.c
  /* add your code here */

  /************************************/
  //NOTE: the signal handlers and the function/s that sets the handler should be found in siganls.c
  //set your signal handlers here
  /* add your code here */

  /************************************/

  /************************************/
  // Init globals
  char temp_path[MAXPATHLEN];
  char *last_cd_tmp = new char[MAXPATHLEN + 1];
  char *last_cd = new char[MAXPATHLEN + 1];

  L_Fg_Cmd =(char*)malloc(sizeof(char)*(MAX_LINE_SIZE+1));
  if (L_Fg_Cmd == NULL)
    exit (-1);
  L_Fg_Cmd[0] = '\0';
  Terminal *my_terminal = new Terminal();
  while (1)
  {
    printf("smash > ");
    fgets(lineSize, MAX_LINE_SIZE, stdin);
    strcpy(cmdString, lineSize);
    cmdString[strlen(lineSize)-1]='\0';
    // perform a complicated Command
    if(!ExeComp(lineSize)) continue;
    // background command
    if(!BgCmd(lineSize, jobs)) continue;
    // built in commands
    ExeCmd(jobs, lineSize, cmdString, *my_terminal);

    /* initialize for next line read*/
    lineSize[0]='\0';
    cmdString[0]='\0';
  }
  /**
   * remmeber!
   */
  //clear_memory;
  return 0;
}


