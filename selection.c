// SELECTION SORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000;

void selectionSort(int a[]){
    int i,j,min,temp;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
    if(min!=i){
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    }
}
int main(){
    void selectionSort(int a[]);
    int i,a[n];
    clock_t start,end;
    double t;

    // Best Case
    for(i=0;i<n;i++){
        a[i]=i;
    }

    start=clock();
    selectionSort(a);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Best Case: %f",t);


    // Average Case
    for(i=0;i<n;i++){
        a[i]=rand();
    }
    start=clock();
    selectionSort(a);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Average Case: %f",t);

    // Worst Case
    for(i=n;i>0;i--){
        a[i]=i;
    }

    start=clock();
    selectionSort(a);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Worst Case: %f",t);
    return 0;
}