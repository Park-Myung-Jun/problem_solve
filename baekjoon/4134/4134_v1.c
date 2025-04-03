#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define PRIME_MAX 4000000

bool prime_check[PRIME_MAX + 1];
int prime_save[PRIME_MAX], prime_count;

int main(void)
{
    int i, j, k;
    int T, sqrt_num, n;
    bool prime_upper_check;

    memset(prime_check, 0x00, sizeof(bool) * PRIME_MAX);
    sqrt_num = (int)sqrt(PRIME_MAX);
    prime_check[0] = true;
    prime_check[1] = true;
    for(i = 2; i <= sqrt_num; i++)
    {
        for(j = i * i; j <= PRIME_MAX; j += i)
        {
            prime_check[j] = true;
        }
    }

    for(i = 0; i <= PRIME_MAX; i++)
    {
        if(prime_check[i] == false)
        {
            prime_save[prime_count] = i;
            prime_count++;
        }
    }

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);

        if(n < prime_save[prime_count - 1])
        {
            for(i = 0; i < prime_count; i++)
            {
                if(n < prime_save[i])
                {
                    printf("%d\n", prime_save[i]);
                    break;
                }
            }
        }
        else
        {
            k = PRIME_MAX;

            while(true)
            {
                prime_upper_check = false;

                for(i = 0; i < prime_count; i++)
                {
                    if(k % prime_save[i] == 0)
                    {
                        k++;
                        prime_upper_check = true;
                        break;
                    }
                }

                if(prime_upper_check == false)
                {
                    prime_save[prime_count] = k;
                    prime_count++;

                    if(n < prime_save[prime_count - 1])
                    {
                        printf("%d\n", prime_save[i]);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
