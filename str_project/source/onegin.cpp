#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "str_input.h"
#include "str_output.h"
#include "../../my_lib/str_func.h"
#include "func_sort.h"
#include "algoritm_sort.h"
#include "len_array.h"
#include "../onegin.h"

len_arr * split_file_on_str(FILE *stream_read, len_arr **buff_for_free)
{
    len_arr *buff = read_from_file_to_buff(stream_read);
    *buff_for_free = buff;

    LOG(1, stderr,"\n main\n %s\n main\n", buff->arr);
    printf("main %p\n",  (buff->arr) );

    len_arr *ptr_all_str = find_all_str(buff);
    for (int i = 0; i < (ptr_all_str->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(ptr_all_str->arr) + i);
        LOG(1, stderr,"number %d, str %s\n point_mem %p\n", i, (char *)(may->arr), ((len_arr *)(ptr_all_str->arr) + i));
    }
    return ptr_all_str;

}
