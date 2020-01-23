#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/freeglut.h>
double a,b,fa,fb,a1,eps, ar[1000]={0}, ar_pairs[10][2]={0},ar_der[10]={0}, roots[10]={0};int k;
using namespace std;
double function_1( double n)
{
    double f1=4*pow(n, 4)+3*pow(n,3)-6*pow(n,2)+0.5;
    //double f1=cos(1/n);
    return f1;
}
double function_der(double(*fun)(double),double n)
{
    double der=(fun(n+eps)-fun(n))/eps;
    //cout<< der<< '\n';
    return der;
}

int roots_finder(double(*fun)(double))
{
    eps=0.000001;
    double max_der=100;
    k=0;
    cin >>a;
    cin >>b;
    ar[0]=fun(a);
//    for(double i=a;i<=b;i+=eps){
//        if(abs(function_1(i))>abs(fa))
//            fa=function_1(i);
//    }
    // cout<< fa;
    double a1=a;
    double step=abs((a-b)/max_der);

    for(int n=1;n<=max_der;n++){
        a1+=step;
        ar[n]=function_1(a1);
        if((ar[n-1]*ar[n])<=0){
            ar_pairs[k][0]=a1-step;
            ar_pairs[k][1]=a1;
            k++;
            //cout<<k<<'\n';
        }
        if(a1>=b)
            break;
        // cout<< "x="<<  a1<< '\n';
        //cout<< "f=" <<ar[n]<<'\n';

    }
    int j=0;
    double x1=0;
    for(int j=0;j<k;j++){
        x1=ar_pairs[j][0];
        //cout<<ar_pairs[j][0]<<'\n';
        while(abs(fun(x1))>eps){
            x1=x1-(fun(x1)/function_der(fun,x1));
        }
        roots[j]=x1;
    }
    for(int i=0;i<k;i++){
        cout<<i+1<< " root: "<< roots[i]<<'\n';
    }
}
void display() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-1,0);
    glVertex2d(1,0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2d(0,1);
    glVertex2d(0,-1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f,0.0f,1.0f);
    glVertex2d(a/10,1);
    glVertex2d(a/10,-1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f,0.0f,1.0f);
    glVertex2d(b/10,1);
    glVertex2d(b/10,-1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.5f);
    for (double i = -10;  i <= 10; i+=eps){
        glVertex2d(i/10,function_1(i)/10);
    }
    glEnd();
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.5f);
    for(int i=0; i<k; i++)
        glVertex2f(roots[i]/10,0);
    glEnd();

    glutSwapBuffers();

}
int main( int argc, char** argv ) {  // Initialize GLUT and
    roots_finder(function_1);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(500,500);         // Size of display area, in pixels.
    glutInitWindowPosition(100,100);     // Location of window in screen coordinates.
    glutCreateWindow("Null of function"); // Parameter is window title.
    glutDisplayFunc(display);

//    glutReshapeFunc(reshape);
//    init();
//    glutIdleFunc(run);
    glutMainLoop(); // Run the event loop!  This function does not return.

    return 0;
}
