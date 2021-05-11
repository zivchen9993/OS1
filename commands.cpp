//		commands.c
//********************************************
#define MAXPATHLEN 2048
#define MAXCMDLEN 82
//********************************************
#include "commands.h"
//#include "Jobs.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <ctype.h>
//********************************************
// function name: ExeCmd
// Description: interperts and executes built-in commands
// Parameters: pointer to jobs, command string
// Returns: 0 - success,1 - failure
//**************************************************************************************
using namespace std;
int ExeCmd(Jobs& my_jobs, char* lineSize, char* cmdString, Terminal& my_terminal)
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
  else if ((!strcmp(cmd, "pwd")) && (args[1]==NULL))
  {
    char temp[MAXPATHLEN];

    cout << ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") ) << endl;
  }

    /*************************************************/
    /**
     *change this!!!! to syscall
     */
  else if (!strcmp(cmd, "cp") && (args[3]==NULL))
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
        perror("");
      }
  }
    /*************************************************/

  else if (!strcmp(cmd, "jobs") && (args[1]==NULL))
  {
      printf("going to print jobs");
      my_jobs.print_jobs();
  }
    /*************************************************/
  else if (!strcmp(cmd, "showpid") && (args[1]==NULL))
  {
    cout << "smash pid is " << getpid() << endl;
  }
    /*************************************************/
  else if (!strcmp(cmd, "fg") && (args[2]==NULL))
  {
    if (args[1]==NULL){
      int pnum_last = my_jobs.get_last_pnum();
      int pid_last = my_jobs.get_last_pid();
      kill(pid_last, SIGCONT);
      my_jobs.change_signal(pnum_last, false);
      current_pid = pid_last;
      cout << current_pid << endl;
      wait(&pid_last);
    } else {
      int j = 0;
      bool is_dig_job;
      while ((args[1][j])) {
        char letter = (args[1][j]);
        is_dig_job = std::isdigit(letter);
        if (!is_dig_job) {
          cout << " smash error:> kill " << args[1] <<
               " - job does not exist " << endl;
          return 0;
        }
        j++;
      }
      int pnum = atoi(args[1]);
      int pid = my_jobs.get_pid(pnum);
      kill(pid, SIGCONT);
      my_jobs.change_signal(pnum, false);
      current_pid = pid;
      wait(&pid);
    }
  }
    /*************************************************/
  else if (!strcmp(cmd, "bg") && (args[2]==NULL))
  {

    if (args[1]==NULL){
      int pnum_last = my_jobs.get_last_pnum();
      int pid_last = my_jobs.get_last_pid();
      if (my_jobs.get_last_signal()){
        my_jobs.print_last_name();
        kill(pid_last, SIGCONT);
        my_jobs.change_signal(pnum_last, false);
      } else {
        cout << " smash error:> kill " << args[1] <<
             " - job does not exist " << endl;
      }
    } else {
      int j = 0;
      bool is_dig_job;
      while ((args[1][j])) {
        char letter = (args[2][j]);
        is_dig_job = std::isdigit(letter);
        if (!is_dig_job) {
          cout << " smash error:> kill " << args[1] <<
               " - job does not exist " << endl;
          return 0;
        }
        j++;
      }
      int pnum = atoi(args[1]);
      int pid = my_jobs.get_pid(pnum);
      if (pid == -1){
        cout << " smash error:> process doesnt exist " << endl;
        return 0;
      }
      if (my_jobs.get_signal(pnum)){
        kill(pid, SIGCONT);
        my_jobs.change_signal(pnum, false);
      } else {
        cout << " smash error:> process isnt stopped " << endl;
      }
    }
  }
    /*************************************************/
  else if (!strcmp(cmd, "history") && (args[1]==NULL))
  {
    my_terminal.print_hist();
  }
    /*************************************************/
  else if (!strcmp(cmd, "diff") && (args[3]==NULL))
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
  else if (!strcmp(cmd, "kill") && (args[3]==NULL))
  {
    int j = 0;
    bool is_dig_job;
    while ((args[2][j])) {
      char letter = (args[2][j]);
      is_dig_job = std::isdigit(letter);
      if (!is_dig_job) {
        cout << " smash error:> kill " << args[2] <<
             " - job does not exist " << endl;
        return 0;
      }
      j++;
    }
    int job_num = atoi(args[2]);
    int needed_pid = my_jobs.get_pid(job_num);
        if (needed_pid == -1){
          cout << " smash error:> kill " << args[2] <<
                                    " - job does not exist " <<  endl;
          return 0;
        }
    int i = 1;
    bool is_dig_sig;
    while ((args[1][i]) != '\0'){
      char letter = args[1][i];
      is_dig_sig = std::isdigit(letter);
      if (!is_dig_sig){
        cout << " smash error:> kill " <<
             " - cannot send signal " <<  endl;
        return 0;
      }
      i++;
    }
    int sig_num = (-1 * atoi(args[1]));
    int retval = kill(needed_pid, sig_num);
    if (retval == 0){
      if ((sig_num == SIGTSTP) || (sig_num == SIGSTOP)){
        my_jobs.change_signal(job_num, true);
      }else if (sig_num == SIGCONT){
        my_jobs.change_signal(job_num, false);
      }
    }
    else if (retval == -1) {
      cout << " smash error:> kill " <<
                        " - cannot send signal " << endl;
    }
  }
    /*************************************************/
  else if (!strcmp(cmd, "quit") && (args[1]==NULL))
  {
	kill(getpid(),SIGTERM);
  }
    /*************************************************/
  else if (!strcmp(cmd, "quit") && !strcmp(args[1],"kill") && (args[2]==NULL))
  {
	my_jobs.kill_jobs();
	kill(getpid(),SIGTERM);
  }
    /*************************************************/
  else // external command
  {
      //if (ar)
      BgCmd(num_arg, args, cmdString, my_jobs);
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
void ExeExternal(char **args, char* cmdString, Jobs& my_jobs, bool bg_flag)
{
  // clear_memory;
    //ExeExternal(args, cmdString, my_jobs);
    int status;
    int pID = fork();
      if (pID != 0 && !bg_flag) {
    	  cerr << "waiting"  << endl;
    	  current_pid = getpid();
          wait(&status);
      }
   //   my_jobs.add_job(string(args[0]));
      switch(pID)
      {
          case -1:
              // Add your code here (error)

              perror("");

          case 0 :
              // Child Process
              setpgrp();
              // Add your code here (execute an external command)
              my_jobs.add_job(std::string("case 0 add me"), getpid());
              my_jobs.add_job(string(args[0]), pID);
              if ( execv(args[0], args) == -1){
                  cerr << "smash error: > \"" << cmdString << "\"" << endl;
                  exit(EXIT_FAILURE);
              }

          default:
              signal(SIGCHLD, SIG_IGN);
              my_jobs.add_job(string(args[0]), pID);
              // Add your code here

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
int BgCmd(int num_args, char **args, char* cmdString, Jobs& my_jobs)
{

  if (!strcmp(args[num_args], "&"))
  {
      args[num_args] = NULL;
      ExeExternal(args, cmdString, my_jobs, true);
  } else{
      ExeExternal(args, cmdString, my_jobs, false);
  }

  return -1;
}
