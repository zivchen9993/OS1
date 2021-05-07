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
    printf("create job");
    process_counter = 0;
};

Jobs::~Jobs(){
/*
    list_last.clear();
    list_hist.clear();
*/
}

bool Jobs::add_job(string p_name, int p_pid){
    process_counter++;
    system_clock::time_point p_time = std::chrono::system_clock::now();
    SingleJob *my_single_job = new SingleJob(process_counter, p_name, p_pid, p_time);
    list_jobs.push_back(*my_single_job);
    printf("add job end");
}

void Jobs::remove_jobs() {
    printf("remove jobs before while loop");
    list<SingleJob>::iterator itr = list_jobs.begin();
    while (itr != list_jobs.end()) {
        printf("remove jobs in while loop");
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
/*
 * list<SingleJob>::iterator itr = list_jobs.begin();
while (itr != items.end())
{
    bool isActive = (*i)->update();
    if (!isActive)
    {
        items.erase(i++);  // alternatively, i = items.erase(i);
    }
    else
    {
        other_code_involving(*i);
        ++i;
    }
}
 */
int Jobs::change_signal(int p_num, bool signal){
    int cntr = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
        if (itr->get_proc_num() == p_num){
            itr->change_signal(signal);
            return 0;
        }
    }
    return -1;
}

void Jobs::print_jobs(){
    printf("before enter r_jobs");
    remove_jobs();
    int cntr = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
        itr->print_single_job();
    }
}


