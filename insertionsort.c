#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (temp < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void main()
{
    printf("*******************IMPLEMENTATION OF INSERTION SORT*******************\n");
    int n = 30000;
    int a[n];
    clock_t start1, start2, start3, end1, end2, end3, total1, total2, total3;
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    start1 = clock();
    insertionSort(a, n);
    end1 = clock();
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    start2 = clock();
    insertionSort(a, n);
    end2 = clock();
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start3 = clock();
    insertionSort(a, n);
    end3 = clock();
    total1 = end1 - start1;
    total2 = end2 - start2;
    total3 = end3 - start3;
    printf("BEST CASE: %ld\n", total1);
    printf("AVG CASE: %ld\n", total2);
    printf("WORST CASE: %ld\n", total3);
}