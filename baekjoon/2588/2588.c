#include <stdio.h>

int main(void)
{
    int num_1, num_2;

    scanf("%d %d", &num_1, &num_2);

    printf("%d\n%d\n%d\n%d\n", num_1 * (num_2 % 10),
        num_1 * (num_2 / 10 % 10), num_1 * (num_2 / 100), num_1 * num_2);

    return 0;
}
