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
#include "Terminal_class.h"
#include "SingleJob.h"
#include "Jobs.h"
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

public:

    Jobs();

    ~Jobs();

    bool add_job(std::string p_name);

    bool remove_job(int p_num);

    int change_signal(int p_num, bool signal);

    void print_jobs();

};


#endif //SMASH_JOBS_H
