/*
this code takes input a n*n square matrix & outputs
lower triangular matrix L &
upper triangular matrix U
*/


#include<stdio.h>
#include<math.h>

void print_matrix(double *a,int n)
{
    int  j=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++){
            printf("%0.1lf      ",*((a+(i*(n+1))) + j));
        }
        printf("\n");
    }

}

int main(void){
    freopen("in.txt","r+",stdin);
    int i,j,k,n;
     // Inputs
	 // 1. Reading matrix dimension n*n
	 printf("Enter dimension of matrix ; n : ");
	 scanf("%d", &n);


     double a[n][n], l[n][n], u[n][n];
     // 2. Reading the  Matrix
	 for(i=0; i<n; i++){
		  for(j=0; j<n; j++){
			   printf("\na[%d][%d] = ",i,j);
			   scanf("%lf", &a[i][j]);
			   printf("%0.1f ",a[i][j]);
		  }
	 }

	 // performing LU decompostion
	 for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {

            // making the upper triangle elements zero
         if (j < i)
            l[j][i] = 0;
         else {
            l[j][i] = a[j][i];
            for (k = 0; k < i; k++) {
               l[j][i] = l[j][i] - l[j][k] * u[k][i];
            }
         }
      }
      for (j = 0; j < n; j++) {

            // making lower triangle zero, though the conditions same,
            // previously it was l[j][i] , now, u[i][j]
         if (j < i)
         u[i][j] = 0;
         else if (j == i)
         u[i][j] = 1;
         else {
            u[i][j] = a[i][j] / l[i][i];
            for (k = 0; k < i; k++) {
               u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
            }
         }
      }
   }

   // printing the answer
   printf("\n\n***********************************\n");
   printf("\n\nL matrix : \n\n");
   for(i=0; i<n; i++){
		  for(j=0; j<n; j++){
			   //printf("\nl[%d][%d] = ",i,j);
			   printf("%0.1lf     ",l[i][j]);
		  }
		  printf("\n");
   }
   printf("\n\n***********************************\n");
   printf("\n\nU matrix : \n\n");
   for(i=0; i<n; i++){
		  for(j=0; j<n; j++){
			   //printf("\nl[%d][%d] = ",i,j);
			   printf("%0.1lf     ",u[i][j]);
		  }
		  printf("\n");
   }
   return 0;
}
