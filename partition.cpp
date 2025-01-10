#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int split(int arr[], int a, int b);
void quick(int arr[], int a, int b);
int partition(int arr[], int a, int b);
void swap(int *x, int *y);

int main() {
    int i, input;
    cin >> input;
    int arr[input];
    for (i = 0; i < input; i++) cin >> arr[i];
    quick(arr, 0, input - 1);
    for (i = 0; i < input; i++) cout << arr[i] << ";";
    return 0;
}

int split(int arr[], int a, int b) {
    int r = rand() % (b - a + 1) + a; // Fixed to include +1
    swap(&arr[r], &arr[b]); // Corrected function call and added second argument
    return partition(arr, a, b); // Changed to correct function name
}

void quick(int arr[], int a, int b) {
    if (a < b) {
        int r = split(arr, a, b);
        quick(arr, a, r - 1); // Fixed range for left subarray
        quick(arr, r + 1, b); // Fixed range for right subarray
    }
}

int partition(int arr[], int a, int b) {
    int i, x = a - 1;
    for (i = a; i < b; i++) {
        if (arr[i] <= arr[b]) swap(&arr[++x], &arr[i]);
    }
    swap(&arr[++x], &arr[b]);
    return x;
}

void swap(int *x, int *y) {
    if (*x != *y) {
        int hold = *x;
        *x = *y;
        *y = hold;
    }
}



