#include <stdio.h>

int arr[] = {10,30,40,50,20,70,60,80};
int n = 8;


void merge(int low, int mid, int high){
    int i = low;
    int k = low;
    int j = mid+1;
    int B[13];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            B[k] = arr[i];
            i++;k++;
        }
        else if(arr[j]<=arr[i]){
            B[k] = arr[j];
            j++;k++;
        }
    }
    while(i<=mid){
        B[k] = arr[i];
        i++;k++;
    }
    while(j<=high){
        B[k] = arr[j];
        j++;k++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = B[i];
    }
}

void mergeSort(int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);
        merge(low, mid, high);
    }
}



void main(){
    mergeSort(0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}