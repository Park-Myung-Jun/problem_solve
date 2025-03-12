#include <stdio.h>

int find_dot_num(int sequence)
{
    int i;
    int line_dot = 2;

    for(i = 0; i < sequence; i++)
    {
        line_dot = line_dot * 2 - 1;
    }

    return line_dot * line_dot;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    printf("%d\n", find_dot_num(N));

    return 0;
}