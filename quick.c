// QUICK SORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000;

void quickSort(int a[],int first, int last){
    int i,j,pivot,temp;
    if(first<last){
        pivot=last;
        i=first;
        j=last;
        while(i<j){
            while(a[i]<=a[pivot] && i<last){
                i++;
            }
            while(a[j]>a[pivot]){
                j--;
            }
            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quickSort(a,first,j-1);
        quickSort(a,j+1,last);
    }

}
int main(){
    void quickSort(int a[],int first, int last);
    int i,a[n];
    clock_t start,end;
    double t;

    // Best Case
    for(i=0;i<n;i++){
        a[i]=i;
    }
    start=clock();
    quickSort(a,0,n-1);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Best Case: %f",t);


    // Average Case
    for(i=0;i<n;i++){
        a[i]=rand();
    }
    start=clock();
    quickSort(a,0,n-1);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Average Case: %f",t);

    // Worst Case
    for(i=n;i>0;i--){
        a[i]=i;
    }
    start=clock();
    quickSort(a,0,n-1);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Worst Case: %f",t);
    return 0;
}

