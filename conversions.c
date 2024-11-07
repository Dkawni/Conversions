#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

/*
reads the user response and goes through many functions to calculate
the original unit to a new unit.
*/

bool isValidFormat(const int numArgsNeeded, const int numArgsRead, bool shouldBeLastValueOnLine) { //checks to see if the format the user input is only one character
    bool formatIsCorrect = numArgsRead == numArgsNeeded;
    if (shouldBeLastValueOnLine) {
        char shouldBeNewLine = '?';
        scanf("%c", &shouldBeNewLine);
        formatIsCorrect = formatIsCorrect && shouldBeNewLine == '\n';
    }
    return formatIsCorrect;
}

char NewUnitType(char userChoice, char newDistChoice, char newTempChoice) { 
    /*is used to call the new unit the user wants to conver it to. Convenient so that
    the invalid format and the user choice don't clash - catches invalid format before moving on
    */
    if (userChoice == 'D'){
        printf("Enter the new unit type (I,F,Y,M): ");
        scanf("%c", &newDistChoice);
        newDistChoice = toupper(newDistChoice);
        return newDistChoice;
    } else if (userChoice == 'T') {
        printf("Enter the new unit type (F, C, or K): ");
        scanf("%c", &newTempChoice);
        newTempChoice = toupper(newTempChoice);
        return newTempChoice;
    }
    return 0;
}

double ConvertInches(char newDistChoice, double origDist) {
    /*
    converts to other units whenever the user enters inches. many if statements
    to convert from inches to the many other options they have to choose from.
    */
    
    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (newDistChoice == 'F') {
        origDist = origDist/12;
    } else if (newDistChoice == 'Y') {
        origDist = origDist/36;
    } else if (newDistChoice == 'M') {
        origDist = origDist/63360;
    } else if (newDistChoice == 'I') {
        return origDist;
    } else {
        printf("%c is not a valid distance type. Ending program.\n", newDistChoice);
        exit(0);
    }
    return origDist;
}

double ConvertFeet(char newDistChoice, double origDist) {
    /*
    Converts to other units when the user enters feet. if statements to convert
    from feet to many other options they have to choose from.
    */

    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (newDistChoice == 'I') { //work on conversions
        origDist = origDist*12;
    } else if (newDistChoice == 'Y') {
        origDist = origDist/3;
    } else if (newDistChoice == 'M') {
        origDist = origDist/5280;
    } else if (newDistChoice == 'F') {
        return origDist;
    } else {
        printf("%c is not a valid distance type. Ending program.\n", newDistChoice);
        exit(0);
    }
    return origDist;
}

double ConvertMiles(char newDistChoice, double origDist) {
    /*
    Converts to other units when the user enters mils. if statements to convert
    from mils to many other options they have to choose from.
    */

    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (newDistChoice == 'I') { //work on conversions
        origDist = origDist*63360;
    } else if (newDistChoice == 'Y') {
        origDist = origDist*1760;
    } else if (newDistChoice == 'F') {
        origDist = origDist*5280;
    } else if (newDistChoice == 'M') {
        return origDist;
    } else {
        printf("%c is not a valid distance type. Ending program.\n", newDistChoice);
        exit(0);
    }
    return origDist;
}

double ConvertYards(char newDistChoice, double origDist) {
    /*
    Converts to other units when the user enters yards. if statements to convert
    from yards to many other options they have to choose from.
    */

    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (newDistChoice == 'I') { //work on conversions
        origDist = origDist*36;
    } else if (newDistChoice == 'F') {
        origDist = origDist*3;
    } else if (newDistChoice == 'M') {
        origDist = origDist/1760;
    } else if (newDistChoice == 'Y') {
        return origDist;
    } else {
        printf("%c is not a valid distance type. Ending program.\n", newDistChoice);
        exit(0);
    }
    return origDist;
}

double ConvertFahrenheit(char newTempChoice, double origTemp) {
    /*
    Converts to other units when the user enters fahrenheit. if statements to convert
    from fahrenheit to many other options they have to choose from.
    */
    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (newTempChoice == 'C') { 
        origTemp = (origTemp - 32) * (5.0/9.0);
    } else if (newTempChoice == 'K') {
        origTemp = (origTemp - 32) * (5.0/9.0) + 273.15;
    } else if (newTempChoice == 'F') {
        return origTemp;
    } else {
        printf("%c is not a valid temperature type. Ending program.\n", newTempChoice);
        exit(0);
    }
    return origTemp;
}

double ConvertKelvin(char newTempChoice, double origTemp) {
    /*
    Converts to other units when the user enters kelvin. if statements to convert
    from kelvin to many other options they have to choose from.
    */
    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (newTempChoice == 'F') { 
        origTemp = (origTemp - 273.15) * (9.0/5.0) + 32;
    } else if (newTempChoice == 'C') {
        origTemp = origTemp - 273.15;
    } else if (newTempChoice == 'K') {
        return origTemp;
    } else {
        printf("%c is not a valid temperature type. Ending program.\n", newTempChoice);
        exit(0);
    }
    return origTemp;
}

