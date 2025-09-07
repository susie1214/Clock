#ifndef __TTL7490_H__
#define __TTL7490_H__

class TTL7490{
    char clock, oldclock;
    int num;
    char out[4];
    void dec2bin();
    void dec2bin(int);
    
public:
    TTL7490(int R0=1, int R1=0, int R2=0);
    
    void reset(int R0, int R1, int R2);
    void clockin(int clock);
    int getNum();
    void getOutput(char out[]);
};

#endif