/*
Crvenkapica

Bara (voda) i suvi delovi (zemlja) nalaze se na šumskoj stazi. Suve delove staze simboliše broj 1, a vodu predstavlja broj 2.

Napravimo jednu listu u kojoj su navedene nasumične vrednosti 1 i 2 tako da je veća verovatnoća da se u ovoj listi nađe voda nego zemljište (na primer, neka odnos bude 70% voda 30% zemljište)! U listi (tj.na stazi) prvi i poslednji element mora da bude 1, odnosno zemljište. Prikažite listu na ekranu tako da zemlju predstavlja # (hashmark), a voda je _ (donja crta). Na primer:

12122222112221 ->#_#_ _ _ _ _#_ _ _#_ _#

Na jednom kraju šumske staze nalazi se Crvenkapica koja želi da stigne do bake koja se nalazi na kraju ove šumske staze. Crvenkapica može da preskoči “n” bara u nizu (vrednost za “n”, broj bara koje Crvenkapica može da preskoči, unosi se sa tastature).

Napišite program koji generiše stazu (listu) u datom odnosu vode i zemljišta (npr. 70% i 30%), prikažite stazu na ekranu, a zatim odredite da li Crvenkapica može da pređe ovu stazu, a da joj noge ostanu suve.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PATH 100

// Function for computing longest line water
int longestWaterLine(int *path, int pathLength) {
    int longestArr = 0;
    int length = 0;
    
    for(int i = 0; i < pathLength; i++) {
        if(path[i] == 2)
            length++;
        else
            length = 0;
            
        if(length > longestArr)
            longestArr = length;
    }
    return longestArr;
}

/*
Landscape: 

#_#_______##___#___#____##_______#_#__##___##__#_#

1 - Earth (#)
2 - Water (_)

Can character move across to end for this landscape?
*/
int main() {
    int lengthLand;
    
    // Enter data for length water
    do {
        printf("Enter length: ");
        scanf("%d", &lengthLand);
        
        if(lengthLand > MAX_PATH)
            printf("Repeat answer. Max number is %d\n", MAX_PATH);
        
    } while(lengthLand > MAX_PATH);
    
    // 
    int landscape[MAX_PATH];
    srand(time(NULL));
    landscape[0] = 1;
    
    for(int i = 1; i < lengthLand; i++) {
        // Random between 1 and 100
        int num = rand() % 100 + 1;
        
        // 30% is earth
        if(num <= 30)
            landscape[i] = 1;
        // 70% is water
        else
            landscape[i] = 2;
    }
    // Last element must be earth
    landscape[lengthLand - 1] = 1;
    
    // Output landscape view
    for(int i = 0; i < lengthLand; i++) {
        // Earth element
        if(landscape[i] == 1)
            printf("#");
        // Water element
        else
            printf("_");
    }
    printf("\n\n");
    
    // Character Stats
    int maxCharacterWaterMove;
    printf("Enter number max value for character who can move across water: ");
    scanf("%d", &maxCharacterWaterMove);
    
    // Stats
    int longestWater = longestWaterLine(landscape, lengthLand);
    printf("Longest water line is: %d\n", lengthLand);
    if(maxCharacterWaterMove >= lengthLand)
        printf("Character can move across water");
    else
        printf("Character cannot move");
    
    
    return 0;
}
