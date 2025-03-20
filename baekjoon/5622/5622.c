#include <stdio.h>
#include <string.h>

#define LETTER_MAX 16

int Dial_Get_Time(char l)
{
    if(l <= 'O')
    {
        return 3 + (l - 'A') / 3;
    }
    else if(l <= 'S')
    {
        return 8;
    }
    else if(l <= 'V')
    {
        return 9;
    }
    else if(l <= 'Z')
    {
        return 10;
    }
}

int main(void)
{
    int i;
    int time_total, letter_length;
    char letter[LETTER_MAX];
    memset(letter, 0x00, LETTER_MAX * sizeof(char));
    scanf("%s", letter);

    time_total = 0;
    letter_length = strlen(letter);

    for(i = 0; i < letter_length; i++)
    {
        time_total += Dial_Get_Time(letter[i]);
        //printf("%d ", Dial_Get_Time(letter[i]));
    }

    printf("%d\n", time_total);

    return 0;
}
