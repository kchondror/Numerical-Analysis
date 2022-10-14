#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Precision 0.000005

double Fx(double x){

    return (94*pow(cos(x),3)-24*cos(x)+177*pow(sin(x),2)-108*pow(sin(x),4)
            -72*pow(cos(x),3)*pow(sin(x),2)-65);
}

double fx(double x){

    return(-282*sin(x)*pow(cos(x),2) + 24*sin(x) +354*sin(x)*cos(x) -432*pow(sin(x),3)*cos(x)
           +72*sin(x)*pow(cos(x),2)*(3*pow(sin(x),2)-2*pow(cos(x),2)));
}

double ffx(double x){

    return (-282*(pow(cos(x),3)-2*pow(sin(x),2)*cos(x)) +24*cos(x) +354*(pow(cos(x),2)-pow(sin(x),2)) +
            432*pow(sin(x),2)*(pow(sin(x),2)-3*pow(cos(x),2) )-72*(2*pow(cos(x),5)
            -17*pow(sin(x),2)*pow(cos(x),3)+6*pow(sin(x),4)*cos(x)));
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
    printf("\nf(x%d)=",k);
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
