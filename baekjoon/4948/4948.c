#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int num)
{
    int i, sqrt_num = (int)sqrt(num);

    if(num < 2)
    {
        return false;
    }

    for(i = 2; i <= sqrt_num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int i;
    int n, prime_count;

    while(true)
    {
        prime_count = 0;
        scanf("%d", &n);

        if(n == 0)
        {
            break;
        }

        for(i = n + 1; i <= 2 * n; i++)
        {
            if(is_prime(i))
            {
                prime_count++;
            }
        }

        printf("%d\n", prime_count);
    }

    return 0;
}
