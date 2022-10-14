#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{

    float x[10]={-2.89,-2.15,-1.72,
                0.50,0.55,0.73,
                1.14,1.56,1.94,
                2.63};

    float y[10]={-0.050418,-0.037515,-0.030015,
                0.008726,0.009599,0.012740,
                0.019895,0.027223,0.033852,
                0.045886};


    float numerator=1,denominator=1,xk,yk=0;

    printf("Enter the Value of x (-3.14,3.14) : ");
    scanf("%f",&xk);
    if(xk < -PI || xk > PI){
        printf("Out of Bounds!");
        exit(0);
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){

            if(i==j)
                continue;

            numerator *= (xk-x[j]);
            denominator *= (x[i]-x[j]);
        }

        yk += ((numerator/denominator)* y[i]);
        numerator=1;
        denominator=1;
    }
    printf("P9(x) = %.10f",yk);
    return 0;
}
