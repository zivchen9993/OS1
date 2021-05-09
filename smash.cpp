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
#include "Jobs.h"

char* L_Fg_Cmd;

//void* jobs = NULL; //This represents the list of jobs. Please change to a preferred type (e.g array of char*)
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
  Jobs *my_jobs = new Jobs();
  my_jobs->add_job(std::string("add me"), getpid());
  while (true)
  {
    std::cerr << "smash > ";
    fgets(lineSize, MAX_LINE_SIZE, stdin);
    strcpy(cmdString, lineSize);
    cmdString[strlen(lineSize)-1]='\0';
    // background command
    //if(!BgCmd(lineSize, *my_jobs)) continue;
    // built in commands BgCmd(int num_args, char *args[MAX_ARG], char* cmdString, Jobs& my_jobs)
    ExeCmd(*my_jobs, lineSize, cmdString, *my_terminal);

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


