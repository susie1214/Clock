#include <iostream>
#include "TTL7446.h"

using namespace std;

TTL7446::TTL7446(){
    in[3] = in[2] = in[1] = in[0] = '0';
    
    bin2dec();
    cnvt();
}

TTL7446::TTL7446(char in[]){
    for(int i=0; i<4; i++)
        this->in[i] = in[i];
        
    bin2dec();
    cnvt();
}

void TTL7446::bin2dec(){
    int num = 0;
    
    for(int i=0; i<4; i++){
        num |= ((in[i] - '0') << i);
    }
    
    this->num = num;
}

void TTL7446::cnvt(){
    
    for(int i=0; i<7; i++)
        out[i] = table[num][i] + '0';
}

void TTL7446::setInput(char in[]){
    for(int i=0; i<4; i++)
        this->in[i] = in[i];
        
    bin2dec();
    cnvt();
}

void TTL7446::getOutput(char out[]){
    for(int i=0; i<7; i++)
        out[i] = this->out[i];
}