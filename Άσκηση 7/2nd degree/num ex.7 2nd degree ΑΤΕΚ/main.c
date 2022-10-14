#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void multATA(float transpose[][10],float A[][3],float ATA[][3],int r1,int c1,int r2 ,int c2){

    for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         ATA[i][j] = 0;
      }
   }

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            ATA[i][j] += transpose[i][k] * A[k][j];
         }
      }
   }

}

void multATb(float transpose[][10],float b[],float ATb[],int r1,int c1,int r2){

    for (int i = 0; i < r1; ++i) {
         ATb[i] = 0;
   }

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c1; ++j) {
            ATb[i] += transpose[i][j] * b[j];
      }
   }

}

void gaussElimination(float a[][4],float x[]){


	float temp,s;


	for(int j=0; j<2; j++)
		for(int i=j+1; i<3; i++){
			temp=a[i][j]/a[j][j];
			for(int k=0; k<4; k++)
				a[i][k]-=a[j][k]*temp;
		}

	for(int i=2; i>=0; i--){
		s=0;
		for(int j=i+1; j<3; j++)
            s += a[i][j]*x[j];
		x[i]=(a[i][3]-s)/a[i][i];
	}
}


int main()
{
    //y = a +b*x +c*x^2  x={1,2,....,10}
    float A[10][3]={{1,1,1},{1,2,4},{1,3,9},{1,4,16},{1,5,25},{1,6,36},{1,7,49},{1,8,64},{1,9,81},{1,10,100}};

    float b[10]={0.36,0.398,0.398,0.362,0.362,0.362,0.362,0.382,0.404,0.404};

    float transpose[3][10];

    float ATA[3][3];
    float ATb[3];


    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = A[i][j];
        }

    multATA(transpose,A,ATA,3,10,10,3);
    multATb(transpose,b,ATb,3,10,10);


    float a[3][4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            a[i][j]=ATA[i][j];
        }
    }

    for(int i=0;i<3;i++){
        a[i][3]=ATb[i];
    }


    float x[3];
    gaussElimination(a,x);


    int t;

    printf("Enter the Value of x : ");
    scanf("%d",&t);
    if(t<0|| t>31){
        printf("Wrong Input");
        exit(0);
    }


    printf("The stock of A.T.E.K is going to be : %lf ",x[0]+t*x[1]+pow(t,2)*x[2]);


    return 0;
}
