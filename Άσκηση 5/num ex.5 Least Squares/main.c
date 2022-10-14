#include <stdio.h>
#include <stdlib.h>


void multATA(float transpose[][10],float A[][2],float ATA[][2],int r1,int c1,int r2 ,int c2){

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

void gaussElimination(float a[][3],float x[]){


	float temp,s;


	for(int j=0; j<1; j++)
		for(int i=j+1; i<2; i++){
			temp=a[i][j]/a[j][j];
			for(int k=0; k<3; k++)
				a[i][k]-=a[j][k]*temp;
		}



	for(int i=1; i>=0; i--){
		s=0;
		for(int j=i+1; j<2; j++)
            s += a[i][j]*x[j];
		x[i]=(a[i][2]-s)/a[i][i];
	}


}


int main()
{
    float A[10][2]={{1,-2.89},{1,-2.15},{1,-1.72},{1,0.50},{1,0.55},{1,0.73},{1,1.14},{1,1.56},{1,1.94},{1,2.63}};

    float b[10]={-0.050418,-0.037515,-0.030015,
                0.008726,0.009599,0.012740,
                0.019895,0.027223,0.033852,
                0.045886};


    float transpose[2][10];
    float ATA[2][2];
    float ATb[3];



    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 2; j++) {
            transpose[j][i] = A[i][j];
        }

    multATA(transpose,A,ATA,2,10,10,2);


    multATb(transpose,b,ATb,2,10,10);



    float a[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            a[i][j]=ATA[i][j];
        }
    }
    for(int i=0;i<2;i++){
        a[i][2]=ATb[i];
    }


    float x[2];
    gaussElimination(a,x);



    float t;

    printf("Enter the Value of x (-3.14,3.14) : ");
    scanf("%f",&t);


    //y=x[0]+x*x[1]
    printf("y = %f + %f * x = %.10f",x[0],x[1],x[0]+t*x[1]);




    return 0;
}
