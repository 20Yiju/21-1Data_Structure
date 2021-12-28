// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;
void tick(pClock ptr);
void runs(pClock ptr);
void show(pClock ptr, char end = '\n');

// increment the time by one second.
void tick(pClock ptr) {
    if((ptr->sec) == 59){
        ptr -> sec = 0;
        ptr -> min++;
        if((ptr->min) == 60){
            ptr -> min = 0;
            ptr -> hr++;
        }
    }
    else{
        ptr->sec++;
    }
    
}

// show the current time in military form.
void show(pClock ptr, char end)  {
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"
    << std::setw(2) << ptr->min << ":"
    << std::setw(2) << ptr->sec << end << std::flush;
    
}


void runs(pClock ptr){
    while(true) {
        sleep(1);
        tick(ptr);
        show(ptr, '\r');
    }
}

int main (void) {
    pClock ptr = new Clock { 14, 38, 56};

    runs(ptr);

    return 0;
    delete ptr;
}