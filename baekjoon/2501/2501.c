#include <stdio.h>
#include <string.h>

#define NUM_MAX_SIZE 10000

int main(void)
{
	int i;
	int N, K;
	int aliquot_array[NUM_MAX_SIZE], aliquot_array_count;
	scanf("%d %d", &N, &K);

	memset(aliquot_array, 0x00, NUM_MAX_SIZE * sizeof(int));
	aliquot_array_count = 0;

	for(i = 1; i <= N; i++)
	{
		if(N % i == 0)
		{
			aliquot_array[aliquot_array_count] = i;
			aliquot_array_count++;
		}
	}

	if(aliquot_array_count < K)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", aliquot_array[K - 1]);
	}

	return 0;
}
