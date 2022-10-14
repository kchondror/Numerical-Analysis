#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Precision 0.000005

double Fx(double x){

    return (94*pow(cos(x),3)-24*cos(x)+177*pow(sin(x),2)-108*pow(sin(x),4)
            -72*pow(cos(x),3)*pow(sin(x),2)-65);
}
double q(double x1,double x2){
    return Fx(x1)/Fx(x2);
}
double r(double x3,double x2){
    return Fx(x3)/Fx(x2);
}
double s(double x3,double x1){
    return Fx(x3)/Fx(x1);
}


double Secant(double x1,double x2,double x3){
    int k=0;
    double x4=0;

    do
    {
        k++;
        x4=x3 -((r(x3,x2)*(r(x3,x2)-q(x1,x2))*(x3 -x2)+(1-r(x3,x2))*s(x3,x1)*(x3-x1))/((q(x1,x2)-1)*(r(x3,x2)-1)*(s(x3,x1)-1)));

        x1=x2;
        x2=x3;
        x3=x4;

        printf("x%d=%lf\n",k,x4);

    }while(fabs(Fx(x4)-Fx(x2))>=Precision);
    return x4;
}

int main()
{
    double a,b,c;
    printf("Give the 3 numbers between [0,3].\na:");
    scanf("%lf",&a);
    printf("b:");
    scanf("%lf",&b);
    printf("c:");
    scanf("%lf",&c);

    if(a<0 ||a>3 || b<0 || b>3 || c<0 || c>3){
        printf("Wrong Input");
        exit(0);
    }
    if(Fx(a)*Fx(b)>=0){
        if(Fx(a)*Fx(c)>=0){
            printf("There are no roots in that space..");
            exit(0);
        }
        else{
        printf("%lf ",Secant(a,b,c));
        }
    }
    else
        printf("%lf ",Secant(a,b,c));


    return 0;
}
