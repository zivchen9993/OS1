#include <iostream>
#include<unistd.h>
int main() {
    std::cerr << "Hello World!";
	sleep(5);//sleeps for 3 second
	std::cerr << "s1";
	sleep(5);//sleeps for 3 second
	std::cerr << "s2";
	sleep(5);//sleeps for 3 second
	std::cerr << "s3";
	sleep(5);//sleeps for 3 second
	std::cerr << "Goodbye World!";
	return 0;
}
