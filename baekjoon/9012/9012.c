#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STRING_MAX_SIZE 51

int main(void)
{
    int i;
    int T, string_len;
    char string_parenthesis[STRING_MAX_SIZE];
    char stack[STRING_MAX_SIZE];
    int stack_top;
    bool is_right;

    scanf("%d", &T);
    while(T--)
    {
        memset(string_parenthesis, 0x00, sizeof(char) * STRING_MAX_SIZE);
        memset(stack, 0x00, sizeof(char) * STRING_MAX_SIZE);
        stack_top = 0;
        is_right = true;

        scanf("%s", string_parenthesis);
        string_len = strlen(string_parenthesis);

        for(i = 0; i < string_len; i++)
        {
            if(string_parenthesis[i] == '(')
            {
                stack[stack_top] = '(';
                stack_top++;
            }
            else
            {
                if(stack_top == 0)
                {
                    is_right = false;
                }
                else
                {
                    stack[stack_top - 1] = '\0';
                    stack_top--;
                }
            }
        }

        if(stack_top != 0)
        {
            is_right = false;
        }

        if(is_right)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
