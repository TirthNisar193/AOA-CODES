#include <stdio.h>
int max(int i, int j, int a[])
{

    if (i == j)
    {
        return a[i];
    }
    if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            return a[i];
        }
        if (a[j] > a[i])
        {
            return a[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1 = max(i, mid, a);
        int max2 = max(mid + 1, j, a);

        if (max1 > max2)
        {
            return max1;
        }
        else
        {
            return max2;
        }
    }
}

int min(int i, int j, int a[])
{
    if (i == j)
    {
        return a[i];
    }
    if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            return a[j];
        }
        if (a[j] > a[i])
        {
            return a[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int min1 = min(i, mid, a);
        int min2 = min(mid + 1, j, a);

        if (min1 > min2)
        {
            return min2;
        }
        else
        {
            return min1;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int mini = min(0, n - 1, a);
    int maxi = max(0, n - 1, a);
    printf("minimum element is: %d\n", mini);
    printf("maximum element is: %d\n", maxi);

    return 0;
}