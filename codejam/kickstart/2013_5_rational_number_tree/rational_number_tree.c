#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define USE_LOG 0

#define RATIONAL_TREE_BINARY_SIZE 64

int main(void)
{
    int i;
    int T, t, id, rational_tree_count;
    unsigned long long n, p, q;
    char rational_tree[RATIONAL_TREE_BINARY_SIZE];

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        rational_tree_count = 0;
        memset(rational_tree, 0x00, RATIONAL_TREE_BINARY_SIZE * sizeof(char));
        scanf("%d", &id);

        if(id == 1)
        {
            p = 1;
            q = 1;
            scanf("%llu", &n);

            while(n != 0)
            {
                rational_tree[rational_tree_count] = n % 2;
                rational_tree_count++;
                n /= 2;
            }

#if USE_LOG
            for(i = 0; i < rational_tree_count; i++)
            {
                printf("%d ", rational_tree[i]);
            }
            printf("\n");
#endif

            for(i = rational_tree_count - 2; i >= 0; i--)
            {
                if(rational_tree[i] == 0)
                {
                    q = p + q;
                }
                else if(rational_tree[i] == 1)
                {
                    p = p + q;
                }
            }

            printf("Case #%d: %llu %llu\n", t, p, q);
        }
        else if(id == 2)
        {
            n = 0;
            scanf("%llu %llu", &p, &q);

            while(p != 1 || q != 1)
            {
                if(p > q)
                {
                    p = p - q;
                    rational_tree[rational_tree_count] = 1;
                }
                else if(p < q)
                {
                    q = q - p;
                    rational_tree[rational_tree_count] = 0;
                }

                rational_tree_count++;
            }

            rational_tree[rational_tree_count] = 1;
            rational_tree_count++;

#if USE_LOG
            for(i = 0; i < rational_tree_count; i++)
            {
                printf("%d ", rational_tree[i]);
            }
            printf("\n");
#endif

            for(i = rational_tree_count - 1; i >= 0; i--)
            {
                n *= 2;
                n += rational_tree[i];
            }

            printf("Case #%d: %llu\n", t, n);
        }
    }

    return 0;
}