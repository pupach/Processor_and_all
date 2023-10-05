#ifndef ASSEMBLER
#define ASSEMBLER
#include "command.h"
#include "../Stack/stack.h"
#include "../str_project/onegin.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

CODE_ERRORS compile_one_str_ass(len_arr *ptr_str, FILE *stream_write);

CODE_ERRORS compiling_assembler(FILE *stream_read, FILE *stream_write);

CODE_ERRORS assembling(char file_to_read[], char file_to_write[]);
#endif
