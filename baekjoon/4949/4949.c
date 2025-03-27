#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

#define SENTENCE_MAX_SIZE 102

int main(void)
{
    int i;
    int sentence_length, stack_top;
    char sentence[SENTENCE_MAX_SIZE], stack[SENTENCE_MAX_SIZE];
    bool is_right;

    while(true)
    {
        is_right = true;
        stack_top = 0;
        memset(stack, 0x00, sizeof(char) * SENTENCE_MAX_SIZE);
        memset(sentence, 0x00, sizeof(char) * SENTENCE_MAX_SIZE);
        fgets(sentence, SENTENCE_MAX_SIZE, stdin);

        sentence_length = strlen(sentence);

        if(sentence[0] == '.')
        {
            break;
        }

        for(i = 0; i < sentence_length; i++)
        {
            if(sentence[i] == '(' || sentence[i] == '[')
            {
                stack[stack_top] = sentence[i];
                stack_top++;
            }

            if(sentence[i] == ')')
            {
                if(stack_top == 0)
                {
                    is_right = false;
                    break;
                }

                if(stack[stack_top - 1] == '(')
                {
                    stack_top--;
                }
                else
                {
                    is_right = false;
                    break;
                }
            }

            if(sentence[i] == ']')
            {
                if(stack_top == 0)
                {
                    is_right = false;
                    break;
                }

                if(stack[stack_top - 1] == '[')
                {
                    stack_top--;
                }
                else
                {
                    is_right = false;
                    break;
                }
            }
        }

        if(stack_top != 0)
        {
            is_right = false;
        }

        if(is_right)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}
