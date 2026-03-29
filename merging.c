#include <stdio.h>


void merge(int A[], int B[], int C[], int n1, int n2) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        C[k] = A[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        C[k] = B[j];
        j++;
        k++;
    }
}

int main() {
    int A[5], B[5], C[10];
    int i;

    printf("Enter 5 elements of array A (ascending order):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter 5 elements of array B (ascending order):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &B[i]);
    }

    merge(A, B, C, 5, 5);

    printf("Merged sorted array C:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}