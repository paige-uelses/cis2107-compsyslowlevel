/*
Paige Uelses
CIS2107_Lab 05 "Processing 2D Arrays"
September 28, 2025

Statement of Problem: write functions to process 2D arrays
*/

#include <stdio.h>
#include <stdlib.h>

//function prototypes
int maximum(int rows, int columns, int arr[rows][columns]);
int rowSum(int rows, int columns, int arr[rows][columns], int row); //row = row x
int columnSum(int rows, int columns, int arr[rows][columns], int col); //col = column x
void isSquare(int rows, int columns);
void displayOutputs(int rows, int columns, int arr[rows][columns]);


//main function
int main(void){
    puts("Let's create a 2Dim array!");
    puts("");

    //create the 2D array
    int rows = 0;
    int columns = 0;

    printf("\tHow many rows? ");
    scanf("%d", &rows);
    printf("\tHow many columns? ");
    scanf("%d", &columns);
    puts("");

    int arr[rows][columns];

    //getting the specific values
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < columns; c++){
            printf("\tenter [%d][%d]: ", r, c);
            scanf("%d", &arr[r][c]);
        }
    }

    //calling the functions

    //1: maximum ... not shown on sample output so didn't display in main

    //2: rowSum
    puts("");
    for (int r = 0; r < rows; r++){
        printf("Sum of row %d = %d\n", r + 1, rowSum(rows, columns, arr, r));
    }
    puts("");

    //3: columnSum
    for (int c = 0; c < columns; c++){
        printf("Sum of column %d = %d\n", c + 1, columnSum(rows, columns, arr, c));
    }
    puts("");

    //4: isSquare
    isSquare(rows, columns);
    puts("");

    //5: displayOutputs
    displayOutputs(rows, columns, arr);
}

//function 1/5 - find maximum value
int maximum(int rows, int columns, int arr[rows][columns]){
    int max = arr[0][0];

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < columns; c++){
            if (arr[r][c] > max){
                max = arr[r][c];
            }
        }
    }
    return max;
}

//function 2/5 - find the sum of the elements in row x
int rowSum(int rows, int columns, int arr[rows][columns], int row){
    int sum = 0;

    for (int i = 0; i < columns; i++){
        sum += arr[row][i];
    }
    return sum;
}

//function 3/5 - find the sum of the elements in column x
int columnSum(int rows, int columns, int arr[rows][columns], int col){
    int sum = 0;

    for (int i = 0; i < rows; i++){
        sum += arr[i][col];
    }
    return sum;
}

//function 4/5 - check if the array is square
void isSquare(int rows, int columns){
    if (rows == columns){
        puts("This is a square array.");
    } else {
        puts("This is not a square array.");
    }
}

//function 5/5 - display output
void displayOutputs(int rows, int columns, int arr[rows][columns]){
    puts("Here is your 2Dim array:");

    for (int r = 0; r < rows; r++){
        printf("[");

        for (int c = 0; c < columns; c++){
            printf("%d", arr[r][c]);
            if (c < columns - 1){
                printf(", ");
            }
        }
        
        printf("]\n");
    }
}
