#include<stdio.h>

void towerOfHanoi(int n, int source, int aux, int dest){
    if (n == 1){
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    towerOfHanoi(n-1, source, dest, aux);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n-1, aux, source, dest);
}

int main(){
    int n;
    printf("Enter number of disk: \n");
    scanf("%d",&n);

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}