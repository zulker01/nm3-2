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
    //freopen("in.txt","r+",stdin);
	 double ratio;
	 int i,j,k,n;

	 // Inputs
	 // 1. Reading number of unknowns
	 printf("Enter number of unknowns: ");
	 scanf("%d", &n);

	 double a[n][n+1], x[n];

	 // 2. Reading Augmented Matrix
	 for(i=0; i<n; i++){
		  for(j=0; j<n+1; j++){
			   printf("\na[%d][%d] = ",i,j);
			   scanf("%lf", &a[i][j]);
			   printf("%0.1f ",a[i][j]);
		  }
	 }
	 printf("\n\n");
	 print_matrix((double *)a,n);
     /*

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n+1;j++)
         {
             printf("%0.1f ",a[i][j]);
         }
         printf("\n");
     }

     */
     for(i=0; i<n-1; i++){
		  if(a[i][i] == 0.0){
                printf("%0.1lf    %d",a[i][i],i);
			   printf("Mathematical Error!");
			   //exit(0);
			   return 0;
		  }
     }
     printf("\n\n");
	 print_matrix((double *)a,n);
     /*
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n+1;j++)
         {
             printf("%0.1f ",a[i][j]);
         }
         printf("\n");
     }
     */
     for(int i=0;i<n-1;i++){
     for(j=i+1; j<n; j++){
			   ratio = a[j][i]/a[i][i];
			   for(k=0; k<n+1; k++){ // k can be from 0 or from i
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			  		printf("a[%d][%d]=%.2lf ", j, k, a[j][k]);
			   }
			   printf("\n");
			   printf("\n\n");
               print_matrix((double *)a,n);

		  }
    }
    // Obtaining Solution by Back Substitution
	 x[n-1] = a[n-1][n]/a[n-1][n-1];

	 for(i=n-1;i>=0; i--){
		  x[i] = a[i][n];
		  for(j=i+1; j<n; j++){
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }

	 // output
	 // Displaying Solution
	 printf("\nSolution:\n");
	 for(i=0; i<n; i++){
	  	printf("x[%d] = %0.3lf\n",i, x[i]);
	 }

     return 0;
}


