#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

float f(float);
float g(float);


float f(float x)
{
    return g(x-1) + 2*x;
}

float g(float y)
{
    return y*y + 3;
}

int main(int argc,char **argv)
{
    
   
    cout << "f(2) = " << f(2) << endl;

    return 0;
}
