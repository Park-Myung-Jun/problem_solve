#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX_SIZE 101
#define CROATIA_ALPHABET_SIZE 8

int main(void)
{
	int i, j, k;
	int word_string_length, alphabet_count, croatia_alphabet_length;
	char word_string[WORD_MAX_SIZE];
	char* croatia_alphabet[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	bool is_croatia_alpha;

	memset(word_string, 0x00, WORD_MAX_SIZE * sizeof(char));
	alphabet_count = 0;

	scanf("%s", word_string);

	word_string_length = strlen(word_string);
	for(i = 0; i < word_string_length; i++)
	{
		for(j = 0; j < CROATIA_ALPHABET_SIZE; j++)
		{
			if(word_string[i] == croatia_alphabet[j][0])
			{
				croatia_alphabet_length = strlen(croatia_alphabet[j]);
				is_croatia_alpha = true;

				for(k = 0; k < croatia_alphabet_length; k++)
				{
					if(word_string[i + k] != croatia_alphabet[j][k])
					{
						is_croatia_alpha = false;
						break;
					}
				}

				if(is_croatia_alpha)
				{
					i += croatia_alphabet_length;
					i--;
				}
			}
		}

		alphabet_count++;
	}

	printf("%d\n", alphabet_count);

	return 0;
}
