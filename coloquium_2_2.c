#include <stdio.h>
#include <stdlib.h>

struct Student {
    float prvi;
    float drugi;
    float treci;
    float cetvrti;
    float ukupno;
};
struct Category {
    char *name;
    int count;
};

float getUkupniBod(struct Student student) {
    float cetvrti = (student.cetvrti == 0.0) ? student.treci : student.cetvrti;

    return (student.prvi + 
            student.drugi + 
            student.treci + cetvrti) * 2;
}
void getData(struct Student *students, int *length) {
    FILE *fp = fopen("T2.txt", "r");

    float prvi;
    float drugi;
    float treci;
    float cetvrti;

    for (int i = 0; fscanf(fp, "%f\t%f\t%f\t%f\n", &prvi, &drugi, &treci, &cetvrti) != EOF; i++) {
        students[i].prvi = prvi;
        students[i].drugi = drugi;
        students[i].treci = treci;
        students[i].cetvrti = cetvrti;
        students[i].ukupno = getUkupniBod(students[i]);

        (*length)++;
    }
    

    fclose(fp);
}
void printData(struct Student *students, int length) {
    printf("I\tII\tIII\tIV\tUkupno\n");
    printf("------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", students[i].prvi, students[i].drugi, students[i].treci, students[i].cetvrti, students[i].ukupno);
    }
    printf("\n");
}

// Sortiranje START
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}
void sortStudents(struct Student *students, int length) {
    // Koristim bubble sort

    int isSorted;
    do
    {
        isSorted = 1;
        
        for (int i = 0; i < length; i++) {
            // Ako krajni elemenat
            if(i == length - 1)
                continue;

            if(students[i].ukupno > students[i + 1].ukupno) {
                swap(&students[i], &students[i + 1]);
                isSorted = 0;
            }
        }       

    } while (!isSorted);
    
}
// Sortiranje END

int getCountByUkupni(struct Student *students, int length, float min, float max) {
    int counter = 0;

    for(int i = 0; i < length; i++) {
        if(students[i].ukupno >= min && students[i].ukupno <= max)
            counter++;
    }

    return counter;
}

void printHistogram(struct Category *categories, int length) {
    printf("Histogram: \n");

    for (int i = 0; i < length; i++) {
        printf("%d | ", i);
        for (int point = 0; point < categories[i].count; point++) {
            printf("* ");
        }
        
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < length; i++) {
        printf("%d - %s (%d)", i, categories[i].name, categories[i].count);
        
        printf("\n");
    }
}

int main() {
    struct Student students[100];
    int length = 0;
    getData(students, &length);
    sortStudents(students, length);
    printData(students, length);

    struct Category categories[5] = { 
        { "Nedovoljan", getCountByUkupni(students, length, 0, 20) },
        { "Dovoljan", getCountByUkupni(students, length, 20, 24.9) },
        { "Dobro", getCountByUkupni(students, length, 25.0, 29.9) },
        { "Vrlo dobro", getCountByUkupni(students, length, 30, 34.9) },
        { "Odličan", getCountByUkupni(students, length, 35, 100) },
    };
    
    printHistogram(categories, 5);

    return 0;
}

/*
Output:

I       II      III     IV      Ukupno
------------------------
3.00    2.10    2.79    2.12    20.02
2.04    3.42    2.21    3.10    21.54
2.63    2.47    3.36    2.83    22.58
2.57    2.83    3.86    2.14    22.80
2.37    3.37    2.85    2.82    22.82
4.19    3.39    2.03    2.07    23.36
4.25    2.38    2.00    3.12    23.50
2.19    4.30    3.27    2.27    24.06
3.27    2.16    4.11    2.60    24.28
2.98    3.02    3.98    2.21    24.38
2.73    3.90    2.97    2.75    24.70
3.20    3.94    2.67    0.00    24.96
2.34    4.17    3.59    2.47    25.14
3.62    2.68    3.73    2.57    25.20
4.04    3.16    2.71    0.00    25.24
2.44    2.62    3.38    4.68    26.24
2.76    3.47    2.28    4.85    26.72
2.57    2.42    4.38    4.11    26.96
3.21    2.89    3.01    4.40    27.02
3.75    2.30    2.99    4.57    27.22
3.28    3.24    2.47    4.65    27.28
2.15    4.89    3.32    3.37    27.46
2.31    3.23    4.74    3.46    27.48
2.98    4.08    3.06    3.63    27.50
3.21    2.83    3.50    4.37    27.82
3.54    3.35    4.84    2.19    27.84
2.82    4.05    4.66    2.42    27.90
3.51    2.69    4.46    3.41    28.14
3.93    3.95    3.16    0.00    28.40
4.71    3.14    2.88    3.70    28.86
4.79    2.15    3.19    4.47    29.20
2.41    2.97    4.50    4.81    29.38
3.07    3.83    3.44    4.45    29.58
3.17    4.87    3.23    3.80    30.14
3.08    3.23    4.84    4.09    30.48
2.28    3.87    4.29    4.82    30.52
2.12    4.61    4.72    3.82    30.54
3.79    3.40    4.26    3.99    30.88
3.60    4.98    4.11    2.90    31.18
5.00    3.84    3.76    3.29    31.78
3.61    5.00    4.56    2.74    31.82
4.55    2.39    4.53    4.46    31.86
3.33    4.94    4.22    3.59    32.16
3.76    3.78    4.79    4.07    32.80
4.00    2.69    4.97    4.76    32.84
4.58    3.54    4.55    4.07    33.48
4.29    3.78    4.61    4.58    34.52
5.00    3.30    4.50    4.59    34.78
4.51    4.62    4.48    4.04    35.30
4.45    3.51    4.88    0.00    35.44

Histogram: 
0 | 
1 | * * * * * * * * * * * 
2 | * * * * * * * * * * * * * * * * * * * * * 
3 | * * * * * * * * * * * * * * * 
4 | * * 

0 - Nedovoljan (0)
1 - Dovoljan (11)
2 - Dobro (21)
3 - Vrlo dobro (15)
4 - Odličan (2)

*/