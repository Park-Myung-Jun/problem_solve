#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char get_character;
    bool is_not_space;
    int word_count;

    get_character = 0;
    is_not_space = false;
    word_count = 0;

    while(true)
    {
        get_character = getchar();

        if(get_character == EOF)
        {
            break;
        }

        if(get_character == ' ' || get_character == '\n')
        {
            is_not_space = false;
        }
        else
        {
            if(is_not_space == false)
            {
                word_count++;
                is_not_space = true;
            }
        }
    }

    printf("%d\n", word_count);

    return 0;
}
