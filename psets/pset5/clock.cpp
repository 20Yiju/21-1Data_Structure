// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "clock.h"

// increment the time by one second.
void tick(pClock clk) {
    if((clk->sec) == 59){
        clk -> sec = 0;
        clk -> min++;
        if((clk->min) == 60){
            clk -> min = 0;
            clk -> hr++;
        }
    }
    else{
        clk->sec++;
    }
    
}

// show the current time in military form.
void show(pClock clk, char end)  {
    std::cout.fill('0');
    std::cout << std::setw(2) << clk->hr << ":"
    << std::setw(2) << clk->min << ":"
    << std::setw(2) << clk->sec << end << std::flush;
    
}


void runs(pClock clk, char end){
    while(true) {
        sleep(1);
        tick(clk);
        show(clk, end);
    }
}