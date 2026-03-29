#include <stdio.h>


int max(int arr[], int n) {
    int i, maximum = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}


int min(int arr[], int n) {
    int i, minimum = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int main() {
    int arr[10], i;

    
    printf("Enter 10 numbers:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    
    int maximum = max(arr, 10);
    int minimum = min(arr, 10);

    
    printf("Maximum element = %d\n", maximum);
    printf("Minimum element = %d\n", minimum);

    return 0;
}