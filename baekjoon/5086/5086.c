#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int A, B;

    while(true)
    {
        scanf("%d %d", &A, &B);
        if(A == 0 && B == 0)
        {
            break;
        }

        if(A % B == 0)
        {
            printf("multiple\n");
        }
        else if(B % A == 0)
        {
            printf("factor\n");
        }
        else
        {
            printf("neither\n");
        }
    }

    return 0;
}