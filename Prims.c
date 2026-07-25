#include<stdio.h>
#define MAX 10
#define INF 999

int main(){
    int n, u, v, mincost =0,min;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int edge = 0;

    printf("\nEnter n: ");
    scanf("%d", &n);

    printf("Enter the cost matrix: ");
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0)
            cost[i][j] = INF;
        }
    }
    visited[0] = 1;

    while(edge < n-1){
        min = INF;
        for(int i =0; i<n; i++){
            if(visited[i] == 1){
                for(int j =0; j<n; j++){
                    if(!visited[j] && cost[i][j]<min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d -> %d : cost = %d\n",u,v,min);
        mincost += min;
        visited[v] = 1;
        edge++;
    }
    printf("Min Cost : %d\n",mincost);
    return 0;
}