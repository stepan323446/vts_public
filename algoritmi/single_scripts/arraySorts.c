#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

// For example
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void displayArray(int arr[], int n, char *title) {
    printf("\n==== Output (%s) =====\n", title);
    printf("Elementi niza:\n");

    for (int i = 0; i < n; i++)
    {        
        printf("| %d |", arr[i]);
    }
    printf("\n");
}

// Sorts
void selectionSort(int arr[], int, int);
void bubbleSort(int arr[], int, int);
int insertionSort(int arr[], int, int);

int main() {
    // Enter array
    srand(time(0));

    int arr[MAX];
    for(int i = 0; i < MAX; i++) {
        arr[i] = randRange(0, 100);
    }
    // Enter array END

    selectionSort(arr, MAX, 0);
    displayArray(arr, MAX, "Selection sort");

    bubbleSort(arr, MAX, 1);
    displayArray(arr, MAX, "Bubble sort");

    insertionSort(arr, MAX, 0);
    displayArray(arr, MAX, "Insertion sort");

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int arr[], int n, int isAcsending) {
    for(int i = 0; i < n - 1; i++) {   
        int minNumberIndex = i;
        int minNumber = arr[i];

        for(int j = i; j < n; j++) {
            int isIndex = 0;

            if(minNumber > arr[j] && isAcsending)
                isIndex = 1;
            else if (minNumber < arr[j] && !isAcsending)
                isIndex = 1;
            

            if(isIndex) {
                minNumber = arr[j];
                minNumberIndex = j;
            }
        }
        swap(&arr[i], &arr[minNumberIndex]);
    }
}
void bubbleSort(int arr[], int n, int isAcsending) {
    int isReady;

    do {
        isReady = 1;
        for(int i = 0; i < n; i++) {
            // Last index
            if(i == n - 1)
                continue;

            if(arr[i] > arr[i + 1] && isAcsending == 1) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
            else if (arr[i] < arr[i + 1] && isAcsending == 0) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
        }
    }
    while(!isReady);
}
int insertionSort(int arr[], int n, int isAcsending) {
    if(n < 2) {
        printf("Array have 1 element");
        return -1;
    }

    // Počećemo sa drugog elementa
    for (int i = 1; i < n; i++) {
        // Indeks za sačuvanje na kom mi mestu posle swap
        int indexIteration = i;

        // Proveravamo elementi u pozadini od arr[i]
        for (int j = i - 1; j >= 0; j--) {
            
            if(arr[j] > arr[indexIteration] && isAcsending) {
                swap(&arr[j], &arr[indexIteration]);
                // Menjamo pozijicu nazad
                indexIteration--;
            }

            if(arr[j] < arr[indexIteration] && !isAcsending) {
                swap(&arr[j], &arr[indexIteration]);
                indexIteration--;
            }
        }
    }
    
    return 0;
}