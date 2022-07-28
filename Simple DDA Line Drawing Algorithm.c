#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1,y1,x2,y2,m,i,j;
float dx,dy;
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glEnd();

glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glBegin(GL_POINTS);

if(m>0 && m<=1)
{
while(x1<=x2 && y1<=y2)
{
    x1=x1+1;
    y1=y1+m;
    glVertex3f(x1/100,y1/100,0.0);
   printf("%f %f \n",x1,y1);

}
}
else if(m>1)
{
    while(x1<=x2 && y1<=y2)
{
    x1=x1+(1/m);
    y1=y1+1;
   glVertex3f(x1/100,y1/100,0.0);
   printf("%f %f",x1,y1);
}
}

else if(m>-1 && m<=0)
{
    while(x1>=x2 && y1>=y2)
{
    x1=x1-1;
    y1=y1-m;
   glVertex3f(x1/100,y1/100,0.0);
   printf("%f %f",x1,y1);
}
}
else if(m<-1)

  {

    while(x1>=x2 && y1>=y2)
{
    x1=x1-(1/m);
    y1=y1-1;
    glVertex3f(x1/100,y1/100,0.0);
    printf("%f %f",x1,y1);
}
  }

glEnd();
glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{

    printf("Simple DDA Line Drawing Algorithm\n\n");
    printf("Enter value of X1: & Y1: ");
    scanf("%f %f",&x1,&y1);

    printf("Enter value of X2: & Y2: ");
    scanf("%f %f",&x2,&y2);

    dx=x2-x1;
    dy=y2-y1;
    m=dy/dx;


glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Simple DDA Line Drawing Algorithm");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
