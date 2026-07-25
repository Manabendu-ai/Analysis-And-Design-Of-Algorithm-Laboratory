#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int left, int mid, int right){
    int new_arr[right-left+1];
    int i =left, j =mid+1, k =0;
    while(i <=mid && j<=right){
        if(arr[i] <= arr[j]){
            new_arr[k++] = arr[i++];
        }
        else{
            new_arr[k++] = arr[j++];
        }
    }

    while(i<=mid){
        new_arr[k++] = arr[i++];
    }

    while(j <= right){
        new_arr[k++] = arr[j++];
    }
    for(i=0; i<k; i++){
        arr[left+i] = new_arr[i];
    }
}


void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    printf("\nEnter n: ");
    scanf("%d",&n);

    int arr[n];
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0]) - 1;

    for(int i =0; i<n; i++){
        arr[i] = rand() % 100;
    }

    clock_t start, stop;
    double time_spent;
    printf("\nIntital Array: ");
    for(int i =0; i<=right; i++){
        printf("%d ",arr[i]);
    }
    start = clock();
    mergeSort(arr, left, right);
    stop = clock();

    time_spent=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("\nSorted Array: ");
    for(int i =0; i<=right; i++){
        printf("%d ",arr[i]);
    }
    printf("\nTotal Time: %f\n",time_spent);
}