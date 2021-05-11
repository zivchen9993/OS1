// signals.c
// contains signal handler funtions
// contains the function/s that set the signal handlers

/*******************************************/
/* Name: handler_cntlc
   Synopsis: handle the Control-C */
#include "signals.h"


extern Jobs my_jobs;


void handler_ctrl_z(int signum){

	if (current_pid != smash_pid){
		std::cerr << "change signal for ctrl z 1" << std::endl;
			int i = kill(current_pid,SIGTSTP);
			std::cerr << "change signal for ctrl z 2" << std::endl;
			if (!i){
				std::cerr << "change signal for ctrl z 3" << std::endl;
				int p_num = my_jobs.get_num(current_pid);
				my_jobs.change_signal(p_num, true);
			} else {
				std::cerr << "smash error: > Ctrl z kaput" << std::endl;
			}
		}
}


void handler_ctrl_c(int signum){

	if (current_pid != smash_pid){
		int i = kill(current_pid,SIGINT);
		if (i){
			std::cerr << "smash error: > Ctrl c kaput" << std::endl;
		}
	}

}
