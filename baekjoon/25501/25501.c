#include <stdio.h>
#include <string.h>

#define STRING_MAX 1001

int recursion_count;

int recursion(const char *s, int l, int r){
    recursion_count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(void)
{
    int T;
    char S[STRING_MAX];

    scanf("%d", &T);
    while(T--)
    {
        recursion_count = 0;
        memset(S, 0x00, sizeof(char) * STRING_MAX);

        scanf("%s", S);
        printf("%d ", isPalindrome(S));
        printf("%d\n", recursion_count);
    }

    return 0;
}
