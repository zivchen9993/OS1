//		commands.c
//********************************************
#define MAXPATHLEN 2048
#define MAXCMDLEN 82
//********************************************
#include "commands.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
//********************************************
// function name: ExeCmd
// Description: interperts and executes built-in commands
// Parameters: pointer to jobs, command string
// Returns: 0 - success,1 - failure
//**************************************************************************************
using namespace std;
int ExeCmd(void* jobs, char* lineSize, char* cmdString, Terminal& my_terminal)
{
  char* cmd;
  char* args[MAX_ARG];
  char pwd[MAX_LINE_SIZE];
  char* delimiters = " \t\n";
  int i = 0, num_arg = 0;
  bool illegal_cmd = FALSE; // illegal command
  cmd = strtok(lineSize, delimiters);
  if (cmd == NULL)
    return 0;
  args[0] = cmd;
  for (i=1; i<MAX_ARG; i++)
  {
    args[i] = strtok(NULL, delimiters);
    if (args[i] != NULL)
      num_arg++;

  }

  if (strcmp(args[0], "history")) {
    /*char *new_command = new char[MAXCMDLEN];
    int cntr = 0;
    for (i=0; i<num_arg; i++){
         if (args[i] != NULL){
           strcpy((new_command + cntr), args[i]);
           cntr += (strlen(args[i]) + 1);
           strcpy((new_command + (cntr-1)), " ");
         }
     }
    strcpy((new_command + (cntr + 1)), "\0");
    my_terminal.push_hist(new_command);
  }
  */
    /*vector<string> list_command;
    for (int i = 0; i < num_arg + 1; i++) {
      string tmp(args[i]);
      list_command.push_back(tmp);
    }
    for (auto it = list_command.cbegin(); it != list_command.cend(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }*/
    //my_terminal.push_hist(new_command);
  }
//******************************************* our additions
  bool last_cd_exist = false;
/*************************************************/
// Built in Commands PLEASE NOTE NOT ALL REQUIRED
// ARE IN THIS CHAIN OF IF COMMANDS. PLEASE ADD
// MORE IF STATEMENTS AS REQUIRED
/*************************************************/
  /*if (!strcmp(cmd, "cd") ) {

      if ((args[1] == "-") && (last_cd_exist));
      {
          int ret_val_cdir = chdir(last_cd);
          if (ret_val_cdir == -1) {
              cout << "\"" << cmdString << "\" " << "- No such file or directory" << endl;
          }


          strcpy(last_cd_tmp, temp_path);


          if (ret_val_cdir == -1) {
              cout << "\"" << cmdString << "\" " << "- No such file or directory" << endl;
          } else {

              strcpy(last_cd, temp_path);
              last_cd_exist = true;
          }
      }
  }
  */
  /*************************************************/
  /*else*/ if (!strcmp(cmd, "pwd"))
  {
    char temp[MAXPATHLEN];
    cout << ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") ) << endl;
  }

    /*************************************************/
  else if (!strcmp(cmd, "mkdir"))
  {

  }
    /*************************************************/

  else if (!strcmp(cmd, "jobs"))
  {

  }
    /*************************************************/
  else if (!strcmp(cmd, "showpid"))
  {

  }
    /*************************************************/
  else if (!strcmp(cmd, "fg"))
  {

  }
    /*************************************************/
  else if (!strcmp(cmd, "bg"))
  {

  }
    /*************************************************/
  else if (!strcmp(cmd, "history"))
  {
    my_terminal.print_hist();
  }
    /*************************************************/
  else if (!strcmp(cmd, "quit"))
  {

  }
    /*************************************************/
  else // external command
  {
    // clear_memory;
    ExeExternal(args, cmdString);
    return 0;
  }
  if (illegal_cmd == TRUE)
  {
    printf("smash error: > \"%s\"\n", cmdString);
    return 1;
  }
  return 0;
}
//**************************************************************************************
// function name: ExeExternal
// Description: executes external command
// Parameters: external command arguments, external command string
// Returns: void
//**************************************************************************************
void ExeExternal(char *args[MAX_ARG], char* cmdString)
{
  int pID;
  switch(pID = fork())
  {
    case -1:
      // Add your code here (error)

      /*
      your code
      */
    case 0 :
      // Child Process
      setpgrp();

      // Add your code here (execute an external command)

      /*
      your code
      */

    default:
      // Add your code here

      cout << ("our default") << endl;
      /*
      your code
      */
  }
}
//**************************************************************************************
// function name: ExeComp
// Description: executes complicated command
// Parameters: command string
// Returns: 0- if complicated -1- if not
//**************************************************************************************
int ExeComp(char* lineSize)
{
  char ExtCmd[MAX_LINE_SIZE+2];
  char *args[MAX_ARG];
  if ((strstr(lineSize, "|")) || (strstr(lineSize, "<")) || (strstr(lineSize, ">")) || (strstr(lineSize, "*")) || (strstr(lineSize, "?")) || (strstr(lineSize, ">>")) || (strstr(lineSize, "|&")))
  {
    // Add your code here (execute a complicated command)

    /*
    your code
    */
  }
  return -1;
}
//**************************************************************************************
// function name: BgCmd
// Description: if command is in background, insert the command to jobs
// Parameters: command string, pointer to jobs
// Returns: 0- BG command -1- if not
//**************************************************************************************
int BgCmd(char* lineSize, void* jobs)
{

  char* Command;
  char* delimiters = " \t\n";
  char *args[MAX_ARG];
  if (lineSize[strlen(lineSize)-2] == '&')
  {
    lineSize[strlen(lineSize)-2] = '\0';
    // Add your code here (execute a in the background)

    /*
    your code
    */

  }
  return -1;
}

/*
 * char *new_data = new char[strlen(str.data)+1];
    strcpy(new_data,str.data);
    new_data[strlen(str.data)] = '\0';
    this->data = new_data;
    this->length = str.length;
 */