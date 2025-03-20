#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define POINT_MAX 3

typedef struct _tsPoint
{
    int Y;
    int X;
} tsPoint;

void Point_Check_X(tsPoint* p_point, bool* p_point_check)
{
    int i, j;

    for(i = 0; i < POINT_MAX - 1; i++)
    {
        for(j = i + 1; j < POINT_MAX; j++)
        {
            if(p_point[i].X == p_point[j].X)
            {
                p_point_check[i] = true;
                p_point_check[j] = true;

                return;
            }
        }
    }
}

void Point_Check_Y(tsPoint* p_point, bool* p_point_check)
{
    int i, j;

    for(i = 0; i < POINT_MAX - 1; i++)
    {
        for(j = i + 1; j < POINT_MAX; j++)
        {
            if(p_point[i].Y == p_point[j].Y)
            {
                p_point_check[i] = true;
                p_point_check[j] = true;

                return;
            }
        }
    }
}

int main(void)
{
    int i, j;
    bool point_check[POINT_MAX];
    tsPoint point[POINT_MAX];
    for(i = 0; i < POINT_MAX; i++)
    {
        scanf("%d %d", &point[i].X, &point[i].Y);
    }

    memset(point_check, 0x00, POINT_MAX * sizeof(bool));
    Point_Check_X(point, point_check);

    for(int i = 0; i < POINT_MAX; i++)
    {
        if(point_check[i] == false)
        {
            printf("%d ", point[i].X);
            break;
        }
    }

    memset(point_check, 0x00, POINT_MAX * sizeof(bool));
    Point_Check_Y(point, point_check);

    for(int i = 0; i < POINT_MAX; i++)
    {
        if(point_check[i] == false)
        {
            printf("%d\n", point[i].Y);
            break;
        }
    }

    return 0;
}
