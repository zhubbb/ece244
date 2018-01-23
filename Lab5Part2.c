// Cathy Fu 1000510949
#include<stdio.h>
#include<math.h>

double sizeofbin(double low, double high, int n)
{ // finds size of each bin
    return ((high-low)/n);
}

int sortbin(double input, double low, double howbig)
{ // puts number in right bin
    return floor((input - low)/howbig);
}

int main(void)
{
    double low, high, value, binsize;
    int n;
    // prompts for user input
    printf("Enter the limits (low high): ");
    scanf("%lf %lf", &low, &high);

    printf("Enter N: ");
    scanf("%d",&n);
    binsize = sizeofbin(low,high,n);
    int histogram [n]; // creates correct sized histogram using number of bins

    for (int a = 0; a < n; a++)
    { // sets all values to 0
        histogram[a] = 0;
    }
    printf("Enter the values.\n");
    scanf("%lf",&value);

    while (value >= low && value < high)
    {   // check which bin its in, increments count for that bin
        int which = sortbin(value,low,binsize);
        histogram[which]++;
        scanf("%lf",&value); // asks for next value
    }

    printf("The histogram values are:");
    double b = low + (binsize / 2); // middle of first bin
    for (int a = 0; a < n; a++)
    { // prints values of histogram
        printf("\n%.2f %d", b, histogram[a]);
        b+= binsize;
    }
    return 0;
}

