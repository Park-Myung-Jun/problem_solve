#include <stdio.h>
#include <string.h>

#define BALL_BASKET_MAX_SIZE 100

int main(void)
{
	int i;
	int N, M, ball_1, ball_2, ball_array[BALL_BASKET_MAX_SIZE], tmp;

	memset(ball_array, 0x00, BALL_BASKET_MAX_SIZE * sizeof(int));
	scanf("%d %d", &N, &M);

	for(i = 0; i < N; i++)
	{
		ball_array[i] = i + 1;
	}

	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &ball_1, &ball_2);

		tmp = ball_array[ball_1 - 1];
		ball_array[ball_1 - 1] = ball_array[ball_2 - 1];
		ball_array[ball_2 - 1] = tmp;
	}

	for(i = 0; i < N; i++)
	{
		printf("%d ", ball_array[i]);
	}
	printf("\n");

	return 0;
}
