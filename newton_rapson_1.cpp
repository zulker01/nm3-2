
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
    float x0, x1, x, f0, f1, f, e;
    cout<<1/3<<" "<<3/2<<" "<<4/5<<endl;
	 int step = 1;
	 cout << "Enter  guess: ";
     cin >> x0;
     cout << "f(" << x0 << ") = " << f(x0) << "\n";
     cout << "finv(" << x0 << ") = " << finv(x0) << "\n";
     cout << "Enter tolerable error: ";
     cin >> e;

     cout << "newton rapson Method" << endl << endl;

     do
    {
        x = x0 - (f(x0)/finv(x0));
        //x = x0+2/3;
        f = f(x);
        cout << "Iteration - " << step << " : x = " << setw(10) << 2/3 << " and f(x) = " << setw(10) << f(x) <<  endl;
        x0 = x;
        step = step + 1;
    }
    while(fabs(f) > e);
    cout<<"steps "<<step<<endl;
    cout << endl << "Root is : "<<  x << endl;
    return 0;
}
