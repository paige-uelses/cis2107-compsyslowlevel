/*
Paige Uelses
CIS2107_Lab 04 "Processing 1D Arrays"
September 19, 2025

Statement of Problem: write functions to process 1D arrays:
including filling with random numbers, finding max in a range,
reversing arrays, reversing a selected range, and finding a sequence of two numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40
#define NUM_MIN 0
#define NUM_MAX 100

//function prototypes
void fillArray(int arr[], int size, int rand_min, int rand_max);
int findWithRange(int arr[], int size, int lowSelectedRange, int highSelectedRange);
void reverseArray(int arr[], int size);
void reverseSelectedRangeWithinArray(int arr[], int size, int startRange, int endRange);
int findSequence(int arr[], int size);

//main function
int main(void){
    srand(time(NULL));
    int arr[SIZE];
    int original[SIZE];

    fillArray(arr, SIZE, NUM_MIN, NUM_MAX);
    //make copy of original array
    for (int i = 0; i < SIZE; i++){
        original[i] = arr[i];
    }

    findWithRange(arr, SIZE, 10, 19);
    reverseArray(arr, SIZE);
    reverseSelectedRangeWithinArray(original, SIZE, 10, 19);
    findSequence(original, SIZE);

    return 0;
}

//function 1/5: fill an array with random numbers
void fillArray(int arr[], int size, int rand_min, int rand_max){
        puts("==============================================================");
    puts("Original Array:");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (rand_max - rand_min + 1) + rand_min;
        printf("%6d", arr[i]);

        if ((i+1) % 10 == 0){
            puts("");
        }
    }
    puts("==============================================================");
}

//function 2/5: find the max in a range
int findWithRange(int arr[], int size, int lowSelectedRange, int highSelectedRange){
    puts("Finding the max of a given range:");
    int max = arr[lowSelectedRange];

    for (int i = lowSelectedRange+1; i <= highSelectedRange; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++){
        if (i >= lowSelectedRange && i <= highSelectedRange){
            if (arr[i] == max){
                printf("\033[1;32m%6d\033[0m", arr[i]);
            } else {
                printf("\033[1;31m%6d\033[0m", arr[i]);
            }
        } else {
            printf("%6d", arr[i]);
        }

        if ((i+1) % 10 == 0){
            puts("");
        }

    }
    printf("\nMax = %d\n", max);
    puts("==============================================================");
    return max;
}

//function 3/5: reverse an array
void reverseArray(int arr[], int size) {
    for (int i = 0, j = size - 1; i<j; i++, j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    puts("Reversed:");
    for (int i = 0; i < size; i++){
        printf("%6d", arr[i]);
        if ((i+1) % 10 == 0){
            puts("");
        }
    }
    puts("==============================================================");
}

//function 4/5: reverse selected range within an array
void reverseSelectedRangeWithinArray(int arr[], int size, int startRange, int endRange){
    puts("Reversing elements in a given range:");
    for (int i = startRange, j = endRange; i<j; i++, j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < size; i++){
        if (i >= startRange && i <= endRange){
            printf("\033[1;31m%6d\033[0m", arr[i]);
        } else {
            printf("%6d", arr[i]);
        }

        if ((i+1) % 10 == 0){
            puts("");
        }
    }
    puts("==============================================================");
}

//function 5/5 tom & jerry - return sequential elements
int findSequence(int arr[], int size){
    int tom;
    int jerry;
    puts("Finding sequential elements:");
    puts("***");
    do{
        printf("Enter two numbers:");
        //input validation
        if (scanf("%d%d", &tom, &jerry) != 2){
            while (getchar() != '\n');
            puts("Invalid input. Enter two integers.\n");
            continue;
        } 
        if (tom < NUM_MIN || tom > NUM_MAX || jerry < NUM_MIN || jerry > NUM_MAX){
            printf("Invalid input. Numbers must be between %d and %d.\n", NUM_MIN, NUM_MAX);
            continue;
        }
    } while (tom < NUM_MIN || tom > NUM_MAX || jerry < NUM_MIN || jerry > NUM_MAX);

    for (int i = 0; i < size - 1; i++){
        if (arr[i] == tom && arr[i+1] == jerry){
            printf("sequence found at index %d\n", i);
            return i;
        }
    }
    puts("sequence not found\n");
    return -1;
    }
