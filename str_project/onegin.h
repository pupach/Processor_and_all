#ifndef ONEGIN
#define ONEGIN

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "source/str_input.h"
#include "source/str_output.h"
#include "../my_lib/str_func.h"
#include "source/func_sort.h"
#include "source/algoritm_sort.h"
#include "source/len_array.h"

len_arr * split_file_on_str(FILE *stream_read, len_arr **buff_for_free);

#endif
