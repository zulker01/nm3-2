/*Assignment -3 : Implementation of (i) Lagrange Interpolation Polynomial and
(ii) Newton’s Interpolation Polynomial using Divided-Difference Method

Zulker Nayeen
Roll :  FH-11

3rd year 2nd Semester
Course : Numerical Methods
*/

#include <bits/stdc++.h>
#include <GL/glut.h>

#define W 1200
#define H 700
#define N 5
using namespace std;

struct Data /*point(x,y)*/
{
    float x, y;
};

//Data f[] = {{-170,168.2}, {-50,131.3}, {0, 200}, {150, 31.3}};/*4 given points*/
Data f[] = {{1,0.7651977},{1.3,0.6200860},{1.6,0.4554022},{1.9,0.2818186},{2.2,0.1103623}};
float divTable[10][10];/*divided difference table for newton's divided difference method*/

float product_term_newton_polynomial (int i,float xi,Data f[])
{
    float prob = 1;
    for (int j = 0; j < i; j++)
    {
        prob = prob * (xi - f[j].x);/*the term(x-x0)(x-x1)...(x-xi)*/
    }
    return prob;

}

// Calculation of Divided Difference Table For Newton's polynomial
void divided_Difference_Table(Data f[], float divTable[][10], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            divTable[j][i] = (divTable[j][i - 1] - divTable[j + 1][i - 1]) / (f[j].x - f[i + j].x);

        }
    }
}

/*Implementation of newton's divided difference */
float newton_divided_method(float xi, Data f[], float divTable[][10], int n)
{
    float sum = divTable[0][0];/*initialize f(x)=f(x0)*/

    for (int i = 1; i < n; i++)
    {
        sum = sum + (product_term_newton_polynomial(i, xi, f) * divTable[0][i]);/*applying the formula*/
    }
    return sum;
}

/*for debugging purpose*/
void printDiffTable(float divTable[][10],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "div"<<"[ "<<i<<"]"<<"["<<j<<"] = "<<divTable[i][j] <<endl;
        }

    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout <<divTable[i][j]<< "     " ;
        }
        cout<<endl;

    }
}
double lagrence(Data f[], double xi, int n)
{
    double yi = 0; // Initialize result

    for (int i=0; i<n; i++)
    {
        // Compute individual terms of above formula
        double L = f[i].y;
        for (int j=0; j<n; j++)
        {
            if (j!=i)
                L *= (xi - f[j].x)/double(f[i].x - f[j].x);
        }

        // Add current term to result
        yi += L;
    }
    return yi;
}



void display(void)  //callback
{
    int i;
    double X,Y;

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    /*drawing XY axis*/

    glColor3ub(128, 128, 128);
    glPointSize(1);
    glBegin(GL_LINES);
    glVertex2i(0,-H/2);
    glVertex2i(0, H/2);
    glVertex2i(-W/2,0);
    glVertex2i(W/2,0);
    glEnd();

    /*Plotting the given points*/

    glColor3ub(255, 0, 255);
    glPointSize(5);
    glBegin(GL_POINTS);
    for (i = 0; i < N; i++)
    {
        glVertex2d(f[i].x, f[i].y);
    }
    glEnd();

    /*Curve for Lagrange polynomial from x=-800 to 800*/

    glPointSize(1);
    glColor3ub(255,0,0);// red
    glBegin(GL_POINTS);
    for(X = -800.0; X < 800; X+=0.01)
    {
        Y=lagrence(f, X, N);
        glVertex2d(X,Y);
    }
    glEnd();

    /*Curve for  Newton’s Interpolation Polynomial using Divided-Difference Method from x=-800 to 800*/

    glPointSize(1);
    glColor3ub(255,255,0); // coor yellow
    glBegin(GL_POINTS);
    for(X = -800.0; X < 800.0; X+=0.01)
    {
        Y=newton_divided_method(X,f,divTable,N);
        glVertex2d(X,Y+5);//as the curves overlap so it has been shifted 5 unit along y axis
    }
    glEnd();

    glPopMatrix();
    glFlush();
}

void reshape(int w, int h)   //projection setting
{
    GLfloat aspect = (GLfloat) w / (GLfloat) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-W/2, W/2, -H/2, H/2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init()  //lighting setting
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_COLOR_MATERIAL);
}

int main(int argc, char **argv)
{
    for(int i=0;i<N;i++)
    {
        divTable[i][0]=f[i].y;
    }

    divided_Difference_Table(f,divTable,N);/*formulation of divided difference table*/
    printDiffTable(divTable,N);/*printing the table for debugging purpose*/
    glutInit(&argc, argv); //initialization
    glutInitDisplayMode(GLUT_RGB); //24 bit color
    glutInitWindowSize(W, H); //WxH window
    glutCreateWindow("Lagrange and Newton's Interpolation Polynomial"); //title
    init();//lighting
    glutReshapeFunc(reshape);//projection
    glutDisplayFunc(display);//callback
    glutMainLoop();
    return(0);
}
