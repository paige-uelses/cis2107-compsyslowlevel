//Paige Uelses
//09/11/2025
//CIS2107-003 Lab-03
//Build an ATM machine using functions 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int validatePIN(void);
int menu(void);
void showBalance(double balance);
void cashWithdrawal(double *balance);
void cashDeposit(double *balance);
void quitThankYou(int transactionCount);
void askReceipt(void);

int main() {
    double balance = 5000.0;
    int transactionCount = 0;

    //welcome
    puts("=============================");
    puts("*Welcome to the ATM Machine!*");
    puts("=============================");

    //validate PIN
    validatePIN();

    //call menu
    int option = 0;

    do {
        option = menu();
        switch(option){
            case 1: 
                showBalance(balance);
                transactionCount++;
                break;
            case 2: 
                cashWithdrawal(&balance);
                transactionCount++;
                break;
            case 3: 
                cashDeposit(&balance);
                transactionCount++;
                break;
            case 4: 
                quitThankYou(transactionCount);
                break;
            default: 
                puts("Invalid choice. Please enter 1-4.");
                break;
        }
    } while (option != 4);
    
    return 0;
}

//FUNCTIONS

//check if PIN is valid 
int validatePIN(){
    int userPIN;
    int attemptNum = 0;
    while (attemptNum < 3){
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &userPIN);

        if (userPIN == 3014) {
            puts("PIN accepted. Proceeding to menu...");
            return 1; 
        } else {
            attemptNum++;
            int attemptsLeft = 3 - attemptNum;
            printf("PIN Not Accepted. You have %d attempts left.\n", attemptsLeft);
        }
    } 
    puts("===============================================================");
    puts("Too many incorrect attempts. You've been locked out of the ATM.");
    puts("===============================================================");
    exit(0);
}

//menu function
int menu(){
    int userChoice;
    puts("=============================");
    puts("        ATM MAIN MENU        ");
    puts("=============================");
    puts("(1): Balance");
    puts("(2): Cash Withdrawal");
    puts("(3): Cash Deposit");
    puts("(4): QUIT");
    printf("Enter your choice: ");
    scanf("%d", &userChoice);
    return userChoice;
}


//option 1 - check balance function
void showBalance(double balance) {
    puts("===========================");
    printf("Your current balance is: $%.2f\n", balance);
    puts("===========================");
    askReceipt();
}

//option 2 - cash withdrawal function
void cashWithdrawal(double *balance){
    static int withdrawnToday = 0;
    int attemptNum = 0;
    double initialWithdrawalRequest = 0.0;
    int withdrawalRequest = 0;

    //check for coin withdrawal

    while (attemptNum < 3) {
        puts("============================================================================");
        printf("Enter the amount you'd like to withdrawal (multiples of $20, max $1,000): \n");
        puts("============================================================================");
        scanf("%lf", &initialWithdrawalRequest);

        double intPart;
        double fracPart = modf(initialWithdrawalRequest, &intPart);

        withdrawalRequest = (int)initialWithdrawalRequest;

        if (fracPart != 0.0) {
            attemptNum++;
            puts("Invalid amount (cannot withdraw coins). Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);

        } else if (withdrawalRequest <= 0) {
            attemptNum++;
            puts("Invalid amount (0 or negative). Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        }        
        else if (withdrawalRequest % 20 != 0) {
            attemptNum++;
            puts("Invalid amount (must be a multiple of 20). Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        } 
        else if (withdrawalRequest + withdrawnToday > 1000) {
            attemptNum++;
            puts("ERROR: Daily withdrawal limit is $1000. Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        }
        else if (withdrawalRequest > *balance) {
            attemptNum++;
            puts("ERROR: Insufficient funds. Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        } 
        else {
            //successful withdrawal
            *balance -= withdrawalRequest;
            withdrawnToday += withdrawalRequest;
            printf("Please take your cash: $%d\n", withdrawalRequest);
            printf("New balance: $%.2f\n", *balance);
            askReceipt();
            return;
        }
    }
    puts("============================================");
    puts("Too many invalid attempts. Session canceled.");
    puts("============================================");
    exit(0);
}

//option 3 - cash deposit
void cashDeposit(double *balance) {
    static int depositedToday = 0;
    int attemptNum = 0;
    double initialDepositRequest = 0.0;
    int depositRequest = 0;

    while (attemptNum < 3) {
        puts("==========================================================================");
        printf("Enter the amount you'd like to deposit (max $10,000, whole dollars only): \n");
        puts("==========================================================================");
        scanf("%lf", &initialDepositRequest);

        double intPart;
        double fracPart = modf(initialDepositRequest, &intPart);

        depositRequest = (int)initialDepositRequest;

        if (fracPart != 0.0) {
            attemptNum++;
            puts("Invalid amount (cannot deposit coins). Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        } else if (depositRequest <= 0) {
            attemptNum++;
            puts("Invalid amount (0 or negative). Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        } 
        else if (depositRequest + depositedToday > 10000) {
            attemptNum++;
            puts("ERROR: Daily deposit limit is $10000. Please try again.");
            printf("You have %d attempts left.\n", 3 - attemptNum);
        }
        else {
            //successful withdrawal
            *balance += depositRequest;
            depositedToday += depositRequest;
            printf("You've successfully deposited: $%d\n", depositRequest);
            printf("New balance: $%.2f\n", *balance);
            askReceipt();
            return;
        }
    }
    puts("============================================");
    puts("Too many invalid attempts. Session canceled.");
    puts("============================================");
    exit(0);
}

//option 4 - quit & thank u
void quitThankYou(int transactionCount){
    puts("============================");
    puts("Thank you for using our ATM.");
    puts("============================");
    printf("Total number of transactions: %d\n", transactionCount);
    puts("Goodbye!");
    exit(0);
}

//ask for receipt
void askReceipt(void) {
    int receiptChoice = 0;
    puts("===========================");
    puts("Would you like a receipt?");
    puts("===========================");
    puts("(1) - YES");
    puts("(2) - NO");
    scanf("%d", &receiptChoice);

    if (receiptChoice == 2) {
        return;
    } else if (receiptChoice == 1) {
        puts("Printing receipt....");
    } else {
        puts("Invalid choice. Try again.");
    }
}

