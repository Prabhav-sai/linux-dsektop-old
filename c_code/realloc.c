#include <stdio.h>
#include <stdlib.h>

void printarr(int* arr, int size) {
		// function to print the elements of an array
		for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}

int main() {
		int* arr;
		int size = 5;
		arr = calloc(size, sizeof(int));
	
		printf("Enter 5 elements:\n");
		for (int i = 0; i < size; i++)
				scanf("%d", &arr[i]);
	
		printf("Current array: ");
		printarr(arr, size);
	
		// Increase array size and reallocate memory
		//size++;
        size--;
		arr = realloc(arr, size * sizeof(int));
	
		// Get new integer to fill the new space created
		//printf("Enter a 6th element:\n");
		//scanf("%d", &arr[size - 1]);
	
		printf("Resized array: ");
		printarr(arr, size);
		printf("%d\n",arr[2]);
	
		free(arr);
		printf("%d\n",arr[2]);
		return 0;
	}