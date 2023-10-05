#ifndef COMMAND
#define COMMAND
#include "../Stack/stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


enum INT_CODE_COMMAND
{
    push = 1,
    HLT = -1,
    add = 4,
    sub = 3,
    mul = 5,
    divis = 6,
    out = 0,
    POISON_VAL = -11
};

struct STR_CODE_COMMANDS
{
    const char push[5] = "push";
    const char HLT[4] = "HLT";
    const char add[4] = "add";
    const char sub[4] = "sub";
    const char mul[4] = "mul";
    const char divis[7] = "divis";
    const char out[4] = "out";
    const char POISON_VAL[11] = "POISON_VAL";
};



#endif
