#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Insertion Sort function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /*Move the elements of arr[0..i-1], that are
        greater than the key, to the position ahead
        of their current position*/
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j;
   for (i = 0; i < n-1; i++) {     
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]) {
              //Swap arr[j] and arr[j+1]
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
       }
   }
}

//Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Comparison of time complexity theoretically
/* Bubble Sort:
   - In the worst-case and average scenarios, the time complexity is O(n^2), where 'n' represents the number of items to be sorted. This is because Bubble Sort compares and swaps each item with every other item in the list.
   - However, in the best-case scenario (when the input array is already sorted), the time complexity is O(n).
   
*/

/* Insertion Sort:
   - For both the worst-case and average scenarios, the time complexity is O(n^2), where 'n' is the number of items to be sorted. This is because Insertion Sort involves comparing and shifting items with every other item in the list.
   - In the best-case scenario (when the input array is already sorted), the time complexity is O(n).
   
*/


// Implementation to check the time complexity with experimental data
int main(){
    int n = 1000; //size of array
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(n * sizeof(int));
    srand(time(0)); //seed for random values

    //Generate random values for arrays
    for(int i=0; i<n; i++) {
        arr1[i] = rand() % 1000; //random numbers between 0 and 999
        arr2[i] = arr1[i]; //copy the values from arr1 to arr2
    }

    clock_t start, end;
    double cpu_time_used;

    printf("Starting the insertion sort...\n");
    start = clock();
    insertionSort(arr1, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished insertion sort in %f seconds.\n", cpu_time_used);

    printf("Starting the bubble sort...\n");
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Finished bubble sort in %f seconds.\n", cpu_time_used);

    //Free allocated memory
    free(arr1);
    free(arr2);

    return 0;
}


