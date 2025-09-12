// Paige Uelses
// 09/08/2025
// CIS2107_03 Lab_02
// Problem: Calculate an employee's paycheck with overtime & basic input validation

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main() {

    double empNum;
    double hourlySalary;
    double weeklyTime;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    //gathering employee number
    printf("Enter Employee Number: ");
    scanf("%lf", &empNum);

    double intPart;
    double fracPart = modf(empNum, &intPart);

    if (empNum <= 0 || fracPart != 0.0) {
        printf("\nThis is not a valid Employee Number.\nPlease run the program again");
        printf("\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    int employeeNumber = (int) intPart;

    //gathering input hourly salary
    printf("Enter Hourly Salary: ");
    scanf("%lf", &hourlySalary);
    if (hourlySalary <= 0) {
        printf("\nThis is not a valid hourly salary amount.\nPlease run the program again");
        printf("\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    //gather input weekly time
    printf("Enter Weekly Time: ");
    scanf("%lf", &weeklyTime);
    if (weeklyTime <= 0) {
        printf("\nThis is not a weekly time.\nPlease run the program again");
        printf("\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    printf("==============================\n");

    //bottom portion + math stuff to solve
    printf("Employee #: \t%d\n", employeeNumber);
    printf("Hourly Salary: \t$%.1f\n", hourlySalary);
    printf("Weekly Time: \t%.1f\n", weeklyTime);

    double regularPay = 0.0;
    double overtimePay = 0.0;
    double netPay = 0.0;

    //calculatiosn
    if (weeklyTime <= 40) {
        regularPay = weeklyTime * hourlySalary;
    } else {
        regularPay = 40.0 * hourlySalary;
        double overtimeHours = weeklyTime - 40.0;
        overtimePay = ((1.5*hourlySalary) * overtimeHours);
    }

    netPay = regularPay + overtimePay;

    //print calculations
    printf("Regular Pay: \t$%.1f\n", regularPay);
    printf("Overtime Pay: \t$%.1f\n", overtimePay);
    printf("Net Pay: \t$%.1f\n", netPay);

    printf("==============================\n");
    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
    exit(0);
    
}