#include <iostream>
#include "myClock.h"

using namespace std;

myClock::myClock(){
    ttl7490.reset(1,0,0);
    maxcnt = 10;
    cnvt();
}

myClock::myClock(int num, int max){
    if(num == 0) ttl7490.reset(1, 0, 0);
    else if(num == 1) ttl7490.reset(0, 1, 0);
    else if(num == 2) ttl7490.reset(0, 0, 1);
    
    maxcnt = max;
    
    cnvt();
}

void myClock::clockin(int clk){
    ttl7490.clockin(clk);

    if(ttl7490.getNum() == maxcnt)
        ttl7490.reset(1, 0, 0);
    
    cnvt();
}

int myClock::clockout(){
    return clk;
}

void myClock::cnvt(){
    char out7490[4];
    char out7446[7];
    
    ttl7490.getOutput(out7490);
    ttl7446.setInput(out7490);
    ttl7446.getOutput(out7446);
    fnd.setFND(out7446);
    if(maxcnt == 6)
        clk = out7490[2] - '0';
    else
        clk = out7490[3] - '0';
}

void myClock::dispFnd(){
    fnd.dispFND();
}

void myClock::dispFnd(int num){
    fnd.dispFND(num);
}

void myClock::getOutput(char out[]){
    ttl7490.getOutput(out);
}

int myClock::getCount(){
    return ttl7490.getNum();
}

void myClock::reset(int num){
    if(num == 0) ttl7490.reset(1, 0, 0);
    else if(num == 1) ttl7490.reset(0, 1, 0);
    else if(num == 2) ttl7490.reset(0, 0, 1);
    
    cnvt();
}