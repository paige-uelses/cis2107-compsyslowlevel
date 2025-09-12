// Paige Uelses
// 09/08/2025
// CIS2107_03 Lab_02
// Problem: Calculate sales total with discounts and user input validation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double itemPrice;
    double itemQuant;

    printf("Welcome to \"Temple\" store\n\n");

    //gather & validate inputs
    printf("Enter item price: ");
    scanf("%lf", &itemPrice);
    if (itemPrice <= 0) {
        printf("\nThis is not a valid item price.\nPlease run the program again");
        printf("\n\nThank You for using \"Temple\" store");
        exit(1);
    }

    printf("Enter quantity: ");
    scanf("%lf", &itemQuant);
    
    double intPart;
    double fracPart = modf(itemQuant, &intPart);
    
    if (itemQuant <= 0 || fracPart != 0.0) {
        printf("\nThis is not a valid quantity order.\nPlease run the program again");
        printf("\n\nThank You for using \"Temple\" store");
        exit(1);
    }

    int itemQuantity = (int) intPart;

    //calculate stuff
    printf("\nThe item price is: $%.1f\n", itemPrice);
    printf("The order is: %d item(s)\n", itemQuantity);

    double orderCost = 0.0;
    double discount = 0.0;
    double discountAmount = 0.0;
    double orderTotal = 0.0;

    orderCost = itemPrice * itemQuantity;

    //calc discount %
    if (itemQuantity <= 49){
        discount = 0.0;
    } else if (itemQuantity >= 50 && itemQuantity <= 99){
        discount = 10.0;
    } else if (itemQuantity >= 100 && itemQuantity <= 149){
        discount = 15.0;
    } else {
        discount = 25.0;
    }

    //calc discount amout
    discountAmount = (discount / 100) * orderCost;

    orderTotal = orderCost - discountAmount;

    //print final calculations
    printf("The cost is: $%.1f", orderCost);
    printf("\nThe discount is: %.1f%%", discount);
    printf("\nThe discount amount is: $%.1f", discountAmount);
    printf("\nThe total is: $%.1f", orderTotal);

    printf("\n\nThank You for using \"Temple\" store");
    exit(0);

}