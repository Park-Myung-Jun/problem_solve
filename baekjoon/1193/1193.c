#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int i;
	int X, pos_y, pos_x;
	scanf("%d", &X);

	i = 1;
	while(true)
	{
		if(X <= i * (i + 1) / 2)
		{
			X -= (i * (i - 1) / 2);
			break;
		}
	
		i++;
	}

	if(i % 2 == 1)
	{
		pos_y = i - (X - 1);
		pos_x = 1 + (X - 1);
	}
	else
	{
		pos_y = 1 + (X - 1);
		pos_x = i - (X - 1);
	}

	printf("%d/%d\n", pos_y, pos_x);

	return 0;
}
