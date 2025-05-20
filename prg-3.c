// 3. Perform the Insertion and Selection Sort on the input {75,8,1,16,48,3,7,0} and display the
// output in descending order.
#include <stdio.h>


void insertionSort(int arr[], int n) {
int i,j,key;
    for ( i = 1; i < n; i++) {
	 key = arr[i];
	 j = i - 1;

	
	while (j >= 0 && arr[j] < key) {
	    arr[j + 1] = arr[j];
	    j--;
	}
	arr[j + 1] = key;
    }
}


void selectionSort(int arr[], int n) {
int i,j,maxIndex,temp;
    for ( i = 0; i < n - 1; i++) {
	
	 maxIndex = i;
	for ( j = i + 1; j < n; j++) {
	    if (arr[j] > arr[maxIndex]) {
		maxIndex = j;
	    }
	}
	
	 temp = arr[maxIndex];
	arr[maxIndex] = arr[i];
	arr[i] = temp;
    }
}


void printArray(int arr[], int n) {
int i;
    for ( i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {75, 8, 1, 16, 48, 3, 7, 0};
    int arr2[] = {75, 8, 1, 16, 48, 3, 7, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

   
    insertionSort(arr, n);
    printf("Sorted array using Insertion Sort in descending order: ");
    printArray(arr, n);

   
    selectionSort(arr2, n);
    printf("Sorted array using Selection Sort in descending order: ");
    printArray(arr2, n);

    return 0;
}