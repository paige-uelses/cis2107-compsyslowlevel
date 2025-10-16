
/*

Paige Uelses
October 2, 2025
CIS2107 - Lab_06 “Arrays of Pointers to Functions”

Statement of problem: design and implement array of function pointer

*/

#include <stdio.h>
#include <stdlib.h>

// prototypes
int showMenu(void);
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main(){

    puts("WELCOME TO LAB 06\n");

    //declare 2-dim array
    int students = 0;
    int exams = 0;

    printf("Enter number of students: ");
    scanf("%d", &students);
    printf("Enter number of exams: ");
    scanf("%d", &exams);
    puts("");

     int grades[students][exams];

    for (int r = 0; r < students; r++){
        for (int c = 0; c < exams; c++){
            printf("enter [%d][%d]: ", r, c);
            scanf("%d", &grades[r][c]);
        }
    }

    //function pointer array
    void (*processGrades[4])(int, int, int[students][exams]) = {printArray, minimum, maximum, average};

    //get user choice
    while (1) {
        int choice = showMenu();
        if (choice == 4){
            puts("End program");
            break;
        }
        processGrades[choice](students, exams, grades);
        puts("");
    }
    return 0;

}

//menu function
int showMenu(void){
    printf("Enter a choice: \n");
    puts("\t0\tPrint the array of grades");
    puts("\t1\tFind the minimum grade");
    puts("\t2\tFind the maximum grade");
    puts("\t3\tPrint the average on all tests for each student");
    puts("\t4\tEnd Program");
    printf("> ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

//0
void printArray(int students, int exams, int grades[students][exams]){
    for (int r = 0; r < students; r++){
        printf("Student %d: ", r);
        for (int c = 0; c < exams; c++){
            printf("%d ", grades[r][c]);
        }\
        putchar('\n');
    }
}

//1
void minimum(int students, int exams, int grades[students][exams]){
    int min = grades[0][0];
    for (int r = 0; r < students; r++){
        for (int c = 0; c < exams; c++){
            if (grades[r][c] < min) {
                min = grades[r][c];
            }
        }
    }
    printf("Minimum grade in the class: %d\n", min);
}

//2
void maximum(int students, int exams, int grades[students][exams]){
    int max = grades[0][0];
    for (int r = 0; r < students; r++){
        for (int c = 0; c < exams; c++){
            if (grades[r][c] > max) {
                max = grades[r][c];
            }
        }
    }
    printf("Maximum grade in the class: %d\n", max);
}

//3
void average(int students, int exams, int grades[students][exams]){
    for (int r = 0; r < students; r++){
        int sum = 0;
        for (int c = 0; c < exams; c++){
            sum += grades[r][c];
        }
        printf("Student %d average: %.2f\n", r, (double)sum / exams);

    }
}
