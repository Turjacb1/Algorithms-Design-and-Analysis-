void bubbleSort(int arr[], int n, int* steps) 
{ for (int i = 0; i < n - 1; i++) 
    { int swapped = 0;
for (int j = 0; j < n - i - 1; j++) {
    (*steps)++;  // Count each comparison

    if (arr[j] > arr[j + 1]) {
        // Swap elements
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
    }
}

// If no elements were swapped, array is sorted
if (swapped == 0)
    break;
}
}




// Fill array in descending order (worst case for Bubble Sort)
void testBubbleSort(int n) 
{ 
    int arr[n]; 
    int steps = 0;
for (int i = 0; i < n; i++) 
{
    arr[i] = n - i;
}

// Call Bubble Sort
bubbleSort(arr, n, &steps);

// Output results
printf("Array size: %d\n", n);
printf("Steps (comparisons): %d\n\n", steps);
}


int main() 
{ testBubbleSort(10); 
    testBubbleSort(100); 
    testBubbleSort(1000);
    return 0;
}