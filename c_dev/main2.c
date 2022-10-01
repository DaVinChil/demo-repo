#include <stdio.h>
#include <math.h>

int main()
{
    int N, rN = 0, count = 0;
    scanf("%d", &N);
    while (count < 5)
    {
        rN = rN * 10 + N % 10;
        N /= 10;
        ++count;
    }
    printf("%d", rN);
}
