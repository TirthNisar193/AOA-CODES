// MIN MAX
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000;
// structure is used to return two values from minMax()
struct pair{
    int min;
    int max;
};

struct pair getMinMax(int a[], int n){
    struct pair minmax;
    int i;
    // If there is only one element then return it as min and max both
    if (n==1){
        minmax.max = a[0];
        minmax.min = a[0];
        return minmax;
    }

    // If there are more than one elements, then initialize min and max
    if (a[0]>a[1]){
        minmax.max = a[0];
        minmax.min = a[1];
    }else{
        minmax.max = a[1];
        minmax.min = a[0];
    }

    for (i=2;i<n;i++){
        if (a[i] > minmax.max){
            minmax.max = a[i];
        }else if (a[i] < minmax.min){
            minmax.min = a[i];
        }
    }
    return minmax;
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
    getMinMax (a,n);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Best Case: %f",t);


    // Average Case
    for(i=0;i<n;i++){
        a[i]=rand();
    }
    start=clock();
    getMinMax (a,n);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Average Case: %f",t);

    // Worst Case
    for(i=n;i>0;i--){
        a[i]=i;
    }
    start=clock();
    getMinMax (a,n);
    end=clock();
    t= ((double)(end-start));
    printf("\nTime Taken by Worst Case: %f",t);
    return 0;
}

