#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "str_func.cpp"
#define SIZE_ARR(arr) sizeof(arr)/sizeof(arr[0])

#define assert_perror(errnum, args...)						                                                      \
  if(!errnum){								                                                                      \
    fprintf(stdout, "%d, %s, %d //-----------------------------------------------------------------------------", \
            (errnum), __FILE__, __LINE__);                                                                        \
    fprintf(stdout, args);                                                                                        \
     return false;                                                                                                \
    }


#define LOG(mode, args...)                                                       \
    do {                                                                         \
    if(mode) {                                                                   \
        fprintf(stderr, "%s:%d\t %s\t", __FILE__, __LINE__, __PRETTY_FUNCTION__);\
        }                                                                        \
    } while(0)


bool compare_pointer(char *pointer_one, char *pointer_two)
{
    if ((pointer_one == nullptr) and (pointer_two == nullptr)) return true;

    else if (pointer_one == pointer_two) return false;

    else if ((pointer_one == nullptr) or(pointer_two == nullptr)) return false;

    else return (strcmp(pointer_one, pointer_two) == 0);
}


bool equ_Mystrchr(const char *str, int ch);

bool equ_Mystrchr(const char *str, int ch)
{
    LOG(true);

    char * res_my = Mystrchr(strdup(str), ch);
    char * res_c = strchr(strdup(str), ch);

    assert_perror((compare_pointer(res_my, res_c)), "%s %s", res_my, res_c);

    return true;
}

bool equ_Mystrlen(const char *str)
{
    LOG(true);

    int res_my = Mystrlen(str);
    int res_c = strlen(str);

    assert_perror((res_my == res_c), "%d %d", res_my, res_c);

    return true;
}

bool equ_Mystrcpy(char *destptr, const char *srcptr)
{
    LOG(true);

    char * res_my = Mystrcpy(strdup(destptr), srcptr);
    char * res_c = strcpy(strdup(destptr), srcptr);

    assert_perror((compare_pointer(res_my, res_c)), "%s %s", res_my, res_c);

    return true;
}

bool equ_Mystrncpy(char *destptr, const char *srcptr, size_t n)
{
    LOG(true);

    char * res_my = Mystrncpy(strdup(destptr), srcptr, n);
    char * res_c = strncpy(strdup(destptr), srcptr, n);

    assert_perror(compare_pointer(res_c, res_my), "%s %s", res_my, res_c);

    return true;
}

bool equ_Mystrcat(char * destptr, const char * srcptr)
{
    LOG(true);

    char * res_my = Mystrcat(strdup(destptr), srcptr );
    char * res_c = strcat(strdup(destptr), srcptr );

    assert_perror(compare_pointer(res_my, res_c),  "%s %s", res_my, res_c);

    return true;
}

bool equ_Mystrncat(char *destptr, const char *srsrcptr, size_t n)
{
    LOG(true);

    char * res_my = Mystrncat(strdup(destptr), srsrcptr, n);
    char * res_c = strncat(strdup(destptr), srsrcptr, n);

    printf("\n%d, %d, %d\n", res_c == nullptr, res_my == nullptr, res_c==res_my);
    assert_perror(compare_pointer(res_my, res_c),  "%s %s", res_my, res_c);

    return true;
}

bool equ_Mystrdup(const char *str)
{
    LOG(true);

    char * res_my = Mystrdup(strdup(str));
    char * res_c  = strdup(strdup(str));

    assert_perror(compare_pointer(res_my, res_c), "%s %s", res_my, res_c);

    return true;
}

const int MAX_SIZE_STR = 100;
const int MAX_INT_DATA = 100;

int test(char str_for_test_1[][MAX_SIZE_STR], int int_for_test[4], size_t len_str, size_t len_int)
{
        char s1[MAX_SIZE_STR];
        char s2[MAX_SIZE_STR];

        for (int i = 0; i < len_str; i++)
        {
            for (int j = 0; j < len_str; j++)
            {
                for (int k = 0; k < len_int; k++)
                {


                    strcpy(s1, str_for_test_1[i]);
                    strcpy(s2, str_for_test_1[j]);
                    equ_Mystrchr(s1, int_for_test[k]);

                    strcpy(s1, str_for_test_1[i]);
                    strcpy(s2, str_for_test_1[j]);
                    equ_Mystrcpy((char *)s1, (char *)s2);


                    strcpy(s1, str_for_test_1[i]);
                    strcpy(s2, str_for_test_1[j]);
                    equ_Mystrncpy((char *)s1, (char *)s2, int_for_test[k]);

                    strcpy(s1, str_for_test_1[i]);
                    strcpy(s2, str_for_test_1[j]);
                    equ_Mystrcat((char *)s1, (char *)s2);

                    strcpy(s1, str_for_test_1[i]);
                    strcpy(s2, str_for_test_1[j]);
                    equ_Mystrncat((char *)s1, (char *)s2, int_for_test[k]);

                }
            }

            strcpy(s1, str_for_test_1[i]);
            equ_Mystrlen((char *)s1);

            strcpy(s1, str_for_test_1[i]);
            equ_Mystrdup((char *)s1);


        }
}




int main()
{
    char str_for_test_1[][MAX_SIZE_STR] = {"ghghgh", "yyyy" , " "};
    char str_for_test_2[][MAX_SIZE_STR] = {"ghghgh", "yyyy", " "};
    int int_for_test[] = {1};

    test(str_for_test_1, int_for_test, SIZE_ARR(str_for_test_1), SIZE_ARR(int_for_test));
}
