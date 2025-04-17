/*
merge_sort(A[p..r]) { # A[p..r]을 오름차순 정렬한다.
    if (p < r) then {
        q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
        merge_sort(A, p, q);      # 전반부 정렬
        merge_sort(A, q + 1, r);  # 후반부 정렬
        merge(A, p, q, r);        # 병합
    }
}

# A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
# A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
merge(A[], p, q, r) {
    i <- p; j <- q + 1; t <- 1;
    while (i ≤ q and j ≤ r) {
        if (A[i] ≤ A[j])
        then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
        else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
    }
    while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
        tmp[t++] <- A[i++];
    while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
        tmp[t++] <- A[j++];
    i <- p; t <- 1;
    while (i ≤ r)  # 결과를 A[p..r]에 저장
        A[i++] <- tmp[t++];
}
*/

#include <stdio.h>
#include <string.h>

#define ARRAY_MAX 500000

int tmp[ARRAY_MAX], A[ARRAY_MAX], count = 0, timing = 0, ans;

void merge_count(int value)
{
    //printf("%d %d\n", count, value);
    count++;
    if(count == timing)
    {
        ans = value;
    }
}

void merge(int * A, int p, int q, int r)
{
    int i = p, j = q + 1, t = 0;
    //memset(tmp, 0x00, sizeof(int) * r);

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
        {
            tmp[t] = A[i];
            merge_count(tmp[t]);
            t++;
            i++;
        }
        else
        {
            tmp[t] = A[j];
            merge_count(tmp[t]);
            t++;
            j++;
        }
    }

    while (i <= q)
    {
        tmp[t] = A[i];
        merge_count(tmp[t]);
        t++;
        i++;
    }

    while (j <= r)
    {
        tmp[t] = A[j];
        merge_count(tmp[t]);
        t++;
        j++;
    }

    i = p;
    t = 0;

    while (i <= r)
    {
        A[i] = tmp[t];
        i++;
        t++;
    }
}

void merge_sort(int* A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main(void)
{
    int i;
    int N, K;

    scanf("%d %d", &N, &K);
    timing = K;
    for(i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }

    merge_sort(A, 0, N - 1);

    if(count < K)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", ans);
    }

    return 0;
}
