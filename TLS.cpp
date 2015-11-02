// traffic.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>

int view=0;

void text(int x,int y,char *string,int font)
{
	int i=0;
	glColor3f(0.5,0.5,0.8);
	glRasterPos2f(x,y);
	for(i=0;i<strlen(string);i++)
	{
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}
}
void First_win()
{
	glClearColor(1.0,1.0,0.6,1.0);
	text(290,700,"TRAFFIC LIGHT SIMULATOR",1);
	glutPostRedisplay();
	//glutSwapBuffers();
}
void init()
{
	glClearColor(0,0,0,0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1000,0.0,800,50.0,-50.0);
	glutPostRedisplay();
}
void main_display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(view==0)
	{
		init();
		First_win();
	}
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
