#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Precision 0.000005

double Fx(double x){
    return (exp(pow(sin(x),3)) + pow(x,6) - 2*pow(x,4) - pow(x,3) -1);
}

void Bisection(double a , double b){
    double c=a;

    while(fabs(b-a)>= Precision){
        c=(a+b)/2;
        if(Fx(c)==0){
            printf("1 root found : %.5lf",c);
            break;
        }

        if(Fx(a)*Fx(c)<0){
            b=c;
            printf("[%f,%f]\n",a,b);
        }
        else{
            a=c;
            printf("[%f,%f]\n",a,b);
        }
    }
    printf("1 root found close to : %.5lf",c);

}

int main()
{
    float a,b;
    printf("Give two numbers between [-2,2] (a<b)\na:");
    scanf("%f",&a);
    printf("b:");
    scanf("%f",&b);


    if(a==0 &&b==0){
        printf("x = 0 is a root");
        exit(0);
    }else if(a<-2||a>2||b<-2||b>2||b<a){
        printf("Wrong Input");
        exit(0);
    }else if(Fx(a)*Fx(b)>=0){
        printf("Cant find a root between %f ,%f",a,b);
        exit(0);
    }else
        Bisection(a,b);

    return 0;
}