double ConvertCelsius(char newTempChoice, double origTemp) {
    /*
    Converts to other units when the user enters celsius. if statements to convert
    from celsius to many other options they have to choose from.
    */  

    if (!isValidFormat(1, 1, true)){ //checks if one character
        printf("Invalid formatting. Ending program.");
        exit(0);
    } else if (newTempChoice == 'F') {
        origTemp = origTemp * (9.0/5.0) + 32;
    } else if (newTempChoice == 'K') {
        origTemp = origTemp + 273.15;
    } else if (newTempChoice == 'C') {
        return origTemp;
    } else {
        printf("%c is not a valid temperature type. Ending program.\n", newTempChoice);
        exit(0);
    }
    return origTemp;
}

int main() { //brings all the functions together for all different options

    char userChoice;

    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf("%c", &userChoice);

    userChoice = toupper(userChoice); //for convenience with if statements

    if (!isValidFormat(1, 1, true)){ //checks if the userChoice is a character
        printf("Invalid formatting. Ending program.");
        exit(0);

    } else if (userChoice == 'D') { //Distance branch
        
        char distChoice;
        char newDistChoice = '\0';
        double origDist;

        printf("Enter the distance followed by its suffix (I,F,Y,M): \n");
        scanf("%lf %c", &origDist, &distChoice);
        distChoice = toupper(distChoice); //for convenience with if statements

        if (!isValidFormat(2, 2, true)){ //checks if the distChoice is a character
        printf("Invalid formatting. Ending program.");
        exit(0);

        } else if (distChoice == 'I') { //if chose inches
            newDistChoice = NewUnitType(userChoice, newDistChoice, 'A'); //Asking the user for the new distant choice. 'A' is used to not trigger the temperature event
            printf("%.2lf%c is %.2lf%c", origDist, distChoice, ConvertInches(newDistChoice, origDist), newDistChoice);
        } else if (distChoice == 'F') { //if chose feet
            newDistChoice = NewUnitType(userChoice, newDistChoice, 'A'); 
            printf("%.2lf%c is %.2lf%c", origDist, distChoice, ConvertFeet(newDistChoice, origDist), newDistChoice);
        } else if (distChoice == 'Y') { //if chose yards
            newDistChoice = NewUnitType(userChoice, newDistChoice, 'A'); 
            printf("%.2lf%c is %.2lf%c", origDist, distChoice, ConvertYards(newDistChoice, origDist), newDistChoice);
        } else if (distChoice == 'M') { //if chose miles
            newDistChoice = NewUnitType(userChoice, newDistChoice, 'A'); 
            printf("%.2lf%c is %.2lf%c", origDist, distChoice, ConvertMiles(newDistChoice, origDist), newDistChoice);
        } else { //if its a character but doesnt correlate to a unit type
            printf("%c is not a valid distance type. Ending program.\n", distChoice);
            exit(0);
        }

    } else if (userChoice == 'T') { //Temperature branch
        
        char tempChoice;
        char newTempChoice = '\0';
        double origTemp;

        printf("Enter the temperature followed by its suffix (F, C, or K): \n");
        scanf("%lf %c", &origTemp, &tempChoice);
        tempChoice = toupper(tempChoice); //for convenience with if statements

        if (!isValidFormat(2, 2, true)){
        printf("Invalid formatting. Ending program.");
        exit(0);

        } else if (tempChoice == 'F') { //if chose fahrenheit
            newTempChoice = NewUnitType(userChoice, 'A', newTempChoice); //Asking the user for the new temperature choice. 'A' is used to not trigger the distance event
            printf("%.2lf%c is %.2lf%c", origTemp, tempChoice, ConvertFahrenheit(newTempChoice, origTemp), newTempChoice);
        } else if (tempChoice == 'C') { //if chose celsius
            newTempChoice = NewUnitType(userChoice, 'A', newTempChoice);
            printf("%.2lf%c is %.2lf%c", origTemp, tempChoice, ConvertCelsius(newTempChoice, origTemp), newTempChoice);
        } else if (tempChoice == 'K') { //if chose kelvin
            newTempChoice = NewUnitType(userChoice, 'A', newTempChoice);
            printf("%.2lf%c is %.2lf%c", origTemp, tempChoice, ConvertKelvin(newTempChoice, origTemp), newTempChoice);
        } else { //if its a character but doesn't correlate with unit type
            printf("%c is not a valid temperature type. Ending program.\n", tempChoice);
        }

    } else { //if its a character but doesnt correlate with unit type
        printf("Unknown conversion type %c chosen. Ending program.\n", userChoice);
    }


}