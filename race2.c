/*
Paige Uelses
CIS2107 - Lab_07 Race
October 11, 2025

Statement of Problem: Simulate the tortoise vs. hare race on a 70-square track using random numbers
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

#define TRACK 70

//prototypes
void moveTortoise(int *tPos);
void moveHare(int *hPos);
void printTrack(int tPos, int hPos);

int main(void){
    int tPos = 1;
    int hPos = 1;

    srand((unsigned) time(NULL));

    puts("ON YOUR MARK, GET SET");
    puts("BANG!!!!!");
    puts("AND THEY'RE OFF!!!!!");

    //call functions
    while(1){
        moveTortoise(&tPos);
        moveHare(&hPos);

        if (tPos < 1){
            tPos = 1;
        }
        if (hPos < 1){
            hPos = 1;
        }

        printTrack(tPos, hPos);

        if (tPos >= TRACK && hPos >= TRACK){
            puts("TORTOISE WINS!!! YAY!!!");
            break;
        } else if (tPos >= TRACK){
            puts("TORTOISE WINS!!! YAY!!!");
            break;
        } else if (hPos >= TRACK){
            puts("Hare wins. Yuch.");
            break;
        }

        sleep(1); 
    }
    return 0;
}

//functions 

/* Tortoise:
   1–5: fast plod (+3)
   6–7: slip (-6)
   8–10: slow plod (+1)
*/
void moveTortoise(int *tPos){
    int r = (rand() % 10) + 1; 
    if (r >= 1 && r <= 5){
        *tPos += 3;
    } else if (r == 6 || r == 7){
        *tPos -= 6;
    } else {
        *tPos += 1;
    }
}

/* Hare:
   1–2: sleep (0)
   3–4: big hop (+9)
   5:   big slip (-12)
   6–8: small hop (+1)
   9–10: small slip (-2)
*/
void moveHare(int *hPos){
    int r = (rand() % 10) + 1; 
    if (r == 1 || r == 2){
    } else if (r == 3 || r == 4){
        *hPos += 9;
    } else if (r == 5){
        *hPos -= 12;
    } else if (r >= 6 && r <= 8){
        *hPos += 1;
    } else {
        *hPos -=2;
    }
}

//printTrack
void printTrack(int tPos, int hPos){
    if (tPos > TRACK){
        tPos = TRACK;
    }
    if (hPos > TRACK){
        hPos = TRACK;
    }

    for (int i = 1; i <= TRACK; i++){
        if (tPos == hPos && i == tPos){
            printf("OUCH!!!");
            i += 6;
        } else if (i == tPos){
            printf("T");
        } else if (i == hPos){
            printf("H");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}




