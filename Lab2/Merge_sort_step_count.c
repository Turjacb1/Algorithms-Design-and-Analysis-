#include <stdio.h>

int stepCount = 0; // Global step counter

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
        stepCount++; // Assignment step
    }

    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
        stepCount++; // Assignment step
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        stepCount++; // Comparison
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
        stepCount++; // Assignment
    }

    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
        stepCount++; // Assignment
    }

    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
        stepCount++; // Assignment
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {10, 44, 66, 22, 46, 24, 12, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    mergesort(arr, 0, size - 1);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTotal steps: %d\n", stepCount);

    return 0;
}
