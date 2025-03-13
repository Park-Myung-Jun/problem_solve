#include <stdio.h>

int main(void)
{
    int i;
    int N;

    scanf("%d", &N);

    for(i = 0; i < N / 4; i++)
    {
        printf("long ");
    }

    printf("int\n");

    return 0;
}