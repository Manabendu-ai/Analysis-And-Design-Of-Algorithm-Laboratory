#include<stdio.h>
#define MAX 20

int min(int a, int b){
    return (a < b) ? a : b;
}

void floyds(int r[MAX][MAX], int n){
    for(int k = 0; k<n; k++){
        for(int j =0; j<n; j++){
            for(int i =0; i<n; i++){
                r[i][j] = min(r[i][j], r[i][k]+r[k][j]);
            }
        }
    }
}
int main(){
    int n;
    int r[MAX][MAX];

    printf("Enter n: \n");
    scanf("%d", &n);

    printf("Enter Cost Matrix: \n");
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &r[i][j]);
        }
    }
    floyds(r,n);
    printf("\nShortest Path Matrix: \n");
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
    return 0;
}