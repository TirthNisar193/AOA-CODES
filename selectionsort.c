#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = a[i];
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                k = j;
            }
        }
        int temp = a[i];
        a[i] = min;
        a[k] = temp;
    }
}

void main()
{
    printf("*******************IMPLEMENTATION OF SELECTION SORT*******************\n");
    int n = 30000;
    int a[n];
    clock_t start1, start2, start3, end1, end2, end3, total1, total2, total3;
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    start1 = clock();
    selectionSort(a, n);
    end1 = clock();
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    start2 = clock();
    selectionSort(a, n);
    end2 = clock();
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start3 = clock();
    selectionSort(a, n);
    end3 = clock();
    total1 = end1 - start1;
    total2 = end2 - start2;
    total3 = end3 - start3;
    printf("BEST CASE: %ld\n", total1);
    printf("AVG CASE: %ld\n", total2);
    printf("WORST CASE: %ld\n", total3);
}