#include <stdio.h>
#include <string.h>

#define SUBJECT_MAX 1000

int main(void)
{
    int i;
    int N, subject[SUBJECT_MAX], score_max;
    double score_new = 0.0;

    score_max = 0;
    scanf("%d", &N);
    memset(subject, 0x00, N * sizeof(int));

    for(i = 0; i < N; i++)
    {
        scanf("%d", subject + i);

        if(score_max < subject[i])
        {
            score_max = subject[i];
        }
    }

    for(i = 0; i < N; i++)
    {
        score_new = score_new + (double)subject[i] / score_max * 100;
    }
    score_new = score_new / N;

    printf("%.6lf", score_new);

    return 0;
}
