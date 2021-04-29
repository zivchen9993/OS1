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

SingleJob::SingleJob(int p_num, string p_name, int p_pid){

    proc_num = p_num;
    proc_name = p_name;
    pid = p_pid;
    system_clock::time_point start_time = std::chrono::system_clock::now();
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

void SingleJob::change_signal(bool signal){
    is_stopped = signal;
}

void SingleJob::print_single_job(){
    system_clock::time_point curr_time = std::chrono::system_clock::now();
    seconds elap_time = std::chrono::duration_cast<std::chrono::seconds>(curr_time - start_time);
    cout << proc_num << " " << proc_name << " " << pid << " " << elap_time.count() << " " << (is_stopped ? "(stopped)" : "") << endl;
}
