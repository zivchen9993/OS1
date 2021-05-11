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
Jobs::Jobs(){
    process_counter = 0;
};

Jobs::~Jobs(){
/*  int cntr = (int)list_jobs.size();
 for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++,
    cntr--) {
   delete list_jobs.remove(itr);
  }
*/
}

bool Jobs::add_job(string p_name, int p_pid){
    process_counter++;
    system_clock::time_point p_time = std::chrono::system_clock::now();
//    list_jobs.push_back(SingleJob(process_counter, p_name, p_pid, p_time));
    SingleJob *my_single_job = new SingleJob(process_counter, p_name, p_pid, p_time);
    list_jobs.push_back(*my_single_job);
}

void Jobs::remove_jobs() {
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

int Jobs::change_signal(int p_num, bool signal){
    int cntr = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
        if (itr->get_proc_num() == p_num){
            itr->change_single_sig(signal);
            return 0;
        }
    }
    return -1;
}

int Jobs::get_pid(int p_num){
  int cntr = (int)list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
    if (itr->get_proc_num() == p_num){
      return itr->get_job_pid();
    }
  }
  return -1;
}

int Jobs::get_num(int p_pid){
  int cntr = (int)list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
    if (itr->get_proc_num() == p_pid){
      return itr->get_proc_num();
    }
  }
  return -1;
}

int Jobs::get_last_pid(){
  return list_jobs.back().get_job_pid();
}

int Jobs::get_last_pnum(){
  return list_jobs.back().get_proc_num();
}

bool Jobs::get_signal(int p_num){
  int cntr = (int)list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
    if (itr->get_proc_num() == p_num){
      return itr->get_job_signal();
    }
  }
  return -1;
}

bool Jobs::get_last_signal(){
  return list_jobs.back().get_job_signal();
}

void Jobs::print_jobs(){
    remove_jobs();
    int cntr = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
        itr->print_single_job();
    }
}

void Jobs::kill_jobs(){
    int cntr_term = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr_term > 0; itr++, cntr_term--) {
        kill(itr->SingleJob::get_job_pid(), SIGTERM);
    }
    remove_jobs();
    sleep(5);
    int cntr_kill = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr_kill > 0; itr++, cntr_kill--) {
    	kill(itr->SingleJob::get_job_pid(), SIGKILL);
    }
}

void Jobs::print_job_name(int p_num){
  int cntr = (int)list_jobs.size();
  for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
    if (itr->get_proc_num() == p_num){
      cout << itr->get_proc_name() << endl;
    }
  }
}

void Jobs::print_last_name(){
      cout << list_jobs.back().get_proc_name() << endl;
}


