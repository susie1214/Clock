#ifndef __FND_H__
#define __FND_H__

class FND{
    char disp[5][5];
    char in[7];
    void cnvt();
    void clear();
public:
    FND();
    FND(char in[]);
    void setFND(char in[]);
    void getFND(char *disp[5]);
    void dispFND();
    void dispFND(int num);
};

#endif