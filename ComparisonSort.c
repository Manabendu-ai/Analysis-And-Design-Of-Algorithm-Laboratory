#include <stdio.h>

int main() {
    int n, a[100], count[100] = {0}, sorted[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                count[j]++;
            else
                count[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        sorted[count[i]] = a[i];
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }

    return 0;
}