#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j;
   for (i = 0; i < n-1; i++) {     
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]) {
              // Swap arr[j] and arr[j+1]
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
       }
   }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n = 1000; // size of array
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(n * sizeof(int));
    srand(time(0)); // seed for random values

    // Generate random values for arrays
    for(int i=0; i<n; i++) {
        arr1[i] = rand() % 1000; // random numbers between 0 and 999
        arr2[i] = arr1[i]; // copy values from arr1 to arr2
    }

    clock_t start, end;
    double cpu_time_used;

    printf("Starting insertion sort...\n");
    start = clock();
    insertionSort(arr1, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished insertion sort in %f seconds.\n", cpu_time_used);

    printf("Starting bubble sort...\n");
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished bubble sort in %f seconds.\n", cpu_time_used);

    // Free allocated memory
    free(arr1);
    free(arr2);

    return 0;
}
