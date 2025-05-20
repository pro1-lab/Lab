// 2. Write a program to sort list of n numbers using Bubble Sort algorithms.
#include <stdio.h>

void bubbleSort(int arr[], int n) {
   
    int i,j;
    for ( i = 0; i < n - 1; i++) {
	
	for ( j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    int n,i;
	int arr[100];



    printf("Enter the number of elements: ");
    scanf("%d", &n);


   
    printf("Enter %d numbers:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Original array: ");
    printArray(arr, n);

  
    bubbleSort(arr, n);

   
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}