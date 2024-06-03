#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Person {
    int visina;
    int tezina;
    int pol;
    float bmi;
};
struct Category {
    char *name;
    int count;
};

float getBMI(struct Person person) {
    return (float)person.tezina / pow((float)person.visina / 100, 2);
}

void getData(struct Person *persons, int *length) {
    FILE *fp = fopen("T1.txt", "r");

    int visina;
    int tezina;
    int pol;
    int bmi;

    for (int i = 0; fscanf(fp, "%d\t%d\t%d\n", &visina, &tezina, &pol) != EOF; i++) {
        persons[i].visina = visina;
        persons[i].tezina = tezina;
        persons[i].pol = pol;
        persons[i].bmi = getBMI(persons[i]);

        (*length)++;
    }
    

    fclose(fp);
}
void printData(struct Person *persons, int length) {
    printf("Visina\tTezina\tPol\tBMI\n");
    printf("------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t%d\t%d\t%f\n", persons[i].visina, persons[i].tezina, persons[i].pol, persons[i].bmi);
    }
    printf("\n");
    
}

// Sortiranje START
void swap(struct Person *a, struct Person *b) {
    struct Person temp = *a;
    *a = *b;
    *b = temp;
}
void sortByHeight(struct Person *persons, int length) {
    // Koristim bubble sort

    int isSorted;
    do
    {
        isSorted = 1;
        
        for (int i = 0; i < length; i++) {
            // Ako krajni elemenat
            if(i == length - 1)
                continue;

            if(persons[i].visina < persons[i + 1].visina) {
                swap(&persons[i], &persons[i + 1]);
                isSorted = 0;
            }
        }       

    } while (!isSorted);
    
}
// Sortiranje END

int getCountBMIByRange(struct Person *persons, int length, float min, float max) {
    int counter = 0;

    for(int i = 0; i < length; i++) {
        if(persons[i].bmi >= min && persons[i].bmi <= max)
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
    struct Person persons[100];
    int length = 0;

    getData(persons, &length);
    sortByHeight(persons, length);
    printData(persons, length);

    struct Category categories[4] = { 
        { "Pothranjenost", getCountBMIByRange(persons, length, 0, 18.5) },
        { "Normalna ili zdrava telesna masa", getCountBMIByRange(persons, length, 18.5, 24.9) },
        { "Prekomerna telesna masa", getCountBMIByRange(persons, length, 25.0, 29.9) },
        { "Gojaznost", getCountBMIByRange(persons, length, 30, 100) },
    };
    printHistogram(categories, 4);
    

    return 0;
}


/*
Output:

Visina  Tezina  Pol     BMI
------------------------
199     119     1       30.049746
198     109     1       27.803286
196     75      1       19.523115
196     80      0       20.824656
195     52      0       13.675213
194     107     1       28.430225
193     81      0       21.745552
193     60      1       16.107817
191     103     1       28.233875
191     58      1       15.898687
191     106     1       29.056223
190     104     1       28.808865
188     117     1       33.103214
187     93      0       26.594984
185     117     0       34.185535
185     111     1       32.432430
185     114     0       33.308983
183     112     0       33.443817
182     62      0       18.717545
178     118     0       37.242775
176     49      1       15.818699
175     53      0       17.306122
174     61      1       20.147972
174     103     0       34.020348
174     72      1       23.781212
172     112     1       37.858299
172     65      1       21.971334
171     64      1       21.887075
171     64      0       21.887075
170     114     0       39.446365
169     46      1       16.105877
167     63      1       22.589552
167     117     0       41.952026
166     104     1       37.741329
166     78      1       28.305996
166     69      0       25.039919
166     81      1       29.394688
165     87      0       31.955923
165     76      1       27.915520
165     75      1       27.548210
164     55      0       20.449139
164     71      0       26.397978
163     71      1       26.722872
163     84      1       31.615793
159     110     1       43.510937
155     87      0       36.212280
154     58      1       24.456064
153     105     1       44.854546
151     49      0       21.490286
150     59      1       26.222221

Histogram: 
0 | * * * * * * 
1 | * * * * * * * * * * * * * 
2 | * * * * * * * * * * * * * * 
3 | * * * * * * * * * * * * * * * * * 

0 - Pothranjenost (6)
1 - Normalna ili zdrava telesna masa (13)
2 - Prekomerna telesna masa (14)
3 - Gojaznost (17)



*/