#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>
/*
#define f(x) cos(x) - x * exp(x)
#define finv(x) -sin(x) - x * exp(x) - exp(x)
*/
//#define f(x) -x*x + 2*exp(x)
#define f(x) x*x - 3*x +2
#define finv(x) 2*x-3
using namespace std;

int main(){
	 float x0, x1, x, f0, f1, f, e, oldx, conv, guess_step, X=-7.668557;
	 int step = 1;

     cout << setprecision(6) << fixed;

	 repeat:
	 cout << "Enter  guess: ";
     cin >> x0;
     cout << "f(" << x0 << ") = " << f(x0) << "\n";
     cout << "finv(" << x0 << ") = " << finv(x0) << "\n";
     cout << "Enter tolerable error: ";
     cin >> e;
     /*
     cout << "Enter second guess: ";
     cin >> x1;
     cout << "f(" << x1 << ") = " << f(x1) << "\n";


     guess_step = (log(x1-x0) - log(e))/log(2);
     cout << "Assumed Step Size = " << guess_step << "\n\n";

	 f0 = f(x0);
	 f1 = f(x1);
     oldx = x1;

	 if(f0 * f1 > 0.0){
		  cout << "Incorrect Initial Guesses." << endl;
		  goto repeat;
	 }
    */
	 cout << "newton rapson Method" << endl << endl;
    do
    {
        //x = x0 - (f(x0)/finv(x0));
        x = x0+2/3;
        f = f(x);

        oldx=x;

        cout << "Iteration - " << step << " : x = " << setw(10) << 2/3 << " and f(x) = " << setw(10) << f(x) <<  endl;
        /*
        if( f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        */
        x0 = x;
        step = step + 1;
    }
    while(fabs(f) > e);
    cout<<"steps "<<step<<endl;
    cout << endl << "Root is : "<<  x << endl;
}

