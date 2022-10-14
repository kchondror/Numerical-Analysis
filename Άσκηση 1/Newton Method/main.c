#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Precision 0.000005

double Fx(double x){
    return (exp(pow(sin(x),3)) + pow(x,6) - 2*pow(x,4) - pow(x,3) -1 );
}

double fx(double x){
    return (exp(pow(sin(x),3))*3*pow(sin(x),2)*cos(x)+6*pow(x,5)-8*pow(x,3)-3*pow(x,2));
}

double ffx(double x){
    return (30*pow(x,4)-24*pow(x,2)-6*x-3*exp(pow(sin(x),3))*pow(sin(x),3)+6*exp(pow(sin(x),3))*sin(x)*pow(cos(x),2)+9*exp(pow(sin(x),3))*pow(sin(x),4)*pow(cos(x),2));
}

double Newton(double x2){
    int k=0;
    double x1=0;

    do
    {
        x1=x2;
        k++;
        x2=x2-Fx(x2)/fx(x2);
        printf("x%d=%.5lf \n",k,x2);

    }while(fabs(x2-x1)>=Precision);
    printf("\nf(x%d)=",k+1);
    return x2;
}

int main()
{
    double x0;
    printf("Give the value of x0 between [-2,2]:");
    scanf("%lf",&x0);

    if(x0<-2||x0>2 || Fx(x0)*ffx(x0)<0){
        printf("Wrong Input");
        exit(0);
    }

    if(x0==0)
        printf("x = 0 is a root");
    else
        printf("%.5lf",Newton(x0));

    return 0;
}
