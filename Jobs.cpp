//
// Created by os on 29.4.2021.
//

#include "Jobs.h"
//
// Created by os on 20.4.2021.
//
#include <stdio.h>
#include <string.h>
#include "Terminal_class.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>

using namespace std;
Jobs::Jobs() {
  process_counter = 0;
  sig_names[1] = "SIGHUP";
  sig_names[2] = "SIGINT";
  sig_names[3] = "SIGQUIT";
  sig_names[4] = "SIGILL";
  sig_names[5] = "SIGTRAP";
  sig_names[6] = "SIGABRT";
  sig_names[7] = "SIGBUS";
  sig_names[8] = "SIGFPE";
  sig_names[9] = "SIGKILL";
  sig_names[10] = "SIGUSR1";
  sig_names[11] = "SIGSEGV";
  sig_names[12] = "SIGUSR2";
  sig_names[13] = "SIGPIPE";
  sig_names[14] = "SIGALRM";
  sig_names[15] = "SIGTERM";
  sig_names[16] = "SIGSTKFLT";
  sig_names[17] = "SIGCHLD";
  sig_names[18] = "SIGCONT";
  sig_names[19] = "SIGSTOP";
  sig_names[20] = "SIGTSTP";
  sig_names[21] = "SIGTTIN";
  sig_names[22] = "SIGTTOU";
  sig_names[23] = "SIGURG";
  sig_names[24] = "SIGXCPU";
  sig_names[25] = "SIGXFSZ";
  sig_names[26] = "SIGVTALRM";
  sig_names[27] = "SIGPROF";
  sig_names[28] = "SIGWINCH";
  sig_names[29] = "SIGIO";
  sig_names[30] = "SIGPWR";
  sig_names[31] = "SIGSYS";
  sig_names[34] = "SIGRTMIN";
  sig_names[35] = "SIGRTMIN+1";
  sig_names[36] = "SIGRTMIN+2";
  sig_names[37] = "SIGRTMIN+3";
  sig_names[38] = "SIGRTMIN+4";
  sig_names[39] = "SIGRTMIN+5";
  sig_names[40] = "SIGRTMIN+6";
  sig_names[41] = "SIGRTMIN+7";
  sig_names[42] = "SIGRTMIN+8";
  sig_names[43] = "SIGRTMIN+9";
  sig_names[44] = "SIGRTMIN+10";
  sig_names[45] = "SIGRTMIN+11";
  sig_names[46] = "SIGRTMIN+12";
  sig_names[47] = "SIGRTMIN+13";
  sig_names[48] = "SIGRTMIN+14";
  sig_names[49] = "SIGRTMIN+15";
  sig_names[50] = "SIGRTMAX-14";
  sig_names[51] = "SIGRTMAX-13";
  sig_names[52] = "SIGRTMAX-12";
  sig_names[53] = "SIGRTMAX-11";
  sig_names[54] = "SIGRTMAX-10";
  sig_names[55] = "SIGRTMAX-9";
  sig_names[56] = "SIGRTMAX-8";
  sig_names[57] = "SIGRTMAX-7";
  sig_names[58] = "SIGRTMAX-6";
  sig_names[59] = "SIGRTMAX-5";
  sig_names[60] = "SIGRTMAX-4";
  sig_names[61] = "SIGRTMAX-3";
  sig_names[62] = "SIGRTMAX-2";
  sig_names[63] = "SIGRTMAX-1";
  sig_names[64] = "SIGRTMAX";
}

Jobs::~Jobs() {
/*  int cntr = (int)list_jobs.size();
 for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++,
    cntr--) {
   delete list_jobs.remove(itr);
  }
*/
}

void Jobs::add_job(string p_name, int p_pid) {
  process_counter++;
  system_clock::time_point p_time = std::chrono::system_clock::now();
//    list_jobs.push_back(SingleJob(process_counter, p_name, p_pid, p_time));
  SingleJob
      *my_single_job = new SingleJob(process_counter, p_name, p_pid, p_time);
  list_jobs.push_back(*my_single_job);
}

void Jobs::update_jobs_list() {
  list<SingleJob>::iterator itr = list_jobs.begin();
  while (itr != list_jobs.end()) {
    int sig = kill((itr->get_job_pid()), 0);
    if (0 == sig) {
      itr++;
    } else {
      itr->~SingleJob();
      list_jobs.erase(itr);
      itr = list_jobs.begin();
    }
  }
}

int Jobs::change_signal(int p_num, bool signal) {
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0;
       itr++, cntr--) {
    if (itr->get_proc_num() == p_num) {
      itr->change_single_sig(signal);
      return 0;
    }
  }
  return -1;
}

int Jobs::get_pid(int p_num) {
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0;
       itr++, cntr--) {
    if (itr->get_proc_num() == p_num) {
      return itr->get_job_pid();
    }
  }
  return -1;
}

int Jobs::get_num(int p_pid) {
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0;
       itr++, cntr--) {
    if (itr->get_job_pid() == p_pid) {
      return itr->get_proc_num();
    }
  }
  return -1;
}

int Jobs::get_last_pid() {
  return list_jobs.back().get_job_pid();
}

int Jobs::get_last_pnum() {
  return list_jobs.back().get_proc_num();
}

bool Jobs::is_job_stopped(int p_num) {
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0;
       itr++, cntr--) {
    if (itr->get_proc_num() == p_num) {
      return itr->get_job_signal();
    }
  }
  return -1;
}

int Jobs::last_job_stopped() {
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.end(); cntr > 0; itr--,
      cntr--) {
    if (itr->get_job_signal() == true) {
      return itr->get_proc_num();
    }
  }
  return -1;
}

void Jobs::print_all_jobs() {
  update_jobs_list();
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0;
       itr++, cntr--) {
    itr->print_single_job();
  }
}

void Jobs::kill_jobs() {
  update_jobs_list();
  int cntr_term = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr_term > 0;
       itr++, cntr_term--) {
    int pid = itr->SingleJob::get_job_pid();
    print_sent_signal(SIGTERM, pid);
    kill(pid, SIGTERM);

  }
  update_jobs_list();
  sleep(5);
  int cntr_kill = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr_kill > 0;
       itr++, cntr_kill--) {
    int pid = itr->SingleJob::get_job_pid();
    cout << " 5 sec passed ";
    print_sent_signal(SIGKILL, pid);
    kill(pid, SIGKILL);
  }
}

void Jobs::print_job_name(int p_num) {
  int cntr = (int) list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0;
       itr++, cntr--) {
    if (itr->get_proc_num() == p_num) {
      cout << itr->get_proc_name() << endl;
    }
  }
}

void Jobs::print_last_name() {
  cout << list_jobs.back().get_proc_name() << endl;
}

bool Jobs::jobs_q_empty() {
  return (list_jobs.size() > 0 ? false : true);
}

void Jobs::print_sent_signal(int signal, int pid) {
  if (((signal >= 1) && (signal <= 31)) || ((signal >= 34) && (signal <= 64))) {
    cout << "signal " << sig_names[signal] << " was sent to pid "
         << pid << endl;
  }
}