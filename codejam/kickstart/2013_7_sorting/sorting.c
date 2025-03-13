#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define USE_LOG 0

#define BOOK_MAX_SIZE 1000

int sort_increase(const void *a, const void *b)
{
    int left = *(const int *)a;
    int right = *(const int *)b;

    return (left > right) - (left < right);
}

int sort_decrease(const void *a, const void *b)
{
    int left = *(const int *)a;
    int right = *(const int *)b;

    return (left < right) - (left > right);
}

int main(void)
{
    int i;
    int t, T;
    int book_array[BOOK_MAX_SIZE], book_sort[BOOK_MAX_SIZE], N, book_sort_count;
    bool book_check[BOOK_MAX_SIZE];

    scanf("%d", &T);

    for(t = 1; t <= T; t++)
    {
        scanf("%d", &N);

        memset(book_array, 0x00, BOOK_MAX_SIZE * sizeof(int));
        memset(book_check, 0x00, BOOK_MAX_SIZE * sizeof(bool));
        memset(book_sort, 0x00, BOOK_MAX_SIZE * sizeof(int));
        book_sort_count = 0;

        for(i = 0 ; i < N; i++)
        {
            scanf("%d", book_array + i);

            if((book_array[i] % 2 + 2) % 2 == 1)
            {
                book_check[i] = true;
            }
            else
            {
                book_sort[book_sort_count] = book_array[i];
                book_sort_count++;
            }
        }

        // even
        qsort(book_sort, book_sort_count, sizeof(int), sort_decrease);
        book_sort_count = 0;
        for(i = 0 ; i < N; i++)
        {
            if(book_check[i] == 0)
            {
                book_array[i] = book_sort[book_sort_count];
                book_sort_count++;
            }
        }

        // odd
        memset(book_sort, 0x00, BOOK_MAX_SIZE * sizeof(int));
        book_sort_count = 0;
        for(i = 0 ; i < N; i++)
        {
            if(book_check[i] == true)
            {
                book_sort[book_sort_count] = book_array[i];
                book_sort_count++;
            }
        }

        qsort(book_sort, book_sort_count, sizeof(int), sort_increase);
        book_sort_count = 0;
        for(i = 0 ; i < N; i++)
        {
            if(book_check[i] == 1)
            {
                book_array[i] = book_sort[book_sort_count];
                book_sort_count++;
            }
        }

#if USE_LOG
        printf("%d %d %d\n", 0 % 2, -5 % 2, -12 % 2);
        for(i = 0 ; i < N; i++)
        {
            printf("%d ", book_check[i]);
        }
        printf("\n");
#endif

        printf("Case #%d: ", t);
        for(i = 0 ; i < N; i++)
        {
            printf("%d ", book_array[i]);
        }
        printf("\n");
    }

    return 0;
}