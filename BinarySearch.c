#include<stdio.h>

int binarySearch(int arr[], int left, int right, int target){
    while(left < right){
        int mid = (left+right)/2;
        if (arr[mid] == target){
            return mid;
        } else if (arr[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

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

    int index = binarySearch(arr, 0, n-1, target);
    if(index!=-1){
        printf("Target Found at index %d\n",index);
        return 0;
    }
    printf("Target Not Found!\n");
    return 0;
}