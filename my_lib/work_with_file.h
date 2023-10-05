#ifndef WORK_WITH_FILe
#define WORK_WITH_FILe
#include <stdlib.h>
  // � ���, � ���, ������ ���� �� ����, �����������!!!
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LOG(mode, stream_out, args...)                                                        \
    do                                                                                      \
    {                                                                                       \
        if(mode)                                                                            \
        {                                                                                           \
            fprintf(stream_out, args);                                                      \
        }                                                                                   \
    } while(0)


enum CODE_ERRORS
{
    ALL_GOOD   = 0,
    VAL_NAN    = 1,
    VAL_INF    = 2,
    VAL_POISON = 3,
    VAL_ZERO   = 4,
    BAD_RETURN = 5,
    OVERFLOW_STACK = -1,
    UNDEF_ERROR = 59,
    WAS_REALLOC = 9,
    STACK_SOON_EMPTY = -4,
    STACK_EMPTY = -5,
    PTR_NULL = -10,
    BAD_HASH = 23,
    NO_HLT = 90,
    NO_NUMBER = 100
};

const int MAX_SIZE = 2;

const int MAX_SIZE_FILE = 255 * 8;//
const char POISON_VAL_FOR_CHAR = '_';


char *Myinsert_str_to_str(const char *str1, const char *str2, size_t index_of_insert);

void close_file_for_debug(FILE *stream_out);

FILE *open_file(const char *text="_", char *mode="r");
#endif
