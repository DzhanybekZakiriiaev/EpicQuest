#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double exponent(double, double);
void printWelcomeMenu();
void printOptions();

void calculator() {

    printWelcomeMenu();
    printOptions();

    int inputNum;
    double num1, num2;

    printf("Enter the first value:");
    scanf("%lf", &num1);
    printf("Enter the second value:");
    scanf("%lf", &num2);

    printf("Enter operation number: ");
    scanf("%d", &inputNum); // Changed format specifier to %d for decimal input

    switch (inputNum)
    {
    case 1:
        printf("%lf + %lf = %lf\n", num1, num2, add(num1, num2));
        break;
    case 2:
        printf("%lf - %lf = %lf\n", num1, num2, subtract(num1, num2));
        break;
    case 3:
        printf("%lf * %lf = %lf\n", num1, num2, multiply(num1, num2));
        break;
    case 4:
        printf("%lf / %lf = %lf\n", num1, num2, divide(num1, num2));
        break;
    case 5:
        printf("%lf ^ %lf = %lf\n", num1, num2, exponent(num1, num2));
        break;
    }
}

void printWelcomeMenu() {
    printf(" **********************\n");
    printf("**   Welcome to the   **\n");
    printf("**   BCS Calculator   **\n");
    printf(" **********************\n");
}

void printOptions() {
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exponent\n");
}

double add(double num1, double num2) {
    double result = num1 + num2;
    return result;
}

double subtract(double num1, double num2) {
    double result = num1 - num2;
    return result;
}

double multiply(double num1, double num2) {
    double result = num1 * num2;
    return result;
}

double divide(double num1, double num2) {
    double result = num1 / num2;
    return result;
}

double exponent(double num1, double num2) {
    double result = pow(num1, num2);
    return result;
}
