#include "../my_lib/work_with_file.h"
#include "command.h"
#include "virtual_machine.h"
#include "Processor.h"

static CODE_ERRORS com_divis(Stack *stk);

static CODE_ERRORS com_sub(Stack *stk);

static CODE_ERRORS com_mul(Stack *stk);

static CODE_ERRORS com_add(Stack *stk);

static CODE_ERRORS com_push(Stack *stk, FILE *stream_read);

static CODE_ERRORS com_out(Stack *stk);

CODE_ERRORS run_program_from_file(char name_com_file[])
{
    int res_com_fscanf = 0;
    int command = POISON_VAL;
    bool flag_hlt = false;
    FILE *stream_read = open_file(name_com_file, "r");

    if (stream_read == nullptr) return PTR_NULL;

    Processor *Cpu_proc = (Processor *)calloc(sizeof(Processor), 1);

    Stack stk1 = {};
    Stack *stk = &stk1;
    Stack_init(stk, 20, 2);

    Cpu_proc->stk = stk;

    do
    {
        res_com_fscanf = fscanf(stream_read, "%d", &command);

        if (res_com_fscanf == 0)
        {
            LOG(1, stderr, "bad code");
            Stack_Destructor(stk); return NO_HLT;
        }
        printf("%d, \n", command);

        switch (command)
        {
            case push:
                com_push(Cpu_proc->stk, stream_read);
                break;
            case add:
                com_add(Cpu_proc->stk);
                break;
            case sub:
                com_sub(Cpu_proc->stk);
                break;
            case mul:
                com_mul(Cpu_proc->stk);
                break;
            case divis:
                com_divis(Cpu_proc->stk);
                break;
            case out:
                com_out(Cpu_proc->stk);
                break;
            case HLT:
                flag_hlt = true;
                break;
            default:
                LOG(1, stderr, "very strange error");
                Stack_Destructor(Cpu_proc->stk);
                return UNDEF_ERROR;

        };
    }while(!flag_hlt);
    Stack_Destructor(Cpu_proc->stk);
    free(Cpu_proc);
}

static CODE_ERRORS com_push(Stack *stk, FILE *stream_read)
{
    Elen_s numb = -1;
    int res = fscanf(stream_read, "%ld", &numb);
    if (res)
    {
        LOG(1, stderr, "com_push number to push %d", numb);
        Stack_Push(stk, numb);
        return ALL_GOOD;
    }
    else
    {
       LOG(1, stderr, "no number");
       return NO_NUMBER;
    }

}

static CODE_ERRORS com_add(Stack *stk)
{
    Elen_s slag_1 = -1;
    Stack_Pop(stk, &slag_1);
    Elen_s slag_2 = -1;
    Stack_Pop(stk, &slag_2);

    if ((!isnan(slag_1)) and (!isnan(slag_2)))
    {
       Stack_Push(stk, slag_1 + slag_2);
        return ALL_GOOD;
    }
    else
    {
       LOG(1, stderr, "UNDEF_ERROR");
       return UNDEF_ERROR;
    }

}

static CODE_ERRORS com_mul(Stack *stk)
{
    Elen_s slag_1 = -1;
    Stack_Pop(stk, &slag_1);
    Elen_s slag_2 = -1;
    Stack_Pop(stk, &slag_2);

    if ((!isnan(slag_1)) and (!isnan(slag_2)))
    {
       Stack_Push(stk, slag_1 * slag_2);
        return ALL_GOOD;
    }
    else
    {
       LOG(1, stderr, "UNDEF_ERROR");
       return UNDEF_ERROR;
    }
}

static CODE_ERRORS com_sub(Stack *stk)
{
    Elen_s slag_1 = -1;
    Stack_Pop(stk, &slag_1);
    Elen_s slag_2 = -1;
    Stack_Pop(stk, &slag_2);

    if ((!isnan(slag_1)) and (!isnan(slag_2)))
    {
       Stack_Push(stk, slag_2 - slag_1);
        return ALL_GOOD;
    }
    else
    {
       LOG(1, stderr, "UNDEF_ERROR");
       return UNDEF_ERROR;
    }
}


static CODE_ERRORS com_divis(Stack *stk)
{
    Elen_s slag_1 = -1;
    Stack_Pop(stk, &slag_1);
    Elen_s slag_2 = -1;
    Stack_Pop(stk, &slag_2);

    if (!isnan(slag_1) and !isnan(slag_2))
    {
       Stack_Push(stk, slag_2 / slag_1);
        return ALL_GOOD;
    }
    else
    {
       LOG(1, stderr, "UNDEF_ERROR");
       return UNDEF_ERROR;
    }
}

static CODE_ERRORS com_out(Stack *stk)
{
    Elen_s slag_1 = -1;
    Stack_Pop(stk, &slag_1);

    if (!isnan(slag_1))
    {
       printf("element number %d equ %ld", stk->size_s, slag_1);
    }
    else
    {
       LOG(1, stderr, "UNDEF_ERROR");
       return UNDEF_ERROR;
    }
}




