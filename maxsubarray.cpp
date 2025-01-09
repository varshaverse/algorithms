#include <iostream>

using namespace std;

int maxCrossSub(int arr[], int x, int mid, int y);
int maxSub(int arr[], int x, int y);

int main() {
    int input;
    cin >> input;
    int arr[input];
    for(int i = 0; i < input; i++) cin >> arr[i];
    cout << maxSub(arr, 0, input - 1);
    return 0;
    
    }

void maxHeap(int arr[], int size, int x){
    int big;
    if(left(x) < size && arr[left(x)] > arr[x]) big = left(x);
    else big = x;
    if(right(x) < size && arr[right(x)] > arr[big]) big = right(x);
    if(big != x){
        swap(arr[x], arr[big]);
        maxHeap(arr, size, big);
    }
}

void heapSort(int arr[], int size){
    int i;
    for(i = size/2; i >= 0; i--) maxHeap(arr, size, i); // Builds max heap
    for(i = size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        maxHeap(arr, --size, 0);
    }
}
int left(int i){ return i * 2;}
int right(int i){ return (i * 2) + 1;}
int parent(int i){ return i / 2;}

void swap(int* x, int* y){
    if(*x != *y){
        int hold = *x;
        *x = *y;
        *y = hold;
    }
}
