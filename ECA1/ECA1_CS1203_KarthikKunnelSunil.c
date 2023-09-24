#include <stdio.h>

// Function to swap two elements
void swap(int* a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Function to reverse a subarray a[i..n]
void reverse(int* a, int i, int n) {
    int left = i;
    int right = n;

    while (left < right) {
        swap(a, left++, right--);
    }
}

// Function to print an array
void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d,", a[i]);
    }
    printf("\n");
}

// Function to generate all permutations of 1...n
void generatePermutations(int n) {
    // initialize the array
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    while (1) {
        // print the current permutation
        printArray(a, n);

        int i = n - 1;
        while (i > 0 && a[i - 1] >= a[i]) {
            i--;
        }

        // if i is 0, it means we have generated all permutations
        if (i == 0) {
            break;
        }

        int j = n - 1;
        while (a[j] <= a[i - 1]) {
            j--;
        }

        // swap a[i-1] and a[j]
        swap(a, i - 1, j);

        // reverse a[i..n]
        reverse(a, i, n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    generatePermutations(n);

    return 0;
}
