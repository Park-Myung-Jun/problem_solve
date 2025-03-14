#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define USE_LOG 0

#define ROOM_MAX_SIZE 1000

typedef struct _ts_room_info {
	uint16_t time;
	bool is_movable;
} ts_room_info;

ts_room_info room_relation_graph[ROOM_MAX_SIZE][ROOM_MAX_SIZE];

uint8_t number_mapping(char alpha)
{
	if('0' <= alpha && alpha <= '9')
	{
		return (int)(alpha - '0');
	}
	else if('a' <= alpha && alpha <= 'z')
	{
		return (int)(alpha - 'a' + 10);
	}
}

uint8_t color_to_num(char color[3])
{
	return (number_mapping(color[0]) * 36 + number_mapping(color[1]) + 1);
}

void find_path(ts_room_info p_room[][ROOM_MAX_SIZE], int* p_path_worth, int p_start, int p_end)
{
	int i, j;
	int queue_rear = 0, queue_front = 0, queue_pop = 0;
	int queue_room[ROOM_MAX_SIZE] = {0};

	p_path_worth[p_start] = 0;
	
	//queue push
	queue_room[queue_rear] = p_start;
	queue_rear = (queue_rear + 1) % ROOM_MAX_SIZE;

	while(queue_front != queue_rear)
	{
		//queue pop
		queue_pop = queue_room[queue_front];
		queue_front = (queue_front + 1) % ROOM_MAX_SIZE;

#if USE_LOG
		printf("qp %d\n", queue_pop);
#endif

		for(i = 0; i < ROOM_MAX_SIZE; i++)
		{	
			if(p_room[queue_pop][i].is_movable == true)
			{
#if USE_LOG
				printf("path check %d %d %d\n", queue_pop, i, p_path_worth[queue_pop] + p_room[queue_pop][i].time);
#endif

				if(p_path_worth[i] != -1 && p_path_worth[i] <= p_path_worth[queue_pop] + p_room[queue_pop][i].time)
				{
					continue;
				}

				p_path_worth[i] = p_path_worth[queue_pop] + p_room[queue_pop][i].time;
				queue_room[queue_rear] = i;
				queue_rear = (queue_rear + 1) % ROOM_MAX_SIZE;
			}
		}
	}
}

int main(void)
{
	int i, j;
	int T, t;
	int N, M, S;
	int start, end, time;
	char get_color[3];
	int color_num[ROOM_MAX_SIZE];
	int path_worth[ROOM_MAX_SIZE];

	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		for(i = 0; i < ROOM_MAX_SIZE; i++)
		{
			memset(room_relation_graph[i], 0x00, ROOM_MAX_SIZE * sizeof(ts_room_info));
		}

		scanf("%d", &N);
		memset(color_num, 0x00, ROOM_MAX_SIZE * sizeof(int));
		for(i = 0; i < N; i++)
		{
			scanf("%s", get_color);
			//printf("get color : %s\n", get_color);
			color_num[i] = color_to_num(get_color);
		}

		scanf("%d", &M);
		//printf("M %d\n", M);
		for(i = 0; i < M; i++)
		{
			scanf("%d %d %d", &start, &end, &time);
			//printf("%d : %d %d %d\n", i, start, end, time);

			room_relation_graph[start - 1][end - 1].is_movable = true;
			room_relation_graph[start - 1][end - 1].time = time;
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(i != j && color_num[i] == color_num[j])
				{
					room_relation_graph[i][j].is_movable = true;
					room_relation_graph[i][j].time = 0;

					room_relation_graph[j][i].is_movable = true;
					room_relation_graph[j][i].time = 0;
				}
			}
		}

#if USE_LOG
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				printf("%d %d | ", room_relation_graph[i][j].is_movable, room_relation_graph[i][j].time);
			}
			printf("\n");
		}
#endif

		printf("Case #%d:\n", t);

		scanf("%d", &S);
		//printf("S %d\n", S);
		for(i = 0; i < S; i++)
		{
			scanf("%d %d", &start, &end);
			//printf("%d : %d %d\n", i, start, end);
			memset(path_worth, 0xFF, ROOM_MAX_SIZE * sizeof(int));

			find_path(room_relation_graph, path_worth, start - 1, end - 1);

#if USE_LOG
			for(j = 0; j < N; j++)
			{
				printf("%d ", path_worth[j]);
			}
			printf("\n");
#endif

			printf("%d\n", path_worth[end - 1]);
		}
	}

	return 0;
}

