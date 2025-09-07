/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
//#include "TTL7490.h"
//#include "TTL7446.h"
//#include "FND.h"
#include <ctime>
#include "myClock.h"

using namespace std;

void delay(int milliseconds) {
    clock_t start = clock();
    while (clock() < start + milliseconds * CLOCKS_PER_SEC / 1000);
}

int clockout(){
    static int clk = 0;
    
    if(clk) clk = 0;
    else clk = 1;
    
    return clk;
}

int main(){
    myClock h1(2, 10), h10(1, 2), m1, m10(0, 6), s1, s10(0, 6);
    char temp[4];
    
    for(int i=0; ; i++){
        s1.clockin(clockout());
        
        if(i%2 == 0){
            s10.clockin(s1.clockout());
            
            m1.clockin(s10.clockout());
            m10.clockin(m1.clockout());
            
            h1.clockin(m10.clockout());
            h10.clockin(h1.clockout());
            
            if(h10.getCount() == 1 && h1.getCount() == 3){
                h10.reset(0);
                h1.reset(1);
            }
            
            for(int j=0; j<5; j++){
                h10.dispFnd(j);
                h1.dispFnd(j);
                if(j == 1 || j == 3) cout << " # ";
                else cout << "   ";
                m10.dispFnd(j);
                m1.dispFnd(j);
                if(j == 1 || j == 3) cout << " # ";
                else cout << "   ";
                s10.dispFnd(j);
                s1.dispFnd(j);
                cout << endl;
            }
            
            cout << endl << endl;
            
            delay(1000);
        }
    }
    
    return 0;
}

/*

int main()
{
    TTL7490 ttl7490(1, 0, 0);
    TTL7446 ttl7446;
    FND fnd;
    char out[4];
    char out7446[7];
    
    for(int i=0; i<20; i++){
        ttl7490.clockin(clockout());
        if(i % 2 == 0){
            ttl7490.getOutput(out);
            ttl7446.setInput(out);
            ttl7446.getOutput(out7446);
            fnd.setFND(out7446);
            
            cout << ttl7490.getNum() << " : " << out[3] << out[2] << out[1] << out[0] << "(";
            for(int j=0; j<7; j++)
                cout << out7446[j];
            cout << ")" << endl;
            
            fnd.dispFND();
        }
    }

    return 0;
}*/