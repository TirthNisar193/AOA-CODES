// INSERTION SORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n=10000;

void insertionSort(int a[]){
    int i,j,temp;
    for(i=1;i<n;i++){
        j=i-1;
        temp=a[i];
        while((a[j]>temp)&&(j>=0)){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    void insertionSort(int a[]);
    int i,a[n];
    clock_t start,end;
    double t;

    // Best Case
    for(i=0;i<n;i++){
        a[i]=i;
    }
    start=clock();
    insertionSort(a);
    end=clock();
    t = ((double)(end-start));
    printf("\nTime taken by Best Case: %f",t);

    // Average Case
    for(i=0;i<n;i++){
        a[i]=rand();
    }
    start=clock();
    insertionSort(a);
    end=clock();
    t = ((double)(end-start));
    printf("\nTime taken by Average Case: %f",t);

    // Worst Case
    for(i=n;i>0;i--){
        a[i]=i;
    }
    start=clock();
    insertionSort(a);
    end=clock();
    t = ((double)(end-start));
    printf("\nTime taken by Worst Case: %f",t);
    return 0;
}

