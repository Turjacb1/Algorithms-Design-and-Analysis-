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

    printf("array size: %d, search key: %d\n", n, key);
    if (index != -1)
        printf("key found at index %d\n", index);
    else
        printf("key not found.\n");

    printf("steps taken: %d\n\n", steps);
}
// worst case
int main() {
    testlinearsearch(10, 10);     
    testlinearsearch(100, 100);   
    testlinearsearch(1000, 1000); 

    return 0;
}
