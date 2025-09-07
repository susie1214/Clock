#include <iostream>
#include "FND.h"

using namespace std;

FND::FND(){
    clear();
}

FND::FND(char in[]){
    for(int i=0; i<7; i++)
        this->in[i] = in[i];
        
    clear();
    cnvt();
}

void FND::clear(){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            disp[i][j] = ' ';
}

void FND::cnvt(){
    for(int i=0; i<5; i++) if(in[0] == '1') disp[0][i] = '#';
    for(int i=0; i<3; i++) if(in[1] == '1') disp[i][4] = '#';
    for(int i=0; i<3; i++) if(in[2] == '1') disp[2+i][4] = '#';
    for(int i=0; i<5; i++) if(in[3] == '1') disp[4][i] = '#';
    for(int i=0; i<3; i++) if(in[4] == '1') disp[i+2][0] = '#';
    for(int i=0; i<3; i++) if(in[5] == '1') disp[i][0] = '#';
    for(int i=0; i<5; i++) if(in[6] == '1') disp[2][i] = '#';
}

void FND::setFND(char in[]){
    for(int i=0; i<7; i++)
        this->in[i] = in[i];
        
    clear();
    cnvt();
}

void FND::getFND(char *fnd[5]){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            fnd[i][j] = disp[i][j];
}

void FND::dispFND(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << disp[i][j];       
        }
        cout << endl;
    }
}

void FND::dispFND(int num){
    for(int i=0; i<5; i++)
        cout << disp[num][i];
    cout << ' ';    
}

