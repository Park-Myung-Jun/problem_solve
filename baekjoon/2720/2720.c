#include <stdio.h>

#define REST_UNIT_SIZE 4

int main(void)
{
    int rest_unit[REST_UNIT_SIZE] = {25, 10, 5, 1};

    int i;
    int T, C;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &C);

        for(i = 0; i < REST_UNIT_SIZE; i++)
        {
            printf("%d ", C / rest_unit[i]);
            C %= rest_unit[i];
        }

        printf("\n");
    }

    return 0;
}