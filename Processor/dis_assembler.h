#ifndef DIS_ASSEMBLER
#define DIS_ASSEMBLER
#include "command.h"
#include "../Stack/stack.h"
#include "../str_project/onegin.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

CODE_ERRORS compile_one_str_dis(len_arr *ptr_str, FILE *stream_write);

CODE_ERRORS compiling_dis_assembler(FILE *stream_read, FILE *stream_write);

CODE_ERRORS dis_assembling(char file_to_read[], char file_to_write[]);
#endif
