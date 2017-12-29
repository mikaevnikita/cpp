#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

void DrawCircle(float x_center,float y_center, float radius, float red, float green, float blue){
	glBegin(GL_POINTS);
	glColor3f(red,green,blue);
	for(float i=0;i<2*M_PI;i+=0.001){
		glVertex2f(radius*cos(i)+x_center,radius*sin(i)+y_center);
	}
	glEnd();
}

void display(){
	glClear (GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f (1.0, 1.0, 1.0);
	glVertex2f (0.25, 0.25);
	glVertex2f (0.75, 0.25);
	glVertex2f (0.75, 0.75);
	glVertex2f (0.25, 0.75);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(10);
	glColor3f(0,0,0);
	glVertex2f(0.25,0.25);
	glVertex2f(0.75,0.75);

	glVertex2f(0.75,0.25);
	glVertex2f(0.25,0.75);
	glEnd();

	//Circle start pos X:0.75 Y=0.5
	DrawCircle(0.5,0.5,0.25,1,0,0);
	DrawCircle(0.5,0.5,sqrt(0.125),0,1,0);
	glFlush();
}

int main(int argc, char ** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Test");
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

