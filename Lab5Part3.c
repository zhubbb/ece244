// Cathy Fu 1000510949
#include<stdio.h>
#include<math.h>

double approxSine (double x, int N)
{ // computes approximation
    double result = 0.0, fa2 = 1, f2=1;
    for (int n = 0; n<N; n++)
    { // computes the standard formula for one member of series
        // repeats until designated accuracy reached
        double factorial = 1;
        double a1 = pow (-1, n);
        double a2 = ((2*n)+1);
        for (int z = a2; z > fa2; z--)
        { // stops when reached last factorial value (to speed things up)
            factorial*=z;
        }
        factorial *=f2; // multiply by last value (ie. 5! then 7! (but 7! = 7*6*5!))
        fa2 = a2;
        f2 = factorial;
        double r1 = (a1*(pow(x,a2)))/factorial; // divides top by bottom
        result +=r1; // adds it to what's already present
    }
    return result;
}

int main (void)
{
    int N =0;
    double x, low=0, high=0, step=0;
    // prompt for input by user
    printf("Enter N: ");
    scanf("%d", &N);

    printf("Enter low: ");
    scanf("%lf", &low);

    printf("Enter high: ");
    scanf("%lf", &high);

    printf("Enter step: ");
    scanf("%lf", &step);

   for (double s = low; s <= high; s+= step)
    { // runs function for each x in [low,high]
        double num = approxSine(s,N);
        printf("%.2f %.2f\n",s,num);
    }
}
