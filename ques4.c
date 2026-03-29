#include <stdio.h>
#include <stdlib.h>


int findMax(int *arr, int n) {
    int i, max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int *arr, n, i;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    arr = (int*) malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int max = findMax(arr, n);

    
    printf("Largest element = %d\n", max);


    free(arr);

    return 0;
}