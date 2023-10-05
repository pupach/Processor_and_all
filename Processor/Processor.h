#ifndef PROCESSOR
#define PROCESSOR
#include "command.h"
#include "../Stack/stack.h"
#include "../str_project/onegin.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

const int AMOUNT_VAR_IN_PROC = 4;

struct Processor
{
    Stack *stk = Stack
    int variables[AMOUNT_VAR_IN_PROC] = {};
};


#endif
