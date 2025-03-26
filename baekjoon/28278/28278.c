#include <stdio.h>
#include <string.h>

#define STACK_MAX_SIZE 1000000

int stack[STACK_MAX_SIZE], stack_top = 0;

int main(void)
{
    int i;
    int N, cmd, get_num;

    scanf("%d", &N);
    memset(stack, 0x00, sizeof(int) * STACK_MAX_SIZE);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &cmd);

        switch(cmd)
        {
            case 1:
                scanf("%d", &get_num);
                stack[stack_top] = get_num;
                stack_top++;
                break;

            case 2:
                if(stack_top == 0)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", stack[stack_top - 1]);
                    stack_top--;
                }
                break;

            case 3:
                printf("%d\n", stack_top);
                break;

            case 4:
                printf("%d\n", stack_top == 0);
                break;

            case 5:
                if(stack_top == 0)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", stack[stack_top - 1]);
                }
                break;

            default:
                break;
        }
    }

    return 0;
}
