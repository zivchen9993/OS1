// signals.c
// contains signal handler funtions
// contains the function/s that set the signal handlers

/*******************************************/
/* Name: handler_cntlc
   Synopsis: handle the Control-C */
#include "signals.h"
using namespace std;
void handler_ctrl_z(int signum) {
  cout << "signal SIGTSTP was sent to pid " << current_pid << endl;
  if (current_pid != smash_pid) {
    int i = kill(current_pid, SIGTSTP);
    if (!i) {
      int p_num = my_jobs->get_num(current_pid);
      my_jobs->change_signal(p_num, true);
    } else {
      cerr << "smash error: > Ctrl z kaput" << endl;
    }
  }
}

void handler_ctrl_c(int signum) {
  cout << "signal SIGINT was sent to pid " << current_pid << endl;
  if (current_pid != smash_pid) {
    int i = kill(current_pid, SIGINT);
    if (i) {
      cerr << "smash error: > Ctrl c kaput" << endl;
    }
  }
}
