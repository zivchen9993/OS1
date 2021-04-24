//
// Created by os on 20.4.2021.
//

#ifndef SMASH_TERMINAL_CLASS_H
#define SMASH_TERMINAL_CLASS_H
#include <stddef.h>
#include <iostream>
#include <list>
#include <iterator>

class Terminal {

  std::list<char *> list_last;
  std::list<const char *> list_hist;


 public:

  /**
   * @brief Initiates an empty string
   */
  Terminal();


  ~Terminal();

  void push_hist(const char *new_cmd);


  void push_last_cwd(char *last_cwd);

  void print_hist();
};
#endif


