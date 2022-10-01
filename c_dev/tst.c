#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    int step = 0;
    printf("Step %d:\n", step++);
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");

    if (n > 2)
    {
        for (int i = 1, j = n - 2; i < (int)ceil(n / 2); i++, j--)
        {
            for (int k = i; k > 0; k--)
            {
                if (arr[k - 1] > arr[k])
                {
                    long long temp = arr[k - 1];
                    arr[k - 1] = arr[k];
                    arr[k] = temp;
                }
                else
                {
                    break;
                }
            }

            for (int k = j; k < n - 1; k++)
            {
                if (arr[k + 1] > arr[k])
                {
                    long long temp = arr[k + 1];
                    arr[k + 1] = arr[k];
                    arr[k] = temp;
                }
                else
                {
                    break;
                }
            }

            printf("Step %d:\n", step++);
            for (int i = 0; i < n; i++)
            {
                printf("%lld ", arr[i]);
            }
            printf("\n");
        }
    }
}
