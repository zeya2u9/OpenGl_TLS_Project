// traffic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<GL/glut.h>
#include<stdio.h>
#include<string.h>

int view=0;
void arrow()
{
	glColor3f(0.8,0.7,0.5);
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(0.0,0.0);
		glVertex2f(1.0,1.0);
	glEnd();
	glPopMatrix();
}
void First_win()
{
	glClearColor(0.0,0.0,0.0,0.0);
}
void main_display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(view==0)
		First_win();
	//glutWireSphere(1.0,15,20);
	//arrow();
	glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
	if(key==27) exit(0); ///escape
	else printf("You pressed %c",key);
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	printf("Width=%d height=%d \n",w,h);

}
int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1000,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("My_carr");
	
	//glutFullScreen();
	glutDisplayFunc(main_display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glutMouseFunc();
	glutMainLoop();
	return 0;
}
