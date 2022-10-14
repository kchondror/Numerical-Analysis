#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Precision 0.000005

double Fx(double x){
    return (exp(pow(sin(x),3)) + pow(x,6) - 2*pow(x,4) - pow(x,3) -1 );
}

double Secant(double x0,double x1){
    int k=0;
    double x2=0;

    do
    {
        k++;
        x2=x1-((Fx(x1)*(x1-x0))/(Fx(x1)-Fx(x0)));
        x0=x1;
        x1=x2;

        printf("x%d=%lf\n",k,x1);

    }while(fabs(Fx(x2))>=Precision);
    return x2;
}

int main()
{
    float a,b;
    printf("Give two numbers between [-2,2] \na:");
    scanf("%f",&a);
    printf("b:");
    scanf("%f",&b);


    if(a<-2||a>2||b<-2||b>2){
        printf("Wrong Input");
        exit(0);
     }else if(a==0 && b==0){
        printf("x = 0 is a root");
        exit(0);
    }else if(Fx(a)*Fx(b)>=0){
        printf("Cant find a root between %f ,%f",a,b);
        exit(0);
    }else
        Secant(a,b);
    return 0;
}
