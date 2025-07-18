#include <stdio.h>
int steps = 0; 



void swap(int* a, int* b) {
    steps++; 
    int temp = *a;
    *a = *b;
    *b = temp;
}





int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        steps++; 
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}




void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}



void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printarray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printarray(arr, n);

    printf("Total steps: %d\n", steps);

    return 0;
}
