#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define GRAVITY_ACCELATE 9.8

double get_theta(int V, int D)
{
    double ret = 0.0;

    ret = asin(GRAVITY_ACCELATE * D / V / V);

    if(isnan(ret))
    {
        ret = 45.0;
    }
    else
    {
        ret = ret * 180 / M_PI / 2;
    }

    //printf("%lf\n", ret);

    return ret;
}

int main(void)
{
    int T, t, V, D;
    double ans;

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        ans = 0.0;
        scanf("%d %d", &V, &D);

        ans = get_theta(V, D);

        printf("Case #%d: %.7lf\n", t, ans);
    }

    return 0;
}