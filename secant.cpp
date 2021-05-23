#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define    f(x)    x*x*x - 2*x - 5

using namespace std;

int main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1, N;

	 /* Setting precision and writing floating point values in fixed-point notation. */
   cout<< setprecision(6)<< fixed;

	 /* Inputs */
	 cout<<"Enter first guess: ";
	 cin>>x0;
	 cout<<"Enter second guess: ";
	 cin>>x1;
	 cout<<"Enter tolerable error: ";
	 cin>>e;
	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 /* Implementing Secant Method */
     cout<< endl<<"**************"<< endl;
	 cout<<"Secant Method"<< endl;
	 cout<<"**************"<< endl;
	 do
	 {
		  f0 = f(x0);
		  f1 = f(x1);
		  if(f0 == f1)
		  {
			   cout<<"Mathematical Error.";
			   exit(0);
		  }

		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = f(x2);

		  cout<<"Iteration-"<< step<<":\t x2 = "<< setw(10)<< x2<<" and f(x2) = "<< setw(10)<< f(x2)<< endl;

		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;

		  step = step + 1;

		  if(step > N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }
	 }while(fabs(f2)>e);

	 cout<< endl<<"Root is: "<< x2;

	 return 0;
}
