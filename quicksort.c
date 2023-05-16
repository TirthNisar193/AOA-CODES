#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int a[], int low, int high)
{
    int i = low + 1;
    int j = high;
    while (j > i)
    {
        while (a[i] <= a[low])
        {
            i++;
        }
        while (a[j] > a[low])
        {
            j--;
        }
        if (j > i)
        {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        int temp = a[j];
        a[j] = a[low];
        a[low] = temp;
        return j;
    }
}
void quicksort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int pivot = partition(a, low, high);
        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
}
void main()
{
    int n = 30000;
    int a[n];
    clock_t start1, start2, start3, end1, end2, end3, total1, total2, total3;
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    start1 = clock();
    quicksort(a, 0, n);
    end1 = clock();
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    start2 = clock();
    quicksort(a, 0, n);
    end2 = clock();
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start3 = clock();
    quicksort(a, 0, n);
    end3 = clock();
    total1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    total2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    total3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    printf("BEST CASE: %ld\n", total1);
    printf("AVG CASE: %ld\n", total2);
    printf("WORST CASE: %ld\n", total3);
}