#include <iostream>
#include<unistd.h>
int main() {
    std::cerr << "Hello World!";
	sleep(10);//sleeps for 3 second
	std::cerr << "awake";
	return 0;
}
