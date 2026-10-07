#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int **a = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++)
    {
        left += a[i][i];
        right += a[i][n - 1 - i];
    }

    printf("%d\n", abs(left - right));

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }

    free(a);

    return 0;
}
