#include <stdio.h>
#include <string.h>

#define WORD_MAX_SIZE 101
#define ALPHABET_SIZE 26

int main(void)
{
	int i, word_string_length, alphabet_num[ALPHABET_SIZE];
	char word_string[WORD_MAX_SIZE];

	memset(word_string, 0x00, WORD_MAX_SIZE * sizeof(char));
	memset(alphabet_num, 0x00, ALPHABET_SIZE * sizeof(int));
	for(i = 0; i < ALPHABET_SIZE; i++)
	{
		alphabet_num[i] = -1;
	}

	scanf("%s", word_string);

	word_string_length = strlen(word_string);
	for(i = 0; i < word_string_length; i++)
	{
		if(alphabet_num[word_string[i] - 'a'] == -1)
		{
			alphabet_num[word_string[i] - 'a'] = i;
		}		
	}

	for(i = 0; i < ALPHABET_SIZE; i++)
	{
		printf("%d ", alphabet_num[i]);
	}
	printf("\n");

	return 0;
}
