#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;
//Окружность от 0 до pi/2 красная, от пи до 3пи/2 синяя, координатные оси - зеленые

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Lines
    glBegin(GL_LINES);
    glColor3f(0,1,0);//Green
    //Ox
    glVertex2f(-1,0);
    glVertex2f(1,0);
    //Oy
    glVertex2f(0,-1);
    glVertex2f(0,1);
    glEnd();
    glFlush();

    glBegin(GL_POINTS);
    for(float i=0;i<2*M_PI;i+=0.01){
        if((i>=0)and(i<=M_PI/2)){
            glColor3f(1,0,0);//Red
            glVertex2f(cos(i),sin(i));
        }
        if((i>=M_PI) and (i<=3*M_PI/2)){
            glColor3f(0,0,1);//Blue
            glVertex2f(cos(i),sin(i));
        }
    }
    glEnd();
    glFlush();
}


int main(int argc,char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(200,200);//Window Size
    glutInitWindowPosition(0,0);//Start Position
    glutCreateWindow("Test");//Window Name
    glClearColor(0.0,0.0,0.0,1.0);//Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

