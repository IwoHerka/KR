/*
 * 1.15. Rewrite the temperature conversion program of Section 1.2 to use a 
 * function for conversion. 
 */

#include <stdio.h>

float fahr_to_cels(float fahr);

int main()
{
        float fahr, celsius;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;

        while (fahr <= upper) {
                celsius = fahr_to_cels(fahr);
                printf("%3.0f %6.1f\n", fahr, celsius);
                fahr = fahr + step;
        }

        return 0;
}

float fahr_to_cels(float fahr)
{
        return (5.0/9.0) * (fahr-32.0);
}
