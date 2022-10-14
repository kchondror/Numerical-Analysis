#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void Pivoting (float A[][3],float P[][3],int column){
  float c=0;

  for(int i=2;i>0;i--){
        if(fabs(A[i-1][column])<fabs(A[i][column]))
            for(int j=0;j<3;j++){
                c=A[i][j];
                A[i][j]=A[i-1][j];
                A[i-1][j]=c;

                c=P[i][j];
                P[i][j]=P[i-1][j];
                P[i-1][j]=c;
            }
    }
}

void Print(float A[][3]){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        printf("%.2f ",A[i][j]);
      }
    printf("\n");
    }
}
float elim(float A[][3],int row,int column){

  float L;
  L=(float)A[row][column]/A[column][column];

  for(int i=column;i<3;i++){
        A[row][i]=A[row][i]-A[column][i]*L;
    }
  return L;
}

int main()
{
  float A[3][3]={{2,1,5},{4,4,-4},{1,3,1}};
  float b[3]={5,0,6};
  float P[3][3]={{1,0,0},{0,1,0},{0,0,1}};
  float L[3][3]={{1,0,0},{0,1,0},{0,0,1}};

  Pivoting(A,P,0);
  A[1][0]=elim(A,1,0);
  A[2][0]=elim(A,2,0);
  Pivoting(A,P,1);
  A[2][1]=elim(A,2,1);

  L[1][0]=A[1][0];
  L[2][0]=A[2][0];
  L[2][1]=A[2][1];

  int result[3]={0,0,0};
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      result[i]+=P[i][j]*b[j];
    }
  }

  float c[3];
  c[0]=result[0];
  c[1]=result[1]-L[1][0]*result[0];
  c[2]=result[2]-L[2][0]*result[0]-L[2][1]*c[1];

  float x[3];
  x[2]=c[2]/A[2][2];
  x[1]=(c[1]-A[1][2]*x[2])/A[1][1];
  x[0]=(c[0]-A[0][1]*x[1]-A[0][2]*x[2])/A[0][0];

  for(int i=0;i<3;i++)
    printf("%f\n",x[i]);
  return 0;
}
