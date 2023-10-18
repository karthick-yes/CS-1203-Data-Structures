#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Merge function implementation
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
//Merge sort implementation
void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
//Utility function swap
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
//utility function partition
int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
//Implementation of quick sort
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//Implementation of heapify
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
//Implementation of heap sort


void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


/* Theoretical Time Complexity Analysis:

Merge Sort: The time complexity of Merge Sort is O(nLogn) in all 3 cases (worst, average, and best) as merge sort will always divides the array into two halves and takes linear time to merge two halves.
Quick Sort: The worst case time complexity of Quick Sort is O(n^2). The average and best case time complexity of Quick Sort is O(nLogn). It is generally faster on random arrays that other O(nLogn).
Heap Sort: The time complexity of Heap Sort is O(nLogn) for all cases (worst, average, and best). It is not a stable sort, but it does not require a large amount of memory.

Comparative Analysis:

Quick Sort is generally faster in practice than other O(nLogn) algorithms, especially for arrays. However, itis an in-place sorting algorithm, meaning it does not require any additional storage. Also one thing to note is that it has a worst case time complexity of O(n^2).
This could also be avoided with the use of random pivot. */


// Complexity Analysis with experimental data


int main(){
    int n = 1000000; // size of array
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(n * sizeof(int));
    int* arr3 = (int*)malloc(n * sizeof(int));
    srand(time(0)); // seed for random values

    // Generate random values for arrays
    for(int i=0; i<n; i++) {
        int val = rand() % 1000; // random numbers between 0 and 999
        arr1[i] = val;
        arr2[i] = val;
        arr3[i] = val;
    }

    clock_t start, end;
    double cpu_time_used;

    printf("Starting the merge sort...\n");
    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished merge sort in %f seconds.\n", cpu_time_used);

    printf("Starting the quick sort...\n");
    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished the quick sort in %f seconds.\n", cpu_time_used);

    printf("Starting the heap sort...\n");
    start = clock();
    heapSort(arr3, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished heap sort in %f seconds.\n", cpu_time_used);

    // Free allocated memory
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
