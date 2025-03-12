#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USE_LOG 0

#define NUMBER_MAX_LENGTH 101
#define FORMAT_MAX_LENGTH 200
#define FORMAT_TOKENIZE_MAX_LENGTH 100
#define FORMAT_TOKEN "-"

int main(void)
{
    char* num_string[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char* num_seq_read[] = {"", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};

    int i, j, k;
    int t, T;
    char phone_number[NUMBER_MAX_LENGTH], phone_format[FORMAT_MAX_LENGTH];
    int phone_format_tokenize[FORMAT_TOKENIZE_MAX_LENGTH], phone_format_tokenize_count;

    int phone_number_position, sequence_count;
    char base;

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        memset(phone_number, 0x00, NUMBER_MAX_LENGTH * sizeof(char));
        memset(phone_format, 0x00, FORMAT_MAX_LENGTH * sizeof(char));
        memset(phone_format_tokenize, 0x00, FORMAT_TOKENIZE_MAX_LENGTH * sizeof(int));
        scanf("%s", phone_number);
        scanf("%s", phone_format);

#if USE_LOG
        printf("%s %s\n", phone_number, phone_format);
#endif

        phone_format_tokenize_count = 0;

        char* token = strtok(phone_format, FORMAT_TOKEN);
        while(token)
        {
            phone_format_tokenize[phone_format_tokenize_count] = atoi(token);
            phone_format_tokenize_count++;

            token = strtok(NULL, FORMAT_TOKEN);
        }

#if USE_LOG
        for(i = 0; i < phone_format_tokenize_count; i++)
        {
            printf("%d ", phone_format_tokenize[i]);
        }
        printf("\n");
#endif

        printf("Case #%d: ", t);

        phone_number_position = 0;
        for(i = 0; i < phone_format_tokenize_count; i++)
        {
            base = phone_number[phone_number_position];
            sequence_count = 1;

            for(j = 1; j < phone_format_tokenize[i]; j++)
            {
                if(base == phone_number[phone_number_position + j])
                {
                    sequence_count++;
                }
                else
                {
                    if(1 < sequence_count && sequence_count < 11)
                    {
                        printf("%s ", num_seq_read[sequence_count]);
                    }
                    else if(10 < sequence_count)
                    {
                        for(k = 0; k < sequence_count - 1; k++)
                        {
                            printf("%s ", num_string[base - '0']);
                        }
                    }
                    printf("%s ", num_string[base - '0']);

                    sequence_count = 1;
                    base = phone_number[phone_number_position + j];
                }
            }

            if(1 < sequence_count && sequence_count < 11)
            {
                printf("%s ", num_seq_read[sequence_count]);
            }
            else if(10 < sequence_count)
            {
                for(k = 0; k < sequence_count - 1; k++)
                {
                    printf("%s ", num_string[base - '0']);
                }
            }
            printf("%s ", num_string[base - '0']);

            phone_number_position += phone_format_tokenize[i];
        }

        printf("\n");
    }

    return 0;
}