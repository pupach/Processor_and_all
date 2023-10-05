#include "work_with_file.h"
#include <stdlib.h>


FILE *open_file(const char *text_const, char *mode)
{
    FILE *stream_read = NULL;

    char file_name_to_open[MAX_SIZE_FILE] = {};

    strcpy(file_name_to_open, text_const);

    const size_t size_mode = 10;
    char new_mode[size_mode] = {};


    do{
        LOG(1, stderr, "%s\n", file_name_to_open);
        if (file_name_to_open[0] == POISON_VAL_FOR_CHAR)
        {
            printf("������� ��� �����, ��� ����� ����� ������� �������\n");


            fscanf(stdin, "%.*s", MAX_SIZE_FILE, file_name_to_open);
        }
        else if(!(strlen(text_const) < MAX_SIZE_FILE))
        {
            printf("����������� ����: ������� ������� ���");
            file_name_to_open[0] = POISON_VAL_FOR_CHAR;
        }
        if ((mode[0] != 'w') and (mode[0] != 'r'))
        {
            printf("����������� mode" );
            printf("������� mode" );

            scanf("%.*s", size_mode, new_mode);

            strcpy(new_mode, mode);
        }
        else
        {
            stream_read = fopen(file_name_to_open, mode);
            file_name_to_open[0] = POISON_VAL_FOR_CHAR;
        }

    }while(stream_read == NULL);

    return stream_read;
}

void close_file_for_debug(FILE *stream_out)
{
    if (!((stream_out == stdout) or (stream_out == stderr)))
    {
        fclose(stream_out);
    }
}
