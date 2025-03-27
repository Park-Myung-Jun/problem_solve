#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STUDENT_MAX 1000

int main(void)
{
    int i;
    int N, stack[STUDENT_MAX], stack_top, student_num, count;

    count = 1;
    stack_top = 0;
    memset(stack, 0x00, sizeof(int) * STUDENT_MAX);

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &student_num);
        stack[stack_top] = student_num;
        stack_top++;

        while(true)
        {
            if(stack_top == 0)
            {
                break;
            }

            if(stack[stack_top - 1] == count)
            {
                stack_top--;
                count++;
            }
            else
            {
                break;
            }
        }
    }

    if(stack_top == 0)
    {
        printf("Nice\n");
    }
    else
    {
        printf("Sad\n");
    }

    return 0;
}
