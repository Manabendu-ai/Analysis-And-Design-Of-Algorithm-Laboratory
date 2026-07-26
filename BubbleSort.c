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

    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n-1; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
       
    }

    printf("Sorted Array: \n");
    for(int i =0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}