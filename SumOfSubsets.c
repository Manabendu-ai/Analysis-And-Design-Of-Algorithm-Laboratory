#include<stdio.h>
#include<stdlib.h>

int w[10], x[10], n, m;

void subset(int s, int k){
    if(s == m){
        printf("{ ");
        for(int  i=0; i<k; i++){
            if(x[i]){
                printf("%d ", w[i]);
            }
        }
        printf("}\n");
    }  

    if (k==n || s > m){
        return;
    }
    x[k]=1;
    subset(s+w[k], k+1);
    x[k]=0;
    subset(s, k+1);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter required sum: ");
    scanf("%d", &m);

    subset(0, 0);
}