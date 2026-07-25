#include<stdio.h>
#include<stdlib.h>

int x[10], n;

int isSafe(int k, int i){
    for(int j =1; j<k; j++){
        if(x[j] == i || abs(x[j] - i)==abs(j-k)){
            return 0;
        }
    }
    return 1;
}

void nqueen(int k){
    
    for(int i =1; i<=n; i++){
        if(isSafe(k,i)){
            x[k] = i;
            if(k==n){
                printf("\nSolution: \n");
                for(int r= 1; r<=n ; r++){
                    for(int c= 1; c<=n; c++){
                        if(x[r] == c){
                            printf("Q ");
                        } else {
                            printf(". ");
                        }
                    }
                    printf("\n");
                }

                for(int j=1; j<=n; j++){
                    printf("%d ",x[j]);
                }
                printf("\n");
            } else {
                nqueen(k+1);
            }
        }
    }

}

int main(){
    n =4;
    nqueen(1);
}