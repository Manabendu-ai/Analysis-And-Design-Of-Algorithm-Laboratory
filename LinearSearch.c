#include<stdio.h>

int main(){
    int n, target;
    printf("Enter n : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter Target : ");
    scanf("%d", &target);

    for(int i = 0; i<n; i++){
        if(arr[i] == target){
            printf("Target Found at index: %d\n",i);
            return 0;
        }
    }
    printf("Target Found Not Found!\n");
    return 0;
}