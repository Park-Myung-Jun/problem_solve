#include <stdio.h>

#define HOUR_TIMES_MINUTE 1440

int main(void)
{
	int A, B, C, End_Time;

	scanf("%d %d %d", &A, &B, &C);

	End_Time = (A * 60 + B + C) % HOUR_TIMES_MINUTE;

	printf("%d %d\n", End_Time / 60, End_Time % 60);

	return 0;
}
