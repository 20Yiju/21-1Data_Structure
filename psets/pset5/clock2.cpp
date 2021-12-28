#include <iostream>
#include <iomanip>
struct Clock{
    int hr, min, sec; 
};

// increment the time by one second.
void tick(Clock *ptr) {
    ptr->sec++;
  // your code here
}
// show the current time in military form.
void show(Clock *ptr)  {
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"<< std::setw(2) << ptr->min << ":"<< std::setw(2) << ptr->sec << std::endl;

}

void tick(Clock *ptr);
void show(Clock *ptr);

int main (void) {
    Clock *ptr = new Clock { 14, 38, 56};
    for(int i = 0; i < 6; ++i) {
        tick(ptr);
        show(ptr); 
    }
    return 0;
    delete ptr;
}