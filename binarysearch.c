/*
 * Binary Search Algorithm
 * -----------------------
 * Searches for a key in a sorted array using the binary search technique.
 * Time Complexity : O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

/* Returns the index of key in arr[], or -1 if not found */
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        /* Use overflow-safe mid calculation */
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Validate input range */
    if (n <= 0 || n > 100) {
        printf("Error: Number of elements must be between 1 and 100.\n");
        return 1;
    }

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found\n");

    return 0;
}