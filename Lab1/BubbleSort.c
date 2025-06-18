void bubbleSort(int arr[], int n, int* steps) 
{ 
    for (int i = 0; i < n - 1; i++) 

    { 
        int swapped = 0;
for (int j = 0; j < n - i - 1; j++) {
    (*steps)++;  

    if (arr[j] > arr[j + 1]) {
        
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
    }
}


if (swapped == 0)
    break;
}
}




void testbubblesort(int n) 
{ 
    int arr[n]; 
    int steps = 0;
for (int i = 0; i < n; i++) 
{
    arr[i] = n - i;
}


bubbleSort(arr, n, &steps);


printf("array size: %d\n", n);
printf("steps : %d\n\n", steps);
}



int main() 
{ testbubblesort(10); 
    testbubblesort(100); 
    testbubblesort(1000);
    return 0;
}