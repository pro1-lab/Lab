#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int length, int target) {
int i;
    for (i = 0; i <length; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function for Binary Search
int binarySearch(int arr[], int length, int target) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid index

        if (arr[mid] == target) {
            return mid; // Return the index if found
        } else if (arr[mid] < target) {
	    low = mid + 1; // Search in the right half
	} else {
	    high = mid - 1; // Search in the left half
	}
    }
    return -1; // Return -1 if not found
}

int main() {
    int search_list[] = {3, 1, 9, 8, 7, 12, 56, 23, 89};
    int length = sizeof(search_list) / sizeof(search_list[0]);
    int target,i,j;
   int linearResult, binaryResult;
    // Linear Search
    printf("Enter a value to search using Linear Search: ");
    scanf("%d", &target);

     linearResult = linearSearch(search_list, length, target);

    if (linearResult != -1) {
	printf("Linear Search: Element found at index %d\n", linearResult);
    } else {
	printf("Linear Search: Element not found\n");
    }

    // Sorting the array for Binary Search
    // Here we use a simple bubble sort for demonstration purposes
    for ( i = 0; i < length - 1; i++) {
	for ( j = 0; j < length - i - 1; j++) {
	    if (search_list[j] > search_list[j + 1]) {
		int temp = search_list[j];
		search_list[j] = search_list[j + 1];
		search_list[j + 1] = temp;
	    }
	}
    }

    printf("Sorted Array for Binary Search: ");
    for ( i = 0; i < length; i++) {
	printf("%d ", search_list[i]);
    }
    printf("\n");

    // Binary Search
    printf("Enter a value to search using Binary Search: ");
    scanf("%d", &target);

     binaryResult = binarySearch(search_list, length, target);
    
    if (binaryResult != -1) {
        printf("Binary Search: Element found at index %d\n", binaryResult);
    } else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}