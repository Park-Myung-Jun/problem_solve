#include <stdio.h>

int main(void)
{
    int V, A, B;

    scanf("%d %d %d", &A, &B, &V);

    printf("%d\n", (V - B - 1) / (A - B) + 1); // ((V - A) + (A - B - 1)) / (A - B) + 1

    return 0;
}
