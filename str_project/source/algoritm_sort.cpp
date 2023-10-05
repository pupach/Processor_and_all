#include "algoritm_sort.h"
#include "str_input.h"
#include "func_sort.h"
#include "../../my_lib/str_func.h"
#include "../../my_lib/work_with_file.h"


len_arr *sort_bubble(len_arr *arr_ptr, int (*f_sort) (len_arr *, len_arr *))
{
    LOG(1, stderr, "size %d", arr_ptr->size_arr);

    len_arr *arr_to_sort = (len_arr *)calloc(arr_ptr->size_arr, sizeof(len_arr *) * 2);

    for (int i = 0; i < (arr_ptr->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(arr_ptr->arr) + i);

        LOG(1, stderr, "arr_ptr number %d, str %s\n", i, (char *)(may->arr));// �� ����� ����� ������� � ��������� ������������ �������� ��������
    }

    memcpy(arr_to_sort, (len_arr *)(arr_ptr->arr), sizeof(len_arr *)*(arr_ptr->size_arr)*2);//why 2?????

    for (int i = 0; i < (arr_ptr->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(arr_to_sort) + i);
        LOG(1, stderr, "arr_to_sort number %d, str %s\n", i, (char *)(may->arr));
    }

    printf("\n%d\n", sizeof(len_arr *));

    for (int i = 0; i < ( arr_ptr->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(arr_to_sort) + i);
        LOG(1, stderr, "sort_bubble 3 number %d, str %s\n", i, (char *)(may->arr));
    }

    bool flag_is_sorted = false;

    do
    {
        flag_is_sorted = true;

        for(size_t i = 0; i < (arr_ptr->size_arr - 1); i++)
        {
            LOG(1, stderr, "sort_bubble i = %d, size = %d\n", i, arr_ptr->size_arr);
            LOG(1, stderr, "str1-%d, str2-%d\n         ", i, i+1);

            int res = f_sort((len_arr *)(arr_to_sort)  + i, (len_arr *)(arr_to_sort)  + i+1);
            LOG(1, stderr, "\nsort endd\n");
            if (res == -1)
            {
                len_arr promejutok = *(arr_to_sort  + i);

                *(arr_to_sort  + i) = *(arr_to_sort  + i+1);
                *(arr_to_sort  + i+1) = promejutok;

                flag_is_sorted = false;
            }
        }
    }while(!flag_is_sorted);
    LOG(1, stderr, "\nwhile_end\n");


    return gen_struct_len_arr((void *)arr_to_sort, arr_ptr->size_arr);
}

