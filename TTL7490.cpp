#include <iostream>
#include "TTL7490.h"

using namespace std;

TTL7490::TTL7490(int R0, int R1, int R2){
    if(R0 == 1) num = 0;
    else if(R1 == 1) num = 1;
    else if(R2 == 1) num = 2;
    
    clock = 0;
    oldclock = 0;
    
    dec2bin();
}

void TTL7490::reset(int R0, int R1, int R2){
    if(R0 == 1) num = 0;
    else if(R1 == 1) num = 1;
    else if(R2 == 1) num = 2;
    
    dec2bin();
}


void TTL7490::dec2bin(int n){
    int num = this->num;
    
    for(int i=0; i<4; i++){
        out[i] = (num % 2) + '0';
        num = (int)(num / 2);
    }
}

void TTL7490::dec2bin(){
    for(int i=0; i<4; i++){
        out[i] = ((this->num >> i) & 0x01) + '0';
    }
}

void TTL7490::clockin(int clock){
    this->clock = clock;
    
    if(this->oldclock == 1 && this->clock == 0)
        if(++num == 10) num = 0;
        
    dec2bin();
    
    this->oldclock = clock;
}

int TTL7490::getNum(){
    return num;
}

void TTL7490::getOutput(char out[]){
    for(int i=0; i<4; i++)
        out[i] = this->out[i];
}
