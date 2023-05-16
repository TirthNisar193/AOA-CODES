#include <stdio.h>
struct node
{
    int weight;
    int id;
    int profit;
    float pbyw;
} knapsack;
void main()
{
    int n, capacity, i, j, min;
    float profit;
    struct node temp;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of elements:");
    scanf("%d", &n);
    struct node knapsack[n];
    printf("Start entering the weight and profit :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &knapsack[i].weight, &knapsack[i].profit);
        knapsack[i].id=i+1;
        knapsack[i].pbyw = (1.0 * knapsack[i].profit) / (1.0 * knapsack[i].weight);
    }
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (knapsack[j].pbyw > knapsack[min].pbyw)
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = knapsack[min];
            knapsack[min] = knapsack[i];
            knapsack[i] = temp;
        }
    }
    int k = 0;
    while (capacity > 0)
    {
        if (knapsack[k].weight <= capacity)
        {
            capacity -= knapsack[k].weight;
            profit += knapsack[k].profit;
            printf("PUT %d IN BAG\n",knapsack[k].id);
            k++;
        }
        else
        {
            profit += knapsack[k].pbyw * capacity;
            capacity = 0;
            printf("PUT %d IN BAG\n",knapsack[k].id);
        }
    }
    printf("The max profit is %f", profit);
}