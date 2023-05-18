// MERGE SORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000;

void merge(int a[], int beg, int mid, int end){
    int i=beg,j=mid+1,index=i,temp[n],k;
    while((i<=mid) && (j<=end)){
        if(a[i]<a[j]){
            temp[index]=a[i];
            i++;
        }else{
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=end){
            temp[index]=a[j];
            j++;
            index++;
        }
    }else{
        while(i<=mid){
            temp[index]=a[i];
            i++;
            index++;
        }
    }

    for(k=beg;k<=index-1;k++){
        a[k]=temp[k];
    }
}

void mergeSort(int a[], int beg, int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        mergeSort(a,beg,mid);
        mergeSort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

int main(){

    int i,a[n];
    clock_t start,end;
    double t;

    // Best Case
    for(i=0;i<n;i++){
        a[i]=i;
    }
    start=clock();
    mergeSort(a,0,n-1);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Best Case: %f",t);


    // Average Case
    for(i=0;i<n;i++){
        a[i]=rand();
    }
    start=clock();
    mergeSort(a,0,n-1);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Average Case: %f",t);

    // Worst Case
    for(i=n;i>0;i--){
        a[i]=i;
    }
    start=clock();
    mergeSort(a,0,n-1);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Worst Case: %f",t);
    return 0;
}
