//
// Created by os on 29.4.2021.
//

#ifndef SMASH_JOBS_H
#define SMASH_JOBS_H

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include "Terminal_class.h"
#include "SingleJob.h"
#include <fstream>
#include <list>
#include <iterator>
#include <cstring>
#include <chrono>

#define MAX_LINE_SIZE 80
#define MAX_ARG 20

class Jobs {

  std::list<SingleJob> list_jobs;
  int process_counter;
  std::string sig_names[65];

 public:

  Jobs();

  ~Jobs();

  void add_job(std::string p_name, int p_pid);

  void update_jobs_list();

  int change_signal(int p_num, bool signal);

  int get_pid(int p_num);

  int get_last_pid();

  int get_last_pnum();

  bool is_job_stopped(int p_num);

  int get_num(int p_pid);

  int last_job_stopped();

  void print_all_jobs();

  void kill_jobs();

  void print_job_name(int p_num);

  void print_last_name();

  bool jobs_q_empty();

  void print_sent_signal(int signal, int pid);

  //bool is_pnum_exist(int p_num);

  void init_sig_name();

};

#endif //SMASH_JOBS_H
