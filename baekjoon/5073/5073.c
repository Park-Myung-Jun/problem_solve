#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a, b, c;

    while(true)
    {
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0 && b == 0 && c == 0)
        {
            break;
        }

        if(a == b && b == c)
        {
            printf("Equilateral\n");
        }
        else if(a + b <= c || b + c <= a || c + a <= b)
        {
            printf("Invalid\n");
        }
        else if(a == b || b == c || c == a)
        {
            printf("Isosceles\n");
        }
        else
        {
            printf("Scalene\n");
        }
    }

    return 0;
}
