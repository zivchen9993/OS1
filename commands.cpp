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
#include <unistd.h>
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
int is_hist = strcmp(args[0], "history");
  if (is_hist) {
    list<string> list_command;
    for (int i = 0; i < num_arg + 1; i++) {
      string tmp(args[i]);
      list_command.push_back(tmp);
    }
    my_terminal.push_hist(list_command);
  }

//******************************************* our additions

/*************************************************/
// Built in Commands PLEASE NOTE NOT ALL REQUIRED
// ARE IN THIS CHAIN OF IF COMMANDS. PLEASE ADD
// MORE IF STATEMENTS AS REQUIRED
/*************************************************/
  if (!strcmp(cmd, "cd") ) {
    if (!(strcmp(args[1],"-"))){
      my_terminal.switch_addr();
      chdir(my_terminal.last_dir());
    } else {
      int ret_val_cdir = chdir(args[1]);
      if (ret_val_cdir == -1) {
        cerr <<"smash error:> No such file or directory" << endl;
      } else {
        string tmp(args[1]);
        my_terminal.push_last_cwd(tmp);
      }
    }
  }

  /*************************************************/
  /*else*/ if (!strcmp(cmd, "pwd"))
  {
    char temp[MAXPATHLEN];
    cout << ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") ) << endl;
  }

    /*************************************************/
    /**
     *change this!!!! to syscall
     */
  else if (!strcmp(cmd, "cp"))
  {
      std::ifstream src(args[1], std::ios::binary);
      std::ofstream dest(args[2], std::ios::binary);
      dest << src.rdbuf();
      if (src && dest){
        cout << args[1] << " has been copied to " << args[2] << endl;
      } else {
        /**
         * understand what error means!!!
         */
        cout << " error copy " << endl;
      }
  }
    /*************************************************/

  else if (!strcmp(cmd, "jobs"))
  {

  }
    /*************************************************/
  else if (!strcmp(cmd, "showpid"))
  {
    cout << "smash pid is " << getpid() << endl;
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
  else if (!strcmp(cmd, "diff"))
  {
    fstream f1, f2;
    char name[80], c1, c2;
    int flag=3;
    bool correct_files = true;

    strcpy(name, args[1]);
    f1.open(name,ios::in);
    if(!(f1)) {
      cerr << "1" << endl;
      correct_files = false;
    }
    strcpy(name, args[2]);
    f2.open(name,ios::in);
    if(!(f2) && correct_files) {
      cerr << "1" << endl;
      correct_files = false;
    }
      while(1 && correct_files){
        c1=f1.get();
        c2=f2.get();
        if(c1!=c2){
          flag=0;
          break;
        }
        if((c1==EOF)||(c2==EOF)){
          break;
        }
      }
      f1.close();
      f2.close();
      if(flag && correct_files) {
        cout << "0" << endl;
      } else if (correct_files && !(flag)){
        cout << "1" << endl;
      }
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

      perror("");

    case 0 :
      // Child Process
      setpgrp();

      // Add your code here (execute an external command)
      cout << ("t") << endl;
      execv(cmdString, args);

    default:
      // Add your code here

      cout << ("our default") << endl;
      /*
      your code
      */
  }
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

