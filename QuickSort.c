#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left+1;
    int j = right;
    int t;

    while(i<=j){
        while(arr[i]<=pivot && i<=right){
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(i<j){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    t = arr[left];
    arr[left] = arr[j];
    arr[j] = t;

    return j;
}

void quickSort(int arr[], int left, int right){
    int p;
    if(left < right){
        p = partition(arr, left, right);
        quickSort(arr, left, p-1);
        quickSort(arr, p+1, right);
    }
}

int main(){
    int n;
    printf("\nEnter n: ");
    scanf("%d", &n);

    int arr[n];
    int left = 0;
    int right = n-1;

    for(int i= 0; i<n; i++){
        arr[i] = rand() % 100; 
    }

    clock_t start, stop;
    double time_spent;
    printf("\nIntital Array: ");
    for(int i =0; i<n; i++){
        printf("%d ",arr[i]);
    }
    start = clock();
    quickSort(arr, left, right);
    stop = clock();

    time_spent=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("\nSorted Array: ");
    for(int i =0; i<=right; i++){
        printf("%d ",arr[i]);
    }
    printf("\nTotal Time: %f\n",time_spent);
}