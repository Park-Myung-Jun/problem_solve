#include <stdio.h>
#include <string.h>

#define WORD_MAX_SIZE 54
#define SURPRIZE "\?\?!"
#define SURPRIZE_LENGTH 3

int main(void)
{
    int i, word_length;
    char word[WORD_MAX_SIZE];

    memset(word, 0x00, WORD_MAX_SIZE * sizeof(char));

    scanf("%s", word);
    word_length = strlen(word);

    for(i = word_length; i < word_length + SURPRIZE_LENGTH; i++)
    {
        word[i] = SURPRIZE[i - word_length];
    }

    printf("%s\n", word);

    return 0;
}
