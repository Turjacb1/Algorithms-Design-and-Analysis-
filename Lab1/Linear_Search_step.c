#include <stdio.h>

int linearSearch(int arr[], int n, int key, int* steps) {
    for (int i = 0; i < n; i++) {
        (*steps)++;  
        if (arr[i] == key)
            return i;
    }
    return -1;
}

void testSearch(int n, int key) {
    int arr[n];
    int steps = 0;

    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int index = linearSearch(arr, n, key, &steps);

    printf("Array size: %d, Search key: %d\n", n, key);
    if (index != -1)
        printf("Key found at index %d\n", index);
    else
        printf("Key not found.\n");

    printf("Steps taken: %d\n\n", steps);
}
//for count worst case
int main() {
    testSearch(10, 10);     
    testSearch(100, 100);   
    testSearch(1000, 1000); 

    return 0;
}
