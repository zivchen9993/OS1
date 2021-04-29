//
// Created by os on 20.4.2021.
//

#ifndef SMASH_TERMINAL_CLASS_H
#define SMASH_TERMINAL_CLASS_H
#include <stddef.h>
#include <iostream>
#include <list>
#include <iterator>
#include <cstring>
#include <unistd.h>
class Terminal {

  std::list<std::string> list_last;
  std::list<std::list<std::string>> list_hist;
  int process_counter;


 public:

  /**
   * @brief Initiates an empty string
   */
  Terminal();


  ~Terminal();

  void push_hist(std::list<std::string> new_cmd);

  void switch_addr();

  void push_last_cwd(std::string last_cwd);

  const char *last_dir();

  void print_hist();
};
#endif


