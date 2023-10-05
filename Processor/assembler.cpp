#include "../my_lib/work_with_file.h"
#include "../my_lib/str_func.h"
#include "../str_project/onegin.h"
#include "command.h"
#include "assembler.h"


static CODE_ERRORS com_divis(FILE *stream_write);

static CODE_ERRORS com_sub(FILE *stream_write);

static CODE_ERRORS com_mul(FILE *stream_write);

static CODE_ERRORS com_add(FILE *stream_write);

static CODE_ERRORS com_push(FILE *stream_write, int number);

static CODE_ERRORS com_HLT(FILE *stream_write);

static CODE_ERRORS com_out(FILE *stream_write);


CODE_ERRORS assembling(char file_to_read[], char file_to_write[])
{
    FILE *stream_read = open_file(file_to_read, "r");
    FILE *stream_write = open_file(file_to_write, 'w');

    compiling_assembler(stream_read, stream_write);

}

CODE_ERRORS compiling_assembler(FILE *stream_read, FILE *stream_write)
{
    len_arr *buff = nullptr;
    len_arr *ptr_all_str = split_file_on_str(stream_read, &buff);
        for (int i = 0; i < (ptr_all_str->size_arr); i++)
    {
        compile_one_str_ass((len_arr *)(ptr_all_str->arr) + i, stream_write);
    }
    free_all_dinamic_ptr(ptr_all_str);
    free_mem_buf(buff);
}

CODE_ERRORS compile_one_str_ass(len_arr *ptr_str, FILE *stream_write)
{
    STR_CODE_COMMANDS code_com = {};
    const size_t MAX_SIZE_COM = 10;
    char command[MAX_SIZE_COM] = {};
    fprintf(stderr, "compile_one_str %s\n", ((char *)ptr_str->arr));
    size_t size = strcpy_to_space(command, ((char *)ptr_str->arr));

    ptr_str->arr = (char *)((char *)ptr_str->arr + size);

        if(strcmp(code_com.push, command))
        {
            com_push(stream_write, atoi(((char *)ptr_str->arr)));
        }
        else if(strcmp(code_com.add, command))
        {
            com_add(stream_write);
        }
        else if(strcmp(code_com.sub, command))
        {
            com_sub(stream_write);
        }
        else if(strcmp(code_com.mul, command))
        {
            com_mul(stream_write);
        }
        else if(strcmp(code_com.divis, command))
        {
            com_divis(stream_write);
        }
        else if(strcmp(code_com.out, command))
        {
            com_out(stream_write);
        }
        else if(strcmp(code_com.HLT, command))
        {
            com_HLT(stream_write);
        }
        else
        {
            LOG(1, stderr, "very strange error");
            return UNDEF_ERROR;
        }
}




static CODE_ERRORS com_push(FILE *stream_write, int number)
{
    fprintf(stream_write, "%d %d\n", push, number);
}

static CODE_ERRORS com_add(FILE *stream_write)
{
    fprintf(stream_write, "%d\n", add);
}

static CODE_ERRORS com_mul(FILE *stream_write)
{
    fprintf(stream_write, "%d\n", mul);
}

static CODE_ERRORS com_sub(FILE *stream_write)
{
    fprintf(stream_write, "%d\n", sub);
}


static CODE_ERRORS com_divis(FILE *stream_write)
{
    fprintf(stream_write, "%d\n", divis);
}

static CODE_ERRORS com_out(FILE *stream_write)
{
    fprintf(stream_write, "%d\n", out);
}

static CODE_ERRORS com_HLT(FILE *stream_write)
{
    fprintf(stream_write, "%d\n", HLT);
}

