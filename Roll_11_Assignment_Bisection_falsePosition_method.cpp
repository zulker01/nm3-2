/*
    **** Assignment 1 : Determine root with false position method & Bisection method  ***
    **** Name : Zulker Nayeen , Roll : FH_11   , 3rd year 2nd semester                ***
    **** Course : Numerical Methods ***
*/

#include<bits/stdc++.h>
using namespace std;
//#define f(x) 3*x-sin(x) + exp(x)
//#define f(x) -x*x + 2*exp(x)
#define f(x) cos(x) - x * exp(x)

/*
    input : first guess : -1
    second guess :2
    error : 0.0001
*/
using namespace std;

int main()
{
    //freopen("out.txt","w+",stdout);

    double x0, x1, x, f0, f1, f, e, oldx, conv, guess_step;
    int step = 1;
    vector<double> cBi,errBi,cFP,errFP;
    cout << setprecision(6) << fixed;
    cout<<1/3<<" "<<1/2<<" "<<4/5<<endl;

    // if the root does not converge within the guess
    // then repeat
repeat:
    cout << "Enter first guess: ";
    cin >> x0;
    cout << "f(" << x0 << ") = " << f(x0) << "\n";
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "f(" << x1 << ") = " << f(x1) << "\n";
    cout << "Enter tolerable error: ";
    cin >> e;

    int x0main = x0;
    int x1main = x1;
    guess_step = (log(x1-x0) - log(e))/log(2);
    cout << "Assumed Step Size = " << guess_step << "\n\n";


    f0 = f(x0);
    f1 = f(x1);
    oldx = x1;

    if(f0 * f1 > 0.0)
    {
        cout << "Incorrect Initial Guesses." << endl;
        goto repeat;
    }

    cout << "Bisection Method" << endl << endl;

    // formula : x2= (x1+x2)/2
    do
    {
        x = (x0 + x1)/2;
        f = f(x);
        cBi.push_back(x);
        errBi.push_back(((fabs((x-oldx)/x)))*100);

        oldx=x;
        // output each iterations
        cout << "Iteration - " << step << " : x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) <<  endl;
        if( f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }

        step = step + 1;
    }
    while(fabs(f) > e);
    cout<<"steps "<<step<<endl;
    cout << endl << "Root is : "<<  x << endl;

    cout<<"\n\n  False Position Method \n";

    x0=x0main;
    x1=x1main;
    f0 = f(x0);
    f1 = f(x1);
    oldx = x1;


    int stepFP =1;

    // false position formula :
    // x = x1 - ((f1*(x1-x0))/(f1-f0));
    do
    {
        x = x1 - ((f1*(x1-x0))/(f1-f0));
        f = f(x);
        cFP.push_back(x);
        errFP.push_back(((fabs((x-oldx)/x)))*100);


        oldx=x;
        cout << "Iteration - " << stepFP << " : x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;
        if( f0 * f < 0)
        {
            x1 = x; // x0 & x has different sign
        }
        else
        {
            x0 = x; //x0 & x has same sign
        }

        stepFP++;
    }
    while(fabs(f) > e);

    cout << endl << "Root is : "<<  x << endl;
    cout<<"\n\n";
    int Bisize= cBi.size();
    int FPsize = cFP.size();
    cout<<Bisize<<" "<<FPsize<<endl;
    cout<<"Iteration   c bisection    f(c) bisection   error %       c False position     f(c) false position     error % "<<endl;
    if(Bisize>=FPsize)
    {
        for(int i=0; i<cBi.size(); i++)
        {

            if(cFP.size()<=i)
            {
                cout<<"   "<<i+1<<"        "<<cBi[i]<<"          "<<f(cBi[i])<<"      "<<errBi[i]<<"       "<<cFP[cFP.size()-1]<<"           "<<f(cFP[cFP.size()-1])<<"              "<<errFP[cFP.size()-1]<<endl;

            }
            else
            {
                cout<<"   "<<i+1<<"        "<<cBi[i]<<"          "<<f(cBi[i])<<"      "<<errBi[i]<<"       "<<cFP[i]<<"           "<<f(cFP[i])<<"              "<<errFP[i]<<endl;
            }

            // cout<<i+1<<"    "<<cFP[i]<<"             "<<f(cFP[i])<<"          "<<errFP[i]<<endl;
        }
    }
    else
    {


        for(int i=0; i<FPsize; i++)
        {

            if(Bisize<=i)
            {
                cout<<"   "<<i+1<<"        "<<cBi[Bisize-1]<<"          "<<f(cBi[Bisize-1])<<"      "<<errBi[Bisize-1]<<"       "<<cFP[i]<<"           "<<f(cFP[i])<<"              "<<errFP[i]<<endl;

            }
            else
            {
                cout<<"   "<<i+1<<"        "<<cBi[i]<<"          "<<f(cBi[i])<<"      "<<errBi[i]<<"       "<<cFP[i]<<"           "<<f(cFP[i])<<"              "<<errFP[i]<<endl;
            }

            // cout<<i+1<<"    "<<cFP[i]<<"             "<<f(cFP[i])<<"          "<<errFP[i]<<endl;
        }

    }
    return 0;
}
