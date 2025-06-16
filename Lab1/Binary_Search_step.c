#include <stdio.h>


int binarySearch(int arr[], int n, int key, int* steps) {
    int low = 0, high = n - 1;



    while (low <= high) {
        (*steps)++; 
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}




void testbinarysearch(int n, int key) {
    int arr[n];
    int steps = 0;

    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int index = binarySearch(arr, n, key, &steps);


    printf("array size: %d, aearch key: %d\n", n, key);
    if (index != -1)
    printf("key found index %d\n", index);
    else
    printf("key not found.\n");

    printf("steps taken: %d\n\n", steps);
}


// worst case
int main() {
    testbinarysearch(10, 10);     
    testbinarysearch(100, 100);   
   testbinarysearch(1000, 1000); 

    return 0;
}
