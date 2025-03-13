#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i;
    int N;

    scanf("%d", &N);

    i = 0;
    while(true)
    {
        if(N <= ((long long int)1ULL + 3 * i * (i + 1)))
        {
            break;
        }

        i++;
    }

    printf("%d\n", i + 1);

    return 0;
}