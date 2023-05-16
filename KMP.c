// KNUTH MORRIS PRATT
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i, pi[50], k, q;
    char p[50], t[50];
    printf("Enter the length of the pattern string ");
    scanf("%d", &m);
    printf("Enter the pattern string ");
    for (i = 0; i <= m - 1; i++)
    {
        scanf("%s", &p[i]);
    }

    printf("Enter the length of the text string ");
    scanf("%d", &n);
    printf("Enter the text string ");
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%s", &t[i]);
    }

    pi[0] = 0;
    k = 0;
    for (q = 1; q <= m - 1; q++)
    {
        while (k > 0 && p[k] != p[q])
        {
            k = pi[k - 1];
        }
        if (p[k] == p[q])
        {
            k = k + 1;
        }
        pi[q] = k;
    }

    printf("Prefix code for pattern is ");
    for (i = 0; i <= m - 1; i++)
    {
        printf("%d", pi[i]);
    }

    k = 0;
    for (q = 1; q <= n - 1; q++)
    {
        while (k > 0 && p[k] != t[q])
        {
            k = pi[k - 1];
        }
        if (p[k] == t[q])
        {
            k = k + 1;
        }
        if (k == m)
        {
            printf("\nPattern occurs with shift %d", q - m + 1);
            k = pi[k];
        }
    }
    return 0;
}
