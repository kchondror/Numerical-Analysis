#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define q 0.15

float N(int A[][15],int i){
  int sum=0;
  for(int j=0;j<15;j++){
    sum+=A[i][j];
  }
  return sum;
}

double mult(double A[][15],double b1[]){
  double temp[15];
    for(int i=0;i<15;i++){
      temp[i]=0;
      for(int j=0;j<15;j++){
            temp[i]+=(float)A[i][j]*b1[j];
      }
    }

    for(int i=0;i<15;i++){
       b1[i]=temp[i];

    }
    return b1[0];
}




int main(void) {
  int A[15][15]={
  {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
  };
  double G[15][15];

  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      G[i][j]=(float)q/15 + (A[j][i]*(1-q))/N(A,j);
      //printf("%.3lf ",G[i][j]);
    }
    //printf("\n");
  }

  double p[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  double temp1=0,temp2=0;

  do{
    temp2=temp1;
    temp1=mult(G,p);
    for(int j=0;j<2;j++){
      p[j]=(1/temp1)*p[j];
    }
  }while(fabs(temp1-temp2)>=0.0000000005);

  double sum=0;
  for(int i=0;i<15;i++){
    sum+=p[i];
  }

  for(int i=0;i<15;i++){
    p[i]/=sum;
    printf("%lf\n",p[i]);
  }



  return 0;
}
