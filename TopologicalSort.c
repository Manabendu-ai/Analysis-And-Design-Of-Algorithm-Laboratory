#include<stdio.h>
#define MAX 20

int main(){
    int n;
    int adj[MAX][MAX];
    int indegree[MAX];
    int visited[MAX] = {0};
    int count=0;

    printf("\nEnter n : ");
    scanf("%d",&n);

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i =0; i<n; i++){
        indegree[i]=0;
        for(int j =0; j<n; j++){
            indegree[i] += adj[j][i];
        }
    }

    while(count < n){
        int found = 0;
        for(int i =0 ; i<n; i++){
            if(indegree[i] == 0 && visited[i] == 0){
                found = 1;
                printf("%d ",i);
                count++;
                visited[i] =1;
                for(int k =0; k<n; k++){
                    if (adj[i][k]==1) {
                        indegree[k]--;
                    }
                }
            }
        }
        if(!found){
            printf("\nGraph Contains a Cycle!");
            break;
        }
    }
    printf("\n");
    return 0;
}