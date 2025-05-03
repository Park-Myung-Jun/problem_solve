/*
1 -> 3

1 -> 2
1 -> 3
2 -> 3


1 -> 3
1 -> 2
3 -> 2

1 -> 3

2 -> 1
2 -> 3
1 -> 3
*/

#include <stdio.h>

void hanoi_recursive(int start, int mid, int end, int n)
{
    if(n == 0)
    {
        printf("%d %d\n", start, end);
        return;
    }

    hanoi_recursive(start, end, mid, n - 1);
    printf("%d %d\n", start, end);
    hanoi_recursive(mid, start, end, n - 1);
}

int main(void)
{
    int N, K;

    scanf("%d", &N);

    printf("%d\n", (1 << N) - 1);
    hanoi_recursive(1, 2, 3, N - 1);

    return 0;
}
