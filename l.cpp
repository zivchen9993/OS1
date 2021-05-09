#include <iostream>
#include<unistd.h>
int main() {
    std::cout << "Hello World!";
	sleep(300);//sleeps for 3 second
	std::cout << "Goodbye World!";
	return 0;
}
