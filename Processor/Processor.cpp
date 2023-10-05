#include "../my_lib/work_with_file.h"
#include "../str_project/onegin.h"
#include "command.h"
#include "assembler.h"
#include "dis_assembler.h"
#include "virtual_machine.h"
#include "Processor.h"

int main()
{
    assembling("rools.txt", "rools_bit.txt");
    dis_assembling("rools_bit.txt", "rools_check.txt");
    run_program_from_file("rools_bit.txt");
}



