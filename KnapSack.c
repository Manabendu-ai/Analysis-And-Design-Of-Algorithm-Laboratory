#include<stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the max capacity: ");
    scanf("%d", &w);

    int wt[n], val[n];

    printf("Enter the weights: ");
    for(int i =0; i<n; i++){
        scanf("%d", &wt[i]);
    }

    printf("Enter the vals: ");
    for(int i =0; i<n; i++){
        scanf("%d", &val[i]);
    }

    int dp[n+1][w+1];


    for(int i =0; i<=n ; i++){
        for(int j = 0; j<=w; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (wt[i-1] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max  (
                                    dp[i-1][j], 
                                    val[i-1] + dp[i-1][j-wt[i-1]]
                                );
            }
        }
    }

    printf("\nDP Table:\n");
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            printf("%5d", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nItems Included: ");
    int row = n, col = w;
    while(row>0  && col>0){
        if(dp[row][col] != dp[row-1][col]){
            printf("%d ",row);
            col = col - wt[row-1];
        }
        row--;
    }

    printf("\nMaximum Profit : %d\n",dp[n][w]);
    return 0;
}