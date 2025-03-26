#include <stdio.h>
#include <string.h>

#define STACK_MAX 100000

int stack[STACK_MAX], stack_top;

int main(void)
{
    int i;
    int K, get_num;
    unsigned int sum;

    scanf("%d", &K);
    memset(stack, 0x00, sizeof(int));
    stack_top = 0;
    sum = 0;

    for(i = 0; i < K; i++)
    {
        scanf("%d", &get_num);

        if(get_num == 0)
        {
            stack[stack_top - 1] = 0;
            stack_top--;
        }
        else
        {
            stack[stack_top] = get_num;
            stack_top++;
        }
    }

    for(i = 0; i < stack_top; i++)
    {
        sum += stack[i];
    }

    printf("%u\n", sum);

    return 0;
}
