#include "../my_lib/work_with_file.h"
#include "../str_project/onegin.h"
#include "../my_lib/str_func.h"
#include "command.h"
#include "assembler.h"
#include "dis_assembler.h"



static CODE_ERRORS com_divis(FILE *stream_write);

static CODE_ERRORS com_sub(FILE *stream_write);

static CODE_ERRORS com_mul(FILE *stream_write);

static CODE_ERRORS com_add(FILE *stream_write);

static CODE_ERRORS com_push(FILE *stream_write, int number);

static CODE_ERRORS com_HLT(FILE *stream_write);

static CODE_ERRORS com_out(FILE *stream_write);

static STR_CODE_COMMANDS code_com = {};


CODE_ERRORS dis_assembling(char file_to_read[], char file_to_write[])
{
    FILE *stream_read = open_file(file_to_read, "r");
    FILE *stream_write = open_file(file_to_write, 'w');

    compiling_dis_assembler(stream_read, stream_write);

}

CODE_ERRORS compiling_dis_assembler(FILE *stream_read, FILE *stream_write)
{
    len_arr *buff = nullptr;
    len_arr *ptr_all_str = split_file_on_str(stream_read, &buff);
    for (int i = 0; i < (ptr_all_str->size_arr); i++)
    {
        compile_one_str_dis((len_arr *)(ptr_all_str->arr) + i, stream_write);
    }
    free_all_dinamic_ptr(ptr_all_str);
    free_mem_buf(buff);
}


CODE_ERRORS compile_one_str_dis(len_arr *ptr_str, FILE *stream_write)
{
    STR_CODE_COMMANDS code_com = {};
    const size_t MAX_SIZE_COM = 10;
    char command[MAX_SIZE_COM] = {};

    fprintf(stderr, "compile_one_str %s\n", ((char *)ptr_str->arr));

    size_t size = strcpy_to_space(command, ((char *)ptr_str->arr));

    ptr_str->arr = (char *)((char *)ptr_str->arr + size);
    int com = atoi(command);

    LOG(1, stderr, "compile_one_str1 com %d com %s\n", com, command);

    switch (com)
    {
        case push:
            com_push(stream_write, atoi((char *)ptr_str->arr));
            break;
        case add:
            com_add(stream_write);
            break;
        case sub:
            com_sub(stream_write);
            break;
        case mul:
            com_mul(stream_write);
            break;
        case divis:
            com_divis(stream_write);
            break;
        case out:
            com_out(stream_write);
            break;
        case HLT:
            com_HLT(stream_write);
            break;
        default:
            LOG(1, stderr, "very strange error");
            return UNDEF_ERROR;

    };
}




static CODE_ERRORS com_push(FILE *stream_write, int number)
{
    LOG(1, stderr, "com_push begin\n");
    fprintf(stream_write, "com_push  %s %d\n", code_com.push, number);
}

static CODE_ERRORS com_add(FILE *stream_write)
{
    fprintf(stream_write, "%s\n", code_com.add);
}

static CODE_ERRORS com_mul(FILE *stream_write)
{
    fprintf(stream_write, "%s\n", code_com.mul);
}

static CODE_ERRORS com_sub(FILE *stream_write)
{
    fprintf(stream_write, "%s\n", code_com.sub);
}

static CODE_ERRORS com_divis(FILE *stream_write)
{
    fprintf(stream_write, "%s\n", code_com.divis);
}

static CODE_ERRORS com_out(FILE *stream_write)
{
    fprintf(stream_write, "%s\n", code_com.out);
}

static CODE_ERRORS com_HLT(FILE *stream_write)
{
    fprintf(stream_write, "%s\n", code_com.HLT);
}

