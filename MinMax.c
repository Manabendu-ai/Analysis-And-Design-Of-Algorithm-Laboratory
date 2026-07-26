#include<stdio.h>

int min, max;

void minmax(int arr[], int low, int high){
    int mid, min1, max1;

    if(low==high){
        min=max=arr[low];
        return;
    }

    if(low == high-1){
        if(arr[low] >= arr[high]){
            max = arr[low];
            min = arr[high];
        } else {
            max = arr[high];
            min = arr[low];
        }
    }

    mid = (low+high)/2;

    minmax(arr, low, mid);
    min1 = min;
    max1 = max;
    minmax(arr, mid+1, high);

    if(min1 < min){
        min = min1;
    }

    if(max1 > max){
        max = max1;
    }
}

int main() {
    int a[20], n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    minmax(a, 0, n - 1);

    printf("Min = %d\n", min);
    printf("Max = %d\n", max);

    return 0;
}