#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double f(double x){
    return sin(x);
}

double Trapezoidal(double *x,int size){

    double sum=0;
    for(int i=1;i<size;i++)
        sum+=f(x[i]);

    sum=sum*2;
    sum+=f(x[0]);
    sum+=f(x[size]);

    return ((x[size] -x[0])/(2*(size))) *sum;
}



int main()
{
    double x[12]={0};

    double min=(PI/2)/11;

    for(int i=1;i<12;i++){
        x[i]=x[i-1]+min;
    }

    printf("The result is : %.8lf",Trapezoidal(x,11));
    return 0;
}
