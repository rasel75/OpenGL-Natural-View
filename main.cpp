/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<math.h>
#endif

#include <stdlib.h>
static float	tx	= 0.0 ;
static float	ty	= 0.0 ;


float p=0;
float q=0;
float r=0;
float s=0;
float k=0;
float c=0;
void init()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-100,100,-100,100,-100,100);
}
float PI=3.1416;
void circle(float rx,float ry,float x,float y)
{
    int i=0;
    float angle=0.0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<200;i++)
    {
        angle = 2 * PI * i /100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT||GL_DEPTH_BUFFER_BIT);
   glColor3d(1,0.498,0.1411);
   glBegin(GL_QUADS); // upper half
   glVertex2d(-100,0);
   glVertex2d(-100,100);
   //glColor3d(1,0,0);
   glVertex2d(100,100);
   glColor3d(1,0,0);
   glVertex2d(100,0);
   glEnd();

    if(p<=130)  //sun down
    {
     p=p+0.027;
    }
     else{
        p=-30;
     }
    glutPostRedisplay();
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	//float x=70,y=80;
    //glTranslatef(0,y,0);
	circle(20,25,70,120-p);

   glBegin(GL_QUADS);//lower  half
     glColor3d(0,0,1);
   glVertex2d(-100,0);
   glColor3f(0,0,1);
   glVertex2d(-100,-100);
   glColor3f(0,0,1);
   glVertex2d(100,-100);
   glColor3f(1,0,0);
   glVertex2d(100,0);
   glEnd();


   if(q>=-170.0) // moving boat
    {
     q=q-0.077;
    }
     else
        q=100;
    glutPostRedisplay();
	glPushMatrix();
	glTranslatef(tx,ty,0);
   glColor3f(0,0,0);
   glBegin(GL_POLYGON); // for boat :p
   glVertex2d(q+45,0);
   glVertex2d(q+60,0);
   glVertex2d(q+65,10);
   glVertex2d(q+58,8);
   glVertex2d(q+58,20);
   glVertex2d(q+50,20);
   glVertex2d(q+50,8);
   glVertex2d(q+40,10);
   glEnd();


   if(s>=-170.0) // cloud moving
    {
     s=s-0.040;
    }
     else
        s=100;
    glutPostRedisplay();
	glPushMatrix();
	glTranslatef(tx,ty,0);

    glColor3f(.95,.647,0.2627);  // Right cloud(megh) ar jonno
    circle(30,13,s+40,70);
    circle(10,20,s+40,70);
    circle(10,20,s+45,75);
    circle(10,20,s+35,70);
    circle(10,20,s+30,70);


   if(k>=-170.0) // moving cloud
    {
     k=k-0.040;
    }
     else
        k=100;
    glutPostRedisplay();
	glPushMatrix();
	glTranslatef(tx,ty,0);

     glColor3f(.95,.647,0.2627);  // left cloud(megh) ar jonno
    circle(30,13,-50+k,70);
    circle(10,20,-50+k,70);
    circle(10,20,-55+k,75);
    circle(10,20,-45+k,70);
    circle(10,20,-40+k,70);


     if(r<=+90.0)   // dew ar code
    {
        r=r+0.17;
    }
     else
        r=-95;
    glutPostRedisplay();
	glPushMatrix();
    glColor3f(.2274,.3725,.8039);
    if(r>=65)
       glColor3f(1,.38823,.278431);
    float a=0,b=-95;
	circle(70,3,a,b=r+b);
	glColor3f(.2274,.3725,.8039);
    if(r>=75)   //second dew
       glColor3f(1,.38823,.278431);
    float e=0,f=-105;
	circle(90,3,e,f=r+f);

	if(c<=+90.0)   // dew ar code
    {
        c=c+0.17;
    }
     else
        c=-100;
    glutPostRedisplay();
	glPushMatrix();
    glColor3f(.2274,.3725,.8039);
    if(c>=70)
       glColor3f(1,.38823,.278431);
    float aa=50,bb=-105;
	circle(100,3,aa,bb=c+bb);
	glColor3f(.2274,.3725,.8039);
    if(c>=75)   //second dew
       glColor3f(1,.38823,.278431);
    float ee=30,ff=-90;
	circle(70,3,ee,ff=c+ff);


    glBegin(GL_QUADS);//lower  half soil
   glColor3f(.41,.41,.41);
   glVertex2d(-100,-35);
   glColor3f(0,1,0);
   glVertex2d(-100,-100);
   glColor3f(.41,.41,.41);
   glVertex2d(25,-100);
   glVertex2d(-100,-15);
   glEnd();
     glBegin(GL_QUADS);//tree body
   glColor3f(0.54,.27,0.07);
   glVertex2d(-30,-80);
   glVertex2d(-35,-10);
   glVertex2d(-30,-10);
   glVertex2d(-25,-80);
   glEnd();
    glBegin(GL_QUADS);//tree body
        glColor3f(0.54,.27,0.07);
   glVertex2d(-25,-80);
   glVertex2d(-15,-30);
   glVertex2d(-10,-30);
   glVertex2d(-20,-80);
   glEnd();

   glBegin(GL_TRIANGLES);//tree leaf
   glColor3f(0,0.392,0);
   glVertex2d(1,-32);
    glVertex2d(-7,5);
     glVertex2d(-25,-29);
     glEnd();

      glBegin(GL_TRIANGLES); //tree leaf
   glColor3f(0,.392,0);
   glVertex2d(3,-22);
    glVertex2d(-5,20);
     glVertex2d(-25,-19);
     glEnd();

       glBegin(GL_TRIANGLES);  //tree leaf
   glColor3f(0,0.392,0);
   glVertex2d(-18,-12);
    glVertex2d(-35,20);
     glVertex2d(-48,-15);
     glEnd();

        glBegin(GL_TRIANGLES);  //tree leaf
   glColor3f(0,0.392,0);
   glVertex2d(-18,-1);
    glVertex2d(-37,35);
     glVertex2d(-48,-4);
     glEnd();

          glBegin(GL_TRIANGLES);  //tree lower
   glColor3f(0,1.0,0);
   glVertex2d(-34,-82);
    glVertex2d(-31,-70);
     glVertex2d(-28,-82);
     glEnd();

         glBegin(GL_TRIANGLES);  //tree lower
