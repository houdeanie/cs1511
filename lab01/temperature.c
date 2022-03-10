//Converting farenheit to Celsius

#include <stdio.h>

int main (void) {
   double fahrenheit, celsius;

   printf("Enter temperature: ");
   scanf("%lf", &fahrenheit);
   celsius = (fahrenheit-32)*5/9;
   printf("Celsius equivalent is %f\n", celsius);

   return 0;
}
