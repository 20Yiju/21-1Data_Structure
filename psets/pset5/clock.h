// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*; 

void tick(pClock clk);
void show(pClock clk, char rp = '\n');
void runs(pClock clk, char rp = '\n');
