#include<stdio.h>
#define MAX 20

int min(int a, int b){
    return (a < b) ? a : b;
}

void warshall(int a[MAX][MAX], int n){
    for(int k = 0; k<n; k++){
        for(int j =0; j<n; j++){
            for(int i =0; i<n; i++){
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

int main(){
    int n;
    int a[MAX][MAX];

    printf("Enter n: \n");
    scanf("%d", &n);

    printf("Enter Cost Matrix: \n");
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    warshall(a,n);
    printf("\nShortest Path Matrix: \n");
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}