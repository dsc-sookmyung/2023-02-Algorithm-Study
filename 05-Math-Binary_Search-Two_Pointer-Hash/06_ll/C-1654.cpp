#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
 
int K = 0; 
int N = 0; 
 
long long lan[10001] = { 0, };
 
long long binarySearch(long long left, long long right)
{
    while (left <= right)
    {
        int Cnt = 0;
 
        long long middle = (left + right) / 2;
 
        for (int i = 0; i <= K; i++)
        {
            Cnt += lan[i] / middle;
        }
 
        if (Cnt >= N) left = middle + 1;
        else right = middle - 1;
    }
 
    return right;
}
 
int main(void)
{
    long long max = 0;
     
    scanf("%d %d", &K, &N);
 
    for(int i=0; i<K; i++)
    {
        scanf("%lld", &lan[i]);
 
        if (max < lan[i]) max = lan[i];
    }
 
    printf("%lld\n", binarySearch(1, max));
 
    return 0;
}