// SUM OF SUBSET
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int set[MAX],subset[MAX];
int n,sum,found=0;

void sumOfSubset(int index,int current_sum){
    int i;
    if(current_sum==sum){
        printf("Subset with sum %d is ",sum);
        for(i=0;i<index;i++){
            printf("%d ",subset[i]);
        }
        printf("\n");
        found=1;
        return;
    }
    if(index==n || current_sum>sum){
        return;
    }

    // Recursively generate subsets by including or excluding the current element
    subset[index]=set[index];
    sumOfSubset(index+1,current_sum+set[index]);
    subset[index]=0;
    sumOfSubset(index+1,current_sum);
}

int main(){
    int i;
    printf("Enter set size ");
    scanf("%d",&n);

    printf("Enter elements of the set\n");
    for(i=0;i<n;i++){
        scanf("%d",&set[i]);
    }

    printf("Enter desired sum ");
    scanf("%d",&sum);

    sumOfSubset(0,0);

    if(!found){
        printf("No subset with desired sum found");
    }
    return 0;
}


