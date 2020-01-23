#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/freeglut.h>
using namespace std;
int lv, ar[7]= {0}, ar_number[3] = {0}, ar_exist[7]={0};
float ar_2[3][2]={0};
const float vertices[7][2] = {
        {-0.51,  0.0},
        {0.3, 0.43},
        {0.2,-0.1},
        {0.5, -0.1},
        {0.5, -0.3},
        {0.1, 0.6},
        {0.35, 0.6}

};

float left_down ()
{
    float x=vertices[0][0];

    int ld=0;
    for (int i=1; i<7;i++)
    {
        if (x>vertices[i][0])
        {
            x=vertices[i][0];

        }
    }

    float y=vertices[0][1];
    for (int i=1; i<7;i++)
    {
        if (x==vertices[i][0]&&y>vertices[i][1])
        {
            y=vertices[i][1];
            ld=i;
        }


    }
    ar[0]=ld;
    ar_exist[ld]++;
    cout<< ar[0]<< '\n';
}
float cos_2()
{
    float ax=ar_2[0][0]-ar_2[1][0];
    float bx=ar_2[2][0]-ar_2[1][0];
    float ay=ar_2[0][1]-ar_2[1][1];
    float by=ar_2[2][1]-ar_2[1][1];
    float cos_1=(ax*bx+ay*by)/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
    return cos_1;
}
float second_vertice()
{

    float y;
    int ver2=0;
    float cos3=1;
//    if(ar[0]==0)
//        y=vertices[1][1];
//    else y=vertices[0][1];
    ar_2[1][0]=vertices[ar[0]][0];
    ar_2[1][1]=vertices[ar[0]][1];
    ar_2[0][0]=vertices[ar[0]][0];
    ar_2[0][1]=vertices[ar[0]][1]+0.5;
    for(int j=0; j<7;j++)
    {
        ar_2[2][0]=vertices[j][0];
        ar_2[2][1]=vertices[j][1];
        if((j!=ar[0])&&(cos_2()<cos3))
        {
            ver2=j;
            cos3=cos_2();
            cout<< cos3<< '\n';
        }

    }
    ar[1]=ver2;
    ar_exist[ver2]++;
    cout<< ar[1]<< '\n';
}
float cos_vector()
{
    float ax=vertices[ar_number[0]][0]-vertices[ar_number[1]][0];
    float bx=vertices[ar_number[2]][0]-vertices[ar_number[1]][0];
    float ay=vertices[ar_number[0]][1]-vertices[ar_number[1]][1];
    float by=vertices[ar_number[2]][1]-vertices[ar_number[1]][1];
    float cos1=(ax*bx+ay*by)/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
    return cos1;
}
float next_vertices ()
{
    int j=0;
    int k=0;
    int n=0;
    int i=0;


    for( n=2;n<7;n++)
    {
        ar_number[0]=ar[n-2];
        ar_number[1]=ar[n-1];
        ar_number[2]=0;



        float cos2=1;
        for ( j=0; j<7;j++)
        {
            if(ar_exist[j]==0||j==ar[0])
            {
                ar_number[2]=j;
                cos_vector();
                if (cos_vector()<cos2)
                {
                    k=j;
                    cos2=cos_vector();
                    ar[n]=k;
                }

            }

        }
        ar_exist[k]++;

    }
    for (i=0;i<7;i++)
    {
        //    cout<< ar[i];
        cout << ar_exist[i];
    }
}

void display() {
    int m=2;
    while(ar[m]!=ar[0])
    {
        m++;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.5f);
    for (int i = 0;  i <= m; i++)

        glVertex2f(vertices[ar[i]][0],vertices[ar[i]][1]);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f,0.5f);
    for(int i=0; i<7; i++)
        glVertex2f(vertices[i][0], vertices[i][1]);
    glEnd();

    glutSwapBuffers();

}

int main( int argc, char** argv ) {  // Initialize GLUT and

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(500,500);         // Size of display area, in pixels.
    glutInitWindowPosition(100,100);     // Location of window in screen coordinates.
    glutCreateWindow("GL Convex hull"); // Parameter is window title.
    glutDisplayFunc(display);
    left_down();           // Called when the window needs to be redrawn.
    second_vertice();
    next_vertices();
    glutMainLoop(); // Run the event loop!  This function does not return.

    return 0;

}