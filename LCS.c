// LONGEST COMMON SUBSEQUENCE (LCS)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

void lcs(char *X, char *Y, int m, int n) {
    int c[m+1][n+1];
    int i, j;
    // Build L[m+1][n+1] in bottom up fashion
    for(i=0;i<=m;i++) {
        for(j=0;j<=n;j++) {
            if(i==0 || j==0){
                c[i][j]=0;
            }else if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    // Find the longest common subsequence
    int index = c[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    i = m;
    j = n;
    while (i>0 && j>0) {
        if(X[i-1]==Y[j-1]){
            lcs[index-1]=X[i-1];
            i--;
            j--;
            index--;
        }
        else if(c[i-1][j] > c[i][j-1])
            i--;
        else
            j--;
    }
    printf("Length of LCS: %d\n",strlen(lcs));
    printf("Longest common subsequence: %s\n", lcs);
}

int main() {
    char X[100], Y[100];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
    return 0;
}
