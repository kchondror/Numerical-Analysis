#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

#define Tol 0.00005

double Max(double arr[],int n)
{
    double max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void GaussSeidel(double A[][N],double B[]){

    double *x,*x0,error;
    double sum=0;
    int k=0;
    x=(double *)malloc(N*sizeof(x[0]));
    x0=(double *)malloc(N*sizeof(x0[0]));

    memset(x,0,N*sizeof(x[0]));
    memset(x0,0,N*sizeof(x0[0]));

    do{
      for(int i=0;i<N;i++){
        sum=B[i];
        for(int j=0;j<N;j++){
            if(i==j)
              continue;
            sum-=(float)A[i][j]*x[j];
        }

        x[i]=sum/A[i][i];
        printf("x%d  = %lf \n",k++,x[i]);
      }
      error=fabs(Max(x0,N)-Max(x,N));
      for(int k=0;k<N;k++){
        x0[k]=x[k];
      }
    }while(error>=Tol);
}

int main()
{
    double A[N][N],*B;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)
                A[i][j]=5;
            else if(j==i+1 || j==i-1)
                A[i][j]=-2;
            else
                A[i][j]=0;
        }
    }
    B=(double *)calloc(N,sizeof(B[0]));

    B[0]=3;
    for(int i=1;i<N-1;i++)
        B[i]=1;
    B[N-1]=3;

    GaussSeidel(A,B);

    return 0;
}
