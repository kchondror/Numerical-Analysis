#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Cholesky(float A[][3])
{
    float L[3][3]={{0,0,0},{0,0,0},{0,0,0}};

    for (int i = 0;i<3;i++)
        for (int j=0;j<=i;j++) {
            int sum = 0;

            if (i==j){
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(A[j][j] -sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (L[i][k] * L[j][k]);
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }


    for (int i=0;i<3;i++) {
      for (int j = 0; j < 3; j++)
        printf("%.2f ",L[i][j]);
      printf("\n");
    }
}

int main()
{
    float A[3][3] ={{4,-2,2},{-2,2,-4},{2,-4,11}};
    Cholesky(A);
    return 0;
}
