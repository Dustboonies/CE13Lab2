/*************************************
 Project:  Lab 02
 Author: Dustin Feldsine, 1450786
 Date Completed: 1/20/16
 Language: C
 *************************************/


// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <math.h>

//CMPE13 Support Library
#include "BOARD.h"

// Microchip libraries
#include <xc.h>
#include <plib.h>

// User libraries


// **** Set macros and preprocessor directives ****

// **** Define global, module-level, or external variables here ****

// **** Declare function prototypes ****
double Round(double x);
double absoluted(double x);
double celci(double x);
double fahren(double x);
double avrg(double x,double y);
double tang(double x);
void helpPls();
// If this code is used for testing, rename main to something we can call from our testing code.
#ifndef LAB2_TESTING

int main(void)
{
    BOARD_Init();
    
/*********************************************************************************
 TEST CODE
 *********************************************************************************/
//    double  a;
//    a=25;
//    a=absoluted(a);
//    printf("%f\n", a);
/*********************************************************************************
 END TEST CODE
 *********************************************************************************/
#else

int their_main(void)
{
#endif // LAB2_TESTING

    /******************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     *****************************************************************************/
    printf("%s\n", "Welcome to Dustin's Calculator Program!!");
    while (1) {
        printf("%s\n", "Please enter the operator you would like to calculate (*,/,+,-,v,a,c,f,t,r or ? for help)");
        char c = '0';
        char z = '0';
        double o1 = 0;
        double o2 = 0;
        scanf("%c%c", &c, &z);
        if (c != '0') {
            printf("%s\n","Please enter first operand:");
            scanf("%lf%c", &o1,&z);
            printf("%f\n",o1);
            if (c == '*' || c == '/' || c == '+' || c == '-' || c == 'v') {
                printf("%s\n","Please enter second operand:");
                scanf("%lf%c", &o2,&z);
                printf("%f\n",o2);
            }
            if (c == '?') {
                helpPls();
                c = '0';
            } else if (c == '*') {
                printf("%s%f%c%f\n", "Your equation is: ",o1,'*',o2);
                o1 = o2*o1;
            } else if (c == '/') {
                printf("%s%f%c%f\n", "Your equation is: ",o1,'/',o2);
                if (o2 == 0) {
                    printf("%s", "Your result is: undefined (0 denominator)");
                } else {
                    o1 = o1 / o2;
                }
            } else if (c == '+') {
                printf("%s%f%c%f\n", "Your equation is: ",o1,'+',o2);
                o1 = o1 + o2;
            } else if (c == '-') {
                printf("%s%f%c%f\n", "Your equation is: ",o1,'-',o2);
                o1 = o1 - o2;
            } else if (c == 'v') {
                printf("%s%f%c%f\n", "Your equation is the average of: ",o1,'&',o2);
                o1 = avrg(o1, o2);
            } else if (c == 'a') {
                printf("%s%f\n", "You taking the absolute value of: ",o1);
                o1 = absoluted(o1);
            } else if (c == 'c') {
                printf("%s%f%s\n", "You are converting ",o1,"to celcius");
                o1 = celci(o1);
            } else if (c == 'f') {
                printf("%s%f%s\n", "You are converting ",o1,"to fahrenheit");
                o1 = fahren(o1);
            } else if (c == 't') {
                printf("%s%f\n", "You getting the tangent of ",o1);
                o1 = tang(o1);
            } else if (c == 'r') {
                printf("%s%f\n", "You are rounding ",o1);
                o1=Round(o1);
            }
            printf("%s%f", "Your result is: ", o1);
        }
    }






    /******************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     *****************************************************************************/
    while (1);
}

/********************************************************************************
 * Define the Absolute Value function here.
 ********************************************************************************/
double absoluted(double x)
{
    if (x < 0) {
        x = -x;
    }
    return x;
}

/*********************************************************************************
 * Define the Fahrenheit to Celsius function here.
 ********************************************************************************/
double celci(double x)
{
    x = (x - 32)*(0.555556);
    return x;
}

/*********************************************************************************
 * Define the Celsius to Fahrenheit function here.
 ********************************************************************************/

double fahren(double x)
{
    x = x * (9 / 5) + 32;
    return x;
}

/********************************************************************************
 * Define the Average function here.
 *******************************************************************************/

double avrg(double x, double y)
{
    x = (x + y) / 2;
    return x;
}

/*********************************************************************************
 * Define the Tangent function that takes input in degrees (Note: Your tangent 
 * function relies on a call from the tangent function of math.h which uses 
 * radians).
 ********************************************************************************/

double tang(double x)
{
    x = (x / 180) * M_PI;
    x = tan(x);
    return x;
}

/*********************************************************************************
 * Define the Round function here.
 * In order to receive the extra credit your calculator MUST ALSO CORRECTLY utilize
 * this function.
 ********************************************************************************/
double Round(double x)
{
    int y;
    x=x+.5;
    y=(int) x;
    return (double) y;
}

/*********************************************************************************
 * Help Function
 * Self Defined
 * DIsplays all of the possible operators
 ********************************************************************************/
void helpPls()
{
    printf("%s\n", "* is multiply");
    printf("%s\n", "/ is divide");
    printf("%s\n", "+ is addition");
    printf("%s\n", "- is subtraction");
    printf("%s\n", "v is average");
    printf("%s\n", "a is absolute value");
    printf("%s\n", "c converts fahrenheit to celcius");
    printf("%s\n", "f converts celcius to fahrenheit");
    printf("%s\n", "t returns the tangent of an angle in degrees");
    printf("%s\n", "r rounds the number");
}
