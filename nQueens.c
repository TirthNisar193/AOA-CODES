#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int x[10];

bool Place(int k, int i) {
    for(int j=0; j<k; j++) {
        if(x[j] == i || abs(x[j]-i) == abs(j-k)) {
            return false;
        }
    }
    return true;
}

void NQueens(int k, int n) {
    for(int i=0; i<n; i++) {
        if(Place(k,i)) {
            x[k] = i;
            if(k == n-1) {
                for(int j=0; j<n; j++) {
                    printf("%d\t", x[j]+1);
                }
                printf("\n");
            }
            else {
                NQueens(k+1, n);
            }
        }
    }
}
void main() {
    NQueens(0, 5);
}