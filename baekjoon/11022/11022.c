#include <stdio.h>

int main(void)
{
    int T, t;
    int A, B;

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        scanf("%d %d", &A, &B);

        printf("Case #%d: %d + %d = %d\n", t, A, B, A + B);
    }

    return 0;
}
