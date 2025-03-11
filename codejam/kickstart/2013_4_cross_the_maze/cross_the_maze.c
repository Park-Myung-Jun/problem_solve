#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAP_MAX_SIZE 100
#define STEP_LOG_MAX 10001
#define DIRECTION_SIZE 4

int main(void)
{
	int direction_table[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};
	char direction_mapping[4] = {'E', 'S', 'W', 'N'}; // 0 E 1 S 2 W 3 N

	int i, j;
	int t, T;
	int N, sx, sy, ex, ey;
	char map[MAP_MAX_SIZE][MAP_MAX_SIZE + 1];
	bool is_all_block, is_left_wall_existed, is_wall_set;
	char step_log[STEP_LOG_MAX] = {0};
	int direction, step_log_count, fuel;
	int now_y, now_x, next_y, next_x, check_y, check_x;

	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		//init
		is_all_block = true;
        is_left_wall_existed = false;
        is_wall_set = false;
		direction = 0;
		step_log_count = 0;
		fuel = STEP_LOG_MAX - 1;
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			memset(map[i], 0x00, (MAP_MAX_SIZE + 1) * sizeof(char));
			scanf("%s", map[i]);
		}
		memset(step_log, 0x00, STEP_LOG_MAX * sizeof(char));
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

		now_y = sy - 1;
		now_x = sx - 1;

        // find direction
        for(i = 0; i < DIRECTION_SIZE; i++)
        {
            check_y = now_y + direction_table[0][(direction + i) % DIRECTION_SIZE];
            check_x = now_x + direction_table[1][(direction + i) % DIRECTION_SIZE];

            if(!is_wall_set && (check_y < 0 || N - 1 < check_y || check_x < 0 || N - 1 < check_x || map[check_y][check_x] == '#'))
            {
                is_wall_set = true;
            }

            if(is_wall_set && 0 <= check_y && check_y < N && 0 <= check_x && check_x < N && map[check_y][check_x] == '.')
            {
                direction = (direction + i) % DIRECTION_SIZE;
                break;
            }
        }

		while(fuel)
		{
            //printf("now : %d %d %d %d\n", now_y, now_x, direction, is_left_wall_existed);

            if(is_left_wall_existed)
            {
                check_y = now_y + direction_table[0][(direction + 3) % DIRECTION_SIZE];
                check_x = now_x + direction_table[1][(direction + 3) % DIRECTION_SIZE];
                if(0 <= check_y && check_y < N && 0 <= check_x && check_x < N && map[check_y][check_x] == '.')
                {
                    direction = (direction + 3) % DIRECTION_SIZE;
                }
            }

            is_left_wall_existed = false;

			for(i = 0; i < DIRECTION_SIZE; i++)
			{
				next_y = now_y + direction_table[0][(direction + i) % DIRECTION_SIZE];
				next_x = now_x + direction_table[1][(direction + i) % DIRECTION_SIZE];

				//printf("next %d %d %d\n", next_y, next_x, direction);

				if(0 <= next_y && next_y < N && 0 <= next_x && next_x < N && map[next_y][next_x] == '.')
				{
                    check_y = now_y + direction_table[0][(direction + 3) % DIRECTION_SIZE];
                    check_x = now_x + direction_table[1][(direction + 3) % DIRECTION_SIZE];
                    if(check_y < 0 || N - 1 < check_y || check_x < 0 || N - 1 < check_x || map[check_y][check_x] == '#')
                    {
                        is_left_wall_existed = true;
                    }

					is_all_block = false;
					direction = (direction + i) % DIRECTION_SIZE;
					break;
				}
			}

			if(is_all_block)
			{
				break;
			}

			// move
			now_y = next_y;
			now_x = next_x;

			step_log[step_log_count] = direction_mapping[direction];
			step_log_count++;

			if(next_y == ey - 1 && next_x == ex - 1)
			{
				break;
			}

			fuel--;
		}

		if(fuel == 0 || is_all_block == true)
		{
			printf("Case #%d: Edison ran out of energy.\n", t);
		}
		else
		{
			printf("Case #%d: %d\n", t, step_log_count);
			for(i = 0; i < step_log_count; i++)
			{
				printf("%c", step_log[i]);
			}
			printf("\n");
		}
	}

	return 0;
}