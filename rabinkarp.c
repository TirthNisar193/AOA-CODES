// RABIN KARP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define d 10

void rabinKarp(char pattern[], char text[], int q){
    int m = strlen(pattern);
    int n = strlen(text);
    int i,j,p=0,t=0,h=1;

    for(i=0;i<m-1;i++){
        h=(h*d)%q;
    }

    for(i=0;i<m;i++){
        p=(p*d + pattern[i])%q;
        t=(t*d + text[i])%q;
    }

    for(i=0;i<=n-m;i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
            }
            if(j==m){
                printf("Pattern is found at position: %d",i+1);
            }
        }
        if (i<n-m){
          t=(d*(t-text[i]*h)+text[i+m])%q;
          if(t<0){
            t=(t+q);
          }
        }
    }
}

int main(){
    char text[]="ABCCDDAEFG";
    char pattern[]="CDD";
    int q=13;
    rabinKarp(pattern,text,q);
    return 0;
}