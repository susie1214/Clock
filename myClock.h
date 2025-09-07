#ifndef __MYCLOCK_H__
#define __MYCLOCK_H__

#include "TTL7490.h"
#include "TTL7446.h"
#include "FND.h"

class myClock{
    TTL7490 ttl7490;
    TTL7446 ttl7446;
    FND fnd;
    int maxcnt;
    int clk;
    void cnvt();
public:
    myClock();
    myClock(int resetNum, int max);
    void clockin(int clk);
    int clockout();
    void getOutput(char out[]);
    void dispFnd();
    void dispFnd(int num);
    int getCount();
    void reset(int num);
    
};

#endif