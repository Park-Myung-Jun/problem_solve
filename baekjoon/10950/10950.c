#include <stdio.h>

int main(void)
{
    int T, A, B;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

    return 0;
}