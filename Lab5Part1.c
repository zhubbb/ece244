// Cathy Fu 1000510949
#include<stdio.h>
#include<math.h>

double func (double values [],double input)
{ // this function simple evaluates the polynomial
    double theend = 0.0;
    for (int i = 0; i<=4; i++)
    { // loops through x^4 -> x^0 , and coefficients in array
        theend += ((values [i])*(pow(input,(4-i))));
    }

    return theend;
}

double integral(double coeff[], double low, double high, double n)
{ // this evaluates the integral of function, uses polynomial function
    double p1, p2, p3, sum;
    // the parts of integral (in separate variables)
    p1 = (high-low)/n;
    p2 = func(coeff,low)/2;
    p3 = func(coeff,high)/2;

    for (int i = 1 ; i<n; i++)
    { // the summation part of integral
        double t = low + i*((high-low)/n);
        sum += func(coeff,t);
    }
    // puts parts together
    sum += (p2 + p3);
    sum *= p1;
    return sum;
}

int main (void)
{
    double bob [5]; // for coefficients
    double low = 0, high = 0.0,n = 0.0;

    printf("Enter the coefficients (a b c d e): ");
    for (int s = 0; s<5; s++)
    { // inputs entry into array
        scanf("%lf", &bob[s]);
    }
    // asks for rest of input
    printf("Enter the integral limits (low high): ");
    scanf("%lf %lf", &low, &high);

    printf("Enter the number of subintervals (n): ");
    scanf("%lf",&n);

    double re = integral(bob,low,high,n); // calls integral function
    printf("The value of the integral is: %f",re); // prints results
    return 0;
}
