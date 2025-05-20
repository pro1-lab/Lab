// 15. Write a program to Sort the following elements using heap sort {9.16,32,8,4,1,5,8,0}.
#include <stdio.h>

void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

 
void heapify(float arr[], int n, int i) {
    int largest = i;  
    int left = 2 * i + 1; 
    int right = 2 * i + 2;  

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

   
    if (right < n && arr[right] > arr[largest])
        largest = right;

  
    if (largest != i) {
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    }
}

 
void heapSort(float arr[], int n) {
     
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for ( i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  
        heapify(arr, i, 0); 
    }
}

 
void printArray(float arr[], int size) {
int i;
    for ( i= 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {9.16, 32, 8, 4, 1, 5, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}