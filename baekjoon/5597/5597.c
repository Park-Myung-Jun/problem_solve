#include <stdio.h>
#include <string.h>

#define STUDENT_MAX_NUM 30

int main(void)
{
    int i;
    int student_homework_check[STUDENT_MAX_NUM], num_get;

    memset(student_homework_check, 0x00, STUDENT_MAX_NUM * sizeof(int));

    for(i = 0; i < STUDENT_MAX_NUM - 2; i++)
    {
        scanf("%d", &num_get);
        student_homework_check[num_get - 1]++;
    }

    for(i = 0; i < STUDENT_MAX_NUM; i++)
    {
        if(student_homework_check[i] == 0)
        {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}