glColor3f(0,1,0);
   glVertex2d(-30,-82);
    glVertex2d(-27,-70);
     glVertex2d(-23,-82);
     glEnd();

         glBegin(GL_TRIANGLES);  //tree lower
 glColor3f(0,1,0);
   glVertex2d(-25,-82);
    glVertex2d(-22,-70);
     glVertex2d(-19,-82);
     glEnd();

           glBegin(GL_TRIANGLES);  //tree lower
   glColor3f(0,1,0);
   glVertex2d(-21,-82);
    glVertex2d(-19,-70);
     glVertex2d(-15,-82);
     glEnd();

        glColor3f(0.50f,0.0f,0.0f); //start house
glBegin(GL_QUADS);            // chal
        glVertex3d(-50,-5,0.0);
        glVertex3d(-85,-5,0.0);
        glVertex3d(-95,-30,0.0);
        glVertex3f(-40,-30,0.0);
glEnd();

  glColor3f(0.5f,.16f,0.88f);
glBegin(GL_QUADS);              //body
        glVertex3d(-50,-30,0.0);
        glVertex3d(-85,-30,0.0);
        glVertex3d(-85,-78,0.0);
        glVertex3f(-50,-78,0.0);
glEnd();

  glColor3f(0.0f,0.0f,0.5f);
glBegin(GL_QUADS);                //lower part
        glVertex3d(-40,-78,0.0);
        glVertex3d(-95,-78,0.0);
        glVertex3d(-95,-90,0.0);
        glVertex3f(-40,-90,0.0);
glEnd();
  glColor3f(0.0f,.16f,0.0f);
glBegin(GL_QUADS);                //door
        glVertex3d(-62,-40,0.0);
        glVertex3d(-72,-40,0.0);
        glVertex3d(-72,-78,0.0);
        glVertex3f(-62,-78,0.0);
        glEnd();

glColor3f(0,0,0);                 // door divided
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(-67, -40);
    glVertex2f(-67, -78);
    glEnd();
      glColor3f(0.0f,.16f,0.0f);
glBegin(GL_QUADS);                //window
        glVertex3d(-75,-48,0.0);
        glVertex3d(-83,-48,0.0);
        glVertex3d(-83,-60,0.0);
        glVertex3f(-75,-60,0.0);

glEnd();


glColor3f(0,0,0);                 // window gril
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(-77, -48);
    glVertex2f(-77, -60);
    glEnd();

    glColor3f(0,0,0);                 //  window gril
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(-79, -48);
    glVertex2f(-79, -60);
    glEnd();

     glColor3f(0,0,0);                 //  window gril
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(-81, -48);
    glVertex2f(-81, -60);
    glEnd();



    glFlush();
}


int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1400,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Natural View Of sunset");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
