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
#define SIG 2048

using namespace std;
Terminal::Terminal() {
  char temp[SIG];
  (getcwd(temp, sizeof(temp)));
  int i = 0;
  string init_cwd = "";
  while (temp[i]) {
    init_cwd = init_cwd + temp[i];
    i++;
  }
  list_last.push_front(init_cwd);
  list_last.push_front(init_cwd);
  list_last.resize(2);
  list_hist.resize(50);
}

Terminal::~Terminal() {
/*
    list_last.clear();
    list_hist.clear();
*/
}

void Terminal::push_hist(std::list<std::string> new_cmd) {
  list_hist.push_front(new_cmd);

}
void Terminal::switch_addr() {
  list_last.reverse();
}

const char *Terminal::last_dir() {
  return list_last.begin()->c_str();
}

void Terminal::push_last_cwd(std::string last_cwd) {
  list_last.push_front(last_cwd);
}
/**
 * check case of >= 50 commands
 *
 */
void Terminal::print_hist() {
  int cntr = (int) list_hist.size();
  for (list<list<string>>::iterator itr = list_hist.begin();
       cntr > 0;
       itr++, cntr--) {
    if (!(itr->empty())) {
      for (list<string>::iterator it = itr->begin(); it != itr->end(); it++) {
        cout << *it << " ";

      }
      cout << endl;
    }
  }
}


