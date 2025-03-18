#include <stdio.h>
#include <string.h>

#define STRING_MAX_SIZE 21

int main(void)
{
    int i, j;
    int t, T;
    int R, alphanumeric_length;
    char alphanumeric[STRING_MAX_SIZE];

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        memset(alphanumeric, 0x00, STRING_MAX_SIZE * sizeof(char));
        scanf("%d %s", &R, alphanumeric);
        alphanumeric_length = strlen(alphanumeric);

        for(i = 0; i < alphanumeric_length; i++)
        {
            for(j = 0; j < R; j++)
            {
                printf("%c", alphanumeric[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
