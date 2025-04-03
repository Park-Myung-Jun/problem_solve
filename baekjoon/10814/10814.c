#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USER_MAX 100000
#define NAME_MAX_LENGTH 101

typedef struct _tsUser {
    int age;
    int regist;
    char name[NAME_MAX_LENGTH];
} tsUser;

tsUser user[USER_MAX];

int algo_function(const void* p_a, const void* p_b)
{
    tsUser a = *(tsUser const*)p_a;
    tsUser b = *(tsUser const*)p_b;

    int compare_age = (a.age > b.age) - (a.age < b.age);
    if(compare_age != 0)
    {
        return compare_age;
    }
    else
    {
        return (a.regist > b.regist) - (a.regist < b.regist);
    }
}

int main(void)
{
    int i;
    int N;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d %s", &user[i].age, user[i].name);
        user[i].regist = i;
    }

    qsort(user, N, sizeof(tsUser), algo_function);

    for(i = 0; i < N; i++)
    {
        printf("%d %s\n", user[i].age, user[i].name);
    }

    return 0;
}
