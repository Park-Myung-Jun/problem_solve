#include <stdio.h>

#define FIBO_MAX_SIZE 40

int g_fr, g_fd;

void g_fr_count(void)
{
    g_fr++;
}

void g_fd_count(void)
{
    g_fd++;
}

int fibo_recursive(int p_n)
{
    if(p_n == 1 || p_n == 2)
    {
        g_fr_count();
        return 1;
    }

    return fibo_recursive(p_n - 1) + fibo_recursive(p_n - 2);
}

int fibo_dinamic(int p_n)
{
    int i;
    int fibo_array[FIBO_MAX_SIZE] = {1, 1};

    for(i = 2; i < p_n; i++)
    {
        g_fd_count();
        fibo_array[i] = fibo_array[i - 1] + fibo_array[i - 2];
    }

    return fibo_array[i - 1];
}

int main(void)
{
    int n;
    g_fr = 0;
    g_fd = 0;

    scanf("%d", &n);

    fibo_recursive(n);
    fibo_dinamic(n);

    printf("%d %d\n", g_fr, g_fd);

    return 0;
}
