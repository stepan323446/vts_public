# Kolokvijum 2

Kolokvijum može da sadrži zadatke na:

* [Crtanje trougao](./zadatak3-trougao.md)
* Fajlovi
* [Random](#random)
* [Sortiranje](#sortiranje)
* Struct (soon)

## Random

Za random mi koristimo samo na 2 načina: sa `float` ili sa `int`. Najčešće sa `int`.

**Morami u početku napisati `srand` u `main()`**:
```c
#include <time.h>

int main() {
    srand(time(0));
    ...
}
```

**Sa float:**
```c
float randRange(int min, int max) {
    float decNumber = rand() % (max - min + 1) + min;
    float flNumber = (float)rand() / (float)RAND_MAX;
    return decNumber + flNumber;
}
```

**Sa int:**
```c
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
```

## Sortiranje

Za sortiranje uvek moramo koristiti ili novu variijablu `temp`, ili svoju funkciju `swap`. Ovde koristimo funkciju:
```c
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### Bubble sort

![Bubble sort](https://upload.wikimedia.org/wikipedia/commons/0/06/Bubble-sort.gif?20110418154649)

Bubble Sort je najjednostavniji algoritam za sortiranje koji radi tako što više puta menja susedne elemente ako su u pogrešnom redosledu. Ovaj algoritam nije pogodan za velike skupove podataka jer je njegova prosečna i najgore vremenska složenost prilično visoka.

**Primer koda:**
```c
void bubbleSort(int arr[], int n, int isAcsending) {
    // Varijabla, da li sve uredu
    int isReady;

    do {
        // Svako ponavljanje stavimo 1, sta sve uredu
        isReady = 1;
        for(int i = 0; i < n; i++) {
            // Poslednji indeks ne treba proveravati
            if(i == n - 1)
                continue;

            // Mozemo bez isAcsending, to je na dva načina
            if(arr[i] > arr[i + 1] && isAcsending == 1) {
                swap(&arr[i], &arr[i + 1]);
                // Ako mi smo uradili zamenu, to nije spremno
                isReady = 0;
            }
            else if (arr[i] < arr[i + 1] && isAcsending == 0) {
                swap(&arr[i], &arr[i + 1]);
                // ...
                isReady = 0;
            }
        }
    }
    while(!isReady);
}
```

### Selection sort

![Selection sort](https://www.lavivienpost.net/wp-content/uploads/2022/01/selection-600.gif)

Algoritam više puta bira najmanji (ili najveći) element iz nesortiranog dela liste i zamenjuje ga prvim elementom nesortiranog dela. Ovaj proces se ponavlja za preostali nesortirani deo dok se cela lista ne sortira.

**Primer koda:**
```c
void selectionSort(int arr[], int n, int isAcsending) {
    for(int i = 0; i < n - 1; i++) {
        // Najmanji trenutni ideks i broj (u pocetku prvi za ovu iteraciju)   
        int minNumberIndex = i;
        int minNumber = arr[i];

        // Počećemo tražiti od prvoj broja iteraciji do kraja
        for(int j = i; j < n; j++) {
            // Bool značaj, ako pronađimo manje (ne treba, ako pišemo bez isAcsending, možemo pisati tako u if)
            int isIndex = 0;

            if(minNumber > arr[j] && isAcsending)
                isIndex = 1;
            else if (minNumber < arr[j] && !isAcsending)
                isIndex = 1;
            
            // Zamenjujemo manjem brojem, i indeks za taj broj
            if(isIndex) {
                minNumber = arr[j];
                minNumberIndex = j;
            }
        }
        // Posle sav taj petlje (sa j), mi dobimo broj sa indeksom. Posle mi mozemo koristiti swap izmedu trenutnim(i) i najmanjem indeksom(minNumberIndex)
        swap(&arr[i], &arr[minNumberIndex]);
    }
}
```

### Insertion sort

![Insertion sort](https://www.lavivienpost.net/wp-content/uploads/2022/01/insertion-600.gif)

Insertion sort je jednostavan algoritam za sortiranje koji funkcioniše tako što iterativno ubacuje svaki element nesortirane liste na njegovu tačnu poziciju u sortiranom delu liste. To je stabilan algoritam za sortiranje, što znači da elementi sa jednakim vrednostima održavaju svoj relativni redosled u sortiranom izlazu.

Insertion sort je kao sortiranje igraćih karata u vašim rukama. Karte ste podelili u dve grupe: sortirane i nesortirane. Zatim birate karticu iz nesortirane grupe i stavljate je na pravo mesto u sortiranoj grupi.

**Primer koda:**
```c
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
```