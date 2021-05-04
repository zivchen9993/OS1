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
/*
    list_last.clear();
    list_hist.clear();
*/
}

bool Jobs::add_job(string p_name){
    process_counter++;
    list_jobs.push_back(SingleJob(process_counter, p_name));
}

bool Jobs::remove_job(int p_num){
    int cntr = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
        if (itr->get_proc_num() == p_num){
           // itr->~SingleJob();
            list_jobs.erase(itr);
            return true;
        }
    }
    return false;
}

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
    int cntr = (int)list_jobs.size();
    for (list<SingleJob>::iterator itr = list_jobs.begin(); cntr > 0; itr++, cntr--) {
        itr->print_single_job();
    }
}


