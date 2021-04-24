//
// Created by os on 20.4.2021.
//

#include "Terminal_class.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>

Terminal::Terminal(){
  using namespace std;
  list_last.resize(1);
  list_hist.resize(50);

};

Terminal::~Terminal(){
/*
    list_last.clear();
    list_hist.clear();
*/
}

void Terminal::push_hist(const char *new_cmd){
  list_hist.push_front(new_cmd);

}
/*
void Terminal::push_hist(std::list){
  list_hist.push_front(new_cmd);

}
*/
void Terminal::push_last_cwd(char *last_cwd){
  list_last.push_front(last_cwd);
}
/**
 * make sure what "auto" is!!!
 */
void Terminal::print_hist(){
  for (auto it = list_hist.cbegin(); it != list_hist.cend(); it++) {
    std::cout << *it << std::endl;
  }
}

