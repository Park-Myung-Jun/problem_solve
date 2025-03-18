#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DICE_COUNT 3
#define DICE_MAX_NUM 6

int main(void)
{
    int i;
    int Dice, Dice_Calc_Prize[DICE_MAX_NUM], num_max;
    bool is_not_once = false;

    num_max = 0;
    memset(Dice_Calc_Prize, 0x00, DICE_MAX_NUM * sizeof(int));

    for(i = 0; i < DICE_COUNT; i++)
    {
        scanf("%d", &Dice);
        Dice_Calc_Prize[Dice - 1]++;
        if(num_max < Dice)
        {
            num_max = Dice;
        }
    }

    for(i = 0; i < DICE_MAX_NUM; i++)
    {
        if(Dice_Calc_Prize[i] == 3)
        {
            printf("%d\n", 10000 + 1000 * (i + 1));
            is_not_once = true;
            break;
        }

        if(Dice_Calc_Prize[i] == 2)
        {
            printf("%d\n", 1000 + 100 * (i + 1));
            is_not_once = true;
            break;
        }
    }

    if(is_not_once == false)
    {
        printf("%d\n", 100 * num_max);
    }

    return 0;
}
