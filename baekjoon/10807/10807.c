#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 201
#define SAVE_OFFSET 100

int main(void)
{
    int i;
    int N, v, num_save[ARRAY_SIZE];

    memset(num_save, 0x00, ARRAY_SIZE * sizeof(int));

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &v);
        num_save[v + SAVE_OFFSET]++;
    }

    scanf("%d", &v);
    printf("%d\n", num_save[v + SAVE_OFFSET]);

    return 0;
}