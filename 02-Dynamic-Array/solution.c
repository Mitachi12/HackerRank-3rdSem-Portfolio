#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int **seq = malloc(n * sizeof(int *));
    int *size = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        seq[i] = NULL;
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++)
    {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int index = (x ^ lastAnswer) % n;

        if (type == 1)
        {
            seq[index] = realloc(seq[index],
                                 (size[index] + 1) * sizeof(int));

            seq[index][size[index]] = y;
            size[index]++;
        }
        else if (type == 2)
        {
            lastAnswer = seq[index][y % size[index]];
            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(seq[i]);
    }

    free(seq);
    free(size);

    return 0;
}
