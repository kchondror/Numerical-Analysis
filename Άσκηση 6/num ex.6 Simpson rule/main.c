#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double f(double x){
    return sin(x);
}

double Simpson(double *x,int size){

    double sum1=0,sum2=0,sum=0;


    for(int i=1;i<=size/2-1;i++)
            sum1+=f(x[2*i]);

    sum1*=2;

    for(int i=1;i<=size/2;i++)
            sum2+=f(x[2*i-1]);

    sum2*=4;
    sum=(sum1+sum2 +f(x[0])+f(x[size]))*((x[size]-x[0])/(3*size));

    return sum;
}



int main()
{
    double x[12]={0};

    double min=(PI/2)/11;

    for(int i=1;i<12;i++){
        x[i]=x[i-1]+min;
    }

    printf("The result is : %lf",Simpson(x,11));

    return 0;
}
