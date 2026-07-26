#include<stdio.h>

int main(){
    int n,min=0;
    printf("Enter n : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<n; i++){
        min = i;
        for(int j = i+1; j<n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted Array: \n");
    for(int i =0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}