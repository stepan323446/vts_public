#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Opsti funkciji
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// readFile učitava brojeve iz fajla u niz,
void readFile(int *arr, int *length) {
    FILE *fp = fopen("data1.txt", "r");
    if(!fp) {
        printf("File not found");
    }

    for (int i = 0; fscanf(fp, "%d", &arr[i]) != EOF; i++)
        (*length)++;

    fclose(fp);
}

// printNums ispisuje brojeve na ekran, na sledeći način: brojevi su razdvojeni zarezom (znakom “, ”), u jednom redu se ispisuje samo 5 brojeva i cifre brojeva su razdvojene “_” znakom. Na primer, brojevi 12, 15, 13, 19 se ispisuju na sledeći način: 1_2, 1_5, 1_3, 1_9,
void printNums(int *arr, int length) {
    const int rowCount = 5;
    int row = rowCount;
    for (int i = 0; i < length; i++) {

        // 1_5, 1_3, 1_9
        int decimal = arr[i] / 10;

        if(decimal > 0)
            printf("%d_%d", decimal, arr[i] % 10);
        else
            printf("%d", arr[i]);

        // u jednom redu se ispisuje samo 5 brojeva
        if(--row > 0) {
            // brojevi su razdvojeni zarezom (znakom “, ”) - na kraju ne treba
            if(i != length - 1)
                printf(", ");
        }
        else {
            printf("\n");
            row = rowCount;
        }
    }
    printf("\n");
    
}

// countNums ispisuje za svaki broj posebno koliko pute se pojavio u nizu
void copyArr(int *source, int sourceLength, int *target) {
    for (int i = 0; i < sourceLength; i++) {
        target[i] = source[i];
    }
}
void countNums(int *arr, int length)  {
    int sameArr[length];
    copyArr(arr, length, sameArr);

    // Iteration every element
    for (int i = 0; i < length; i++)
    {
        // Skip repeatly numbers
        if(sameArr[i] == -1)
            continue;

        int counter = 0;
        // Count for element
        for (int j = i; j < length; j++) {
            if(sameArr[i] == sameArr[j]) {
                if(counter > 1)
                    sameArr[j] = -1;
            
                counter++;
            }
        }
        printf("Number %d repeated %d times\n", sameArr[i], counter);
    }
}


// sortNums: bubble-sort metodom sortirati u opadajućem redosledu brojeve)
void sortNums(int *arr, int length) {
    int isReady;
    do {
        isReady = 1;
        for (int i = 0; i < length; i++) {
            // If last index
            if(i == length - 1)
                continue;

            if(arr[i] < arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
        }
        
    }
    while (!isReady);
}

// deleteNums: učitava broj n sa tastature iz opsega [0, N-1], gde je N broj elemenata u nizu (onoliko koliko ste učitali iz fajla data1.txt). Funkcija briše element na n-toj lokaciji, a ostale elemente pomera.
int deleteNums(int *arr, int *length) {
    int n;
    printf("Location for remove (0-%d): ", *length - 1);
    scanf("%d", &n);

    if(n > *length - 1) {
        printf("Out of memory!\n");
        return 0;
    }
    for (int i = n; i < *length; i++) {
        // End array
        if(i == *length - 1)
            break;
        
        // Na kraj elemenat, koj zelimo unistati
        swap(&arr[i], &arr[i + 1]);
    }
    (*length)--;

    return 1;
}

// readFile: učitava brojeve iz fajla u matricu dimenzije 5x5
void readFileMatrix5x5(int arr[][5]) {
    int arr1D[25];
    int length = 0;
    readFile(arr1D, &length);
    

    const int colCount = 5;
    int col = 0;
    int row = 0; 
    for (int i = 0; i < length; i++)
    {
        arr[row][col] = arr1D[i];
        if(++col >= 5) {
            
            col = 0;
            row++;
        }
    }
    
}
// rotateNums: zamenjuje redove sa kolonama u matrici. Prvi red postaje prva kolona, drugi red druga kolona itd. )
void rotateNums(int arr[][5]) {
    int result[5][5]; // New matrix to store the rotated values
    
    // Transpose the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            result[j][i] = arr[i][j];
        }
    }
    
    // Copy the transposed matrix back to the original matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = result[i][j];
        }
    }
}
void printMatrixArr(int arr[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", arr[i][j]);   
        }
        printf("\n");
    }
    
}
/*
calcNums ispisuje :
    zbir elemenata ispod sporedne dijagonale
    proizvod elemenata iznad glavne dijagonale
*/
void calcNums(int arr[][5]) {
    int sum = 0;
    long long int product = 1;
    // Sum
    for (int i = 0; i < 5; i++) {
        for (int j = 0; i < 5; j++) {
            if(i == j)
                break;

            sum += arr[i][j];
        }
    }
    // Product
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(i >= j)
                continue;
            //printf("%d *", arr[i][j]);
            product *= arr[i][j];
        }
    }

    // print
    printf("Sum ispod: %d\n", sum);
    printf("Product iznad: %ld\n", product);
    
}
// minDiff: ova funkcija ispisuje ona dva broja čija je razlika najmanja
void minDiff(int *arr, int length) {
    int isNewNum1 = 1;
    int num1;
    int isNewNum2 = 1;
    int num2;
    int diff;

    for (int i = 0; i < length; i++) {
        // Start number
        if(isNewNum1)
            num1 = arr[i];
        isNewNum1 = 0;

        for (int j = 0; j < length; j++) {
            // Skip same element
            if(i == j)
                continue;

            // Start number
            if(isNewNum2) {
                num2 = arr[j];
                diff = fabs(num1 - num2);
                

                isNewNum2 = 0;
            }
            int testDiff = fabs(arr[i] - arr[j]);
            if(testDiff < diff) {
                num1 = arr[i];
                num2 = arr[j];
                diff = testDiff;
            }

        }   
    }
    printf("Min diff nums %d and %d are %d\n", num1, num2,  diff);
    
}

int main() {
    int arr[100];
    int length = 0;
    readFile(arr, &length);

    printNums(arr, length);

    countNums(arr, length);

    sortNums(arr, length);
    printNums(arr, length);

    deleteNums(arr, &length);
    printNums(arr, length);

    int matrixArr[5][5];
    readFileMatrix5x5(matrixArr);
    printMatrixArr(matrixArr);

    printf("ROTATED:\n");
    rotateNums(matrixArr);
    printMatrixArr(matrixArr);

    calcNums(matrixArr);

    minDiff(arr, length);
    
    return 0;
}