#include <stdio.h>
#include <string.h>

#define SEQUENCE_MAX 100000

int main(void)
{
    int i;
    int n, seq[SEQUENCE_MAX], save[SEQUENCE_MAX], sum_max;

    scanf("%d", &n);
    memset(seq, 0x00, SEQUENCE_MAX);
    memset(save, 0x00, SEQUENCE_MAX);

    scanf("%d", seq);
    sum_max = seq[0];
    save[0] = seq[0];

    for(i = 1; i < n; i++)
    {
        scanf("%d", seq + i);
        if(save[i - 1] + seq[i] < seq[i])
        {
            save[i] = seq[i];
        }
        else
        {
            save[i] = save[i - 1] + seq[i];
        }

        if(sum_max < save[i])
        {
            sum_max = save[i];
        }
    }

    printf("%d\n", sum_max);

    return 0;
}
