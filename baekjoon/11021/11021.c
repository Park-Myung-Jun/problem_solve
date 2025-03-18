#include <stdio.h>

int main(void)
{
    int t;
    int T, A, B;

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        scanf("%d %d", &A, &B);

        printf("Case #%d: %d\n", t, A + B);
    }

    return 0;
}
