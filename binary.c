// BINARY SEARCH
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000;

void binarySearch(int a[])
{
    int search,left,right,mid,y=0;
    printf("\nEnter the element to be searched ");
    scanf("%d",&search);
    //Binary Search
    left=0;
    right=n-1;
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==search){
            y=1;
            break;
        }else if(a[mid]<search){
            left=mid+1;
        }else if(a[mid]>search){
            right=mid-1;
        }
    }
    if(y==1){
        printf("Element found");
    }else{
        printf("Element not found");
    }
}

int main(){

    int i,j,temp,a[n];
    clock_t start,end;
    double t;


    for(i=0;i<n;i++){
        a[i]=i;
    }
    //Optimized Bubble Sort
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-i-2;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    // Best Case
    printf("Enter 0 as number to be searched");
    start=clock();
    binarySearch(a);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Best Case: %f\n",t);


    // Average Case
    printf("Enter 5000 as number to be searched");
    start=clock();
    binarySearch(a);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Average Case: %f\n",t);

    // Worst Case
    printf("Enter 9999 as number to be searched");
    start=clock();
    binarySearch(a);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Worst Case: %f\n",t);
    return 0;
}
