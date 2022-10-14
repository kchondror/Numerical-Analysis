#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Precision 0.000005

double Fx(double x){

    return (94*pow(cos(x),3)-24*cos(x)+177*pow(sin(x),2)-108*pow(sin(x),4)
            -72*pow(cos(x),3)*pow(sin(x),2)-65);
}

float generate_random(double a, double b) {

    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;

}

void Bisection(double a , double b){
    srand(time(0));
    double c=a;
    int k=0;


    while(fabs(b-a)>= Precision){

        c=generate_random(a,b);
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
        k++;
    }
    printf("1 root found close to : %.5lf\n %d",c,k);
}

int main()
{
    float a,b;
    printf("Give a space of numbers between [0,3] \na:");
    scanf("%f",&a);
    printf("b:");
    scanf("%f",&b);

    if(a<=0||a>3||b<=0||b>3||b<=a){
        printf("Wrong Input");
        exit(0);
    }else if(Fx(a)*Fx(b)>=0){
        printf("Cant find a root between %f ,%f",a,b);
        exit(0);
    }else
        Bisection(a,b);

    return 0;
}
