#include <iostream>
#include<unistd.h>
int main() {
    std::cout << "Hello World!";
	unsigned int microsecond = 1000000;
	usleep(3 * microsecond);//sleeps for 3 second
	std::cout << "Goodbye World!";
	return 0;
}
