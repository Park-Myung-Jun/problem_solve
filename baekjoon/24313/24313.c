#include <stdio.h>

int main(void)
{
    int a1, a0, c, n0;

    scanf("%d %d %d %d", &a1, &a0, &c, &n0);

    printf("%d\n", (a1 * n0 + a0 <= c * n0) && (a1 <= c));

    return 0;
}
