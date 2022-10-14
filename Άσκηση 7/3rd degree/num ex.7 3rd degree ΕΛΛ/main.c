#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void multATA(float transpose[][10],float A[][4],float ATA[][4],int r1,int c1,int r2 ,int c2){

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

void gaussElimination(float a[][5],float x[]){


	float temp,s;


	for(int j=0; j<3; j++)
		for(int i=j+1; i<4; i++){
			temp=a[i][j]/a[j][j];
			for(int k=0; k<5; k++)
				a[i][k]-=a[j][k]*temp;
		}



	for(int i=3; i>=0; i--){
		s=0;
		for(int j=i+1; j<4; j++)
            s += a[i][j]*x[j];
		x[i]=(a[i][4]-s)/a[i][i];
	}


}


int main()
{
    float A[10][4]={{1,1,1,1},{1,2,4,8},{1,3,9,27},{1,4,16,64},{1,5,25,125},{1,6,36,216},{1,7,49,343},{1,8,64,512},{1,9,81,729},{1,10,100,1000}};

    float b[10]={13.750,13.650,13.650,13.600,13.750,13.550,13.600,13.600,13.600,13.650};

    float transpose[4][10];

    float ATA[4][4];
    float ATb[4];


    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 4; j++) {
            transpose[j][i] = A[i][j];
        }

    multATA(transpose,A,ATA,4,10,10,4);
    multATb(transpose,b,ATb,4,10,10);


    float a[4][5];
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            a[i][j]=ATA[i][j];
        }
    }

    for(int i=0;i<4;i++){
        a[i][4]=ATb[i];
    }

    float x[4];
    gaussElimination(a,x);


    int t;

    printf("Enter the Value of x : ");
    scanf("%d",&t);
    if(t<0|| t>31){
        printf("Wrong Input");
        exit(0);
    }


    printf("The stock of E.L.L is going to be : %lf ",x[0]+t*x[1]+pow(t,2)*x[2]+pow(t,3)*x[3]);



    return 0;
}
