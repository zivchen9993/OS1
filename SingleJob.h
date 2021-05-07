//
// Created by os on 29.4.2021.
//

#ifndef SMASH_SINGLEJOB_H
#define SMASH_SINGLEJOB_H
//
// Created by os on 29.4.2021.
//

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Terminal_class.h"
#include <fstream>
#include <list>
#include <iterator>
#include <cstring>
#include <chrono>
#include <ctime>

#define MAX_LINE_SIZE 80
#define MAX_ARG 20

using namespace std::chrono;

class SingleJob {

    int proc_num;
    std::string proc_name;
    int pid;
    system_clock::time_point start_time;
    bool is_stopped;

public:

   // SingleJob();

    SingleJob(int p_num, std::string p_name, int p_pid,  system_clock::time_point p_time);

    ~SingleJob();

    int get_proc_num();

    void change_signal(bool signal);

    void print_single_job();

    int get_job_pid();

};


#endif //SMASH_SINGLEJOB_H
