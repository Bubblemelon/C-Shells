#include<stdio.h>

/*
 * A program that converts fahrenheit to celsius.
 *
 * (°F − 32) × 5/9 = 0°C
 */
#define FREEZING_POINT 32.0f
#define FACTOR (5.0f/9.0f)

/*
 * Avoid using integers for division e.g
 * d = 5/9 = 0.55555555555
 * if d was type int, then d = 0 !!!
 *
 * Integers truncate decimal values.
 */


int main()
{
    float fahrenheit;
    int c;

    printf("\n~~~ Fahrenheit to Celsius Converter ~~~\n");
    printf("Enter temperature in fahrenheit: ");

    // store the input at the memory location of variable f
    scanf("%f", &fahrenheit);

    float celsius = ((fahrenheit - FREEZING_POINT) * FACTOR);

    printf("\nUsing 'floats' for calculation:\n");
    printf("Temperature %.2fF is %.2fC.\n",
            fahrenheit,
            celsius
           );

    c = celsius;

    printf("\nTemperature in celsius gets truncated when using 'integers': %d\n", c);

    return 0;
}