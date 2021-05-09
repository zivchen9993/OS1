//
// Created by os on 29.4.2021.
//

#include "SingleJob.h"
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
#define MAXPATHLEN 2048


using namespace std;

SingleJob::SingleJob(int p_num, string p_name, int p_pid, system_clock::time_point p_time){

    proc_num = p_num;
    proc_name = p_name;
    pid = p_pid;
    start_time = p_time;

    is_stopped = false;
};

SingleJob::~SingleJob(){
/*
    list_last.clear();
    list_hist.clear();
*/
}

int SingleJob::get_proc_num(){
    return proc_num;
}

std::string SingleJob::get_proc_name(){
  return proc_name;
}

void SingleJob::change_single_sig(bool signal){
    is_stopped = signal;
}

void SingleJob::print_single_job(){
    system_clock::time_point curr_time = std::chrono::system_clock::now();
    seconds elap_time = std::chrono::duration_cast<std::chrono::seconds>(curr_time - start_time);
    cout << "[" <<proc_num << "] " << proc_name << " " << pid << " " << elap_time.count() << " secs " << (is_stopped ? "(stopped)" : "") << endl;
}

int SingleJob::get_job_pid(){
    return pid;
}

bool SingleJob::get_job_signal(){
  return is_stopped;
}