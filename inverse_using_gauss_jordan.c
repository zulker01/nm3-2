/*
this code takes input a n*n square matrix & outputs
inverse matrix

it uses augmented matrix by combining identity matrix I, & solve the matrix using gauss elimination
*/

/*
       ****** Warning ******
       this matrix operation starts from 1 , not zero
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
    float a[n][n+n], x[n], ratio;

    for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   printf("\na[%d][%d] = ",i,j);
				   scanf("%f", &a[i][j]);
				   printf("%0.1f ",a[i][j]);
			  }
		 }
		 /* Augmenting Identity Matrix of Order n */
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }
		 /* Applying Gauss Jordan Elimination */
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("Mathematical Error!");
				   //exit(0);
				   return 0;
			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Row Operation to Make Principal Diagonal to 1 */
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
		 /* Displaying Inverse Matrix */
		 printf("\nInverse Matrix is:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	printf("%0.3f\t",a[i][j]);
			  }
			  printf("\n");
		 }
		 getch();
		 return(0);
}
