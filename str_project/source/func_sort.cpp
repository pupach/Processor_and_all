#include "str_input.h"
#include "func_sort.h"
#include "../../my_lib/str_func.h"

int compare_str_len_arr(len_arr * str1, len_arr * str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);
    int index_1 = 0;
    int index_2 = 0;
    int delta_index = 0;
    int revers = 0;
    fprintf(stderr, "str1 %s \n", str1->arr);
    fprintf(stderr, "str2 %s \n ", str2->arr);


    if (revers)
    {
        index_1 = str1->size_arr;
        index_2 = str2->size_arr;
        delta_index = -1;
    }
    else
    {
        index_1 = 0;
        index_2 = 0;
        delta_index = 1;
    }

    int res_comp = 0;
    char *str_1 = (char *)(str1->arr);
    char *str_2 = (char *)(str2->arr);

    while((index_1 != str1->size_arr) and (index_2 != str2->size_arr)
            and res_comp == 0)
    {
//        LOG("while begin");
        while(!is_letter_rus(*(str_1 + index_1)))
        {
            index_1 += delta_index;
        }
        while(!is_letter_rus(*(str_2 + index_2)))
        {
            index_2 += delta_index;
        }

        if (*(str_1 + index_1) > *(str_2 + index_2)) res_comp = 1;

        else if (*(str_1 + index_1) < *(str_2 + index_2)) res_comp = -1;

        index_1 += delta_index;
        index_2 += delta_index;
//        LOG("while end");
    }

    if (res_comp == 0)
    {
        if ((index_1 != str1->size_arr) and (index_2 == str2->size_arr)) res_comp = -1;

        else if ((index_1 == str1->size_arr) and (index_2 != str2->size_arr)) res_comp = 1;

    }
    return res_comp;
}
