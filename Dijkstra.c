#include<stdio.h>
#define MAX 10
#define INF 999

int main(){
    int cost[MAX][MAX], dist[MAX], visited[MAX]={0};
    int source,n,u, min;

    printf("\nEnter n : \n");
    scanf("%d", &n);

    printf("Enter Cost Marix: \n");
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("Enter Source Vertex: \n");
    scanf("%d", &source);

    for(int i =0; i<n; i++){
        dist[i] = cost[source][i];
    }

    dist[source] = 0;
    visited[source] = 1;

    for(int i =1; i<n; i++){
        min = INF;
        for(int j =0; j<n; j++){
            if(!visited[j] && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;
        for(int j=0; j<n; j++){
            if(!visited[j] && dist[j] > dist[u] + cost[u][j]){
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }
    printf("\nShortest Distance: \n");
    for(int i=0; i<n; i++){
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }
}