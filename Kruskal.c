#include<stdio.h>
#define MAX 10
#define INF 999

int parent[MAX];

int find(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

int main(){
    int n, u, v, mincost=0, min;
    int cost[MAX][MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    for(int i =0; i<n; i++){
        parent[i] = i;
        for(int j =0; j<n; j++){
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0){
                cost[i][j] = INF;
            }
        }
    }
    int e = 0;
    while(e<n-1){
        min = INF;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    u =i;
                    v =j;
                }
            }
        }
        int a = find(u);
        int b = find(v);

        if(a != b){
            printf("%d -> %d = %d\n",u,v, min);
            mincost += min;
            parent[a] = b;
            e++;
        }
        cost[u][v] = cost[v][u] = INF;
    }
    printf("Minimum Cost = %d\n", mincost);
    return 0;
}