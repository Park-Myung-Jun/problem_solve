#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_GET 60
#define STRING_TOKENIZER " \n"

double Get_Grade(char* grade_str)
{
    double grade_ret = 0;

    switch(grade_str[0])
    {
        case 'A':
            grade_ret = 4.0;
            break;

        case 'B':
            grade_ret = 3.0;
            break;

        case 'C':
            grade_ret = 2.0;
            break;

        case 'D':
            grade_ret = 1.0;
            break;

        default:
            break;
    }

    if(grade_str[1] == '+')
    {
        grade_ret += 0.5;
    }

    return grade_ret;
}

int main(void)
{
    char string_get[STRING_GET];
    double score_calc;
    double result, grade_score_count;

    result = 0.0;
    grade_score_count = 0;
    memset(string_get, 0x00, STRING_GET * sizeof(char));

    while(fgets(string_get, STRING_GET, stdin) != NULL)
    {
        if(string_get[strlen(string_get) - 1] == '\n')
        {
            string_get[strlen(string_get) - 1] = '\0';
        }

        char* tok = strtok(string_get, STRING_TOKENIZER);
        tok = strtok(NULL, STRING_TOKENIZER);
        score_calc = atof(tok);
        tok = strtok(NULL, STRING_TOKENIZER);
        if(tok[0] != 'P')
        {
            result += (score_calc * Get_Grade(tok));
            grade_score_count += score_calc;
        }

        memset(string_get, 0x00, STRING_GET * sizeof(char));
    }

    result /= grade_score_count;

    printf("%.6lf\n", result);

    return 0;
}
