// traffic.cpp : Defines the entry point for the console application.
//
// #include "stdafx.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
// #include<GL/glut.h>
// #include <stdio.h>
#include <string>
#include <iostream>

#define ESCAPE 27

using namespace std;

int view=0;

void text(int x, int y, string s, int font) {
	int i=0;
	glColor3f(0.0,0.5,0.8);
	glRasterPos2f(x,y);
	for(i=0;i<s.length();i++) {
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
		else if(font==3) {
			glColor3f(1.0,0.0,0.0);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
		}
	}
}

void First_win() {
	glClearColor(1.0,1.0,0.6,1.0);
	text(290,700,"TRAFFIC LIGHT SIMULATOR",1);
	text(350,660,"Using OpenGL",1);
	text(400,620,"Made By:",2);
	text(300,580,"Zeya Umayya & Zishan Ahmad",1);
	text(100,540,"INSTRUCTIONS::",2);
	text(300,100,"!!!!PRESS SPACEBAR TO ENTER INTO THE ARENA!!!!",3);
	glutPostRedisplay();
	//glutSwapBuffers();
}

void init() {
	glClearColor(0, 0, 0, 0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1000,0.0,800,50.0,-50.0);
	glutPostRedisplay();
}

void traffic_light() {
	glTranslatef(-190,20,0);
	glColor3f(0.0,0.0,0.0);
	//traffic signal controller
	glPushMatrix();
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(600,350);  //1
		glVertex2d(650,350);  //2
		glVertex2d(650,370);  //3
		glVertex2d(600,370);  //12
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	// glColor3f(0.6,0.2,0.0);
		glVertex2d(630,370);  //4
		glVertex2d(630,520);  //5
		glVertex2d(620,520);  //10
		glVertex2d(620,370);  //11
	glEnd();
	glPopMatrix();

	// Left Red Light
	glPushMatrix();
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(600,450);  //6
		glVertex2d(600,600);  //7
		glVertex2d(550,600);  //8
		glVertex2d(550,450);  //9		
	glEnd();
	glPopMatrix();

	//Right Red Light
	glPushMatrix();
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(700,450);  //11
		glVertex2d(700,600);  //12
		glVertex2d(650,600);  //13
		glVertex2d(650,450);  //14		
	glEnd();
	glPopMatrix();

	//Connecting Rod
	glPushMatrix();
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(650,520);  //15
		glVertex2d(650,540);  //16
		glVertex2d(600,540);  //17
		glVertex2d(600,520);  //18		
	glEnd();
	glPopMatrix();
}

void road_strips() {
	//first bottom green strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.8,0.0);
		glVertex2d(0,200);
		glVertex2d(0,250);
		glVertex2d(1000,250);
		glVertex2d(1000,200);
	glEnd();
	glPopMatrix();

	//second grey strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(0,250);
		glVertex2d(0,500);
		glVertex2d(1000,500);
		glVertex2d(1000,250);
	glEnd();
	glPopMatrix();

	//tilted grey strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(300,500);
		glVertex2d(200,800);
		glVertex2d(350,800);
		glVertex2d(500,500);
	glEnd();
	glPopMatrix();

	//Dotted strips
	traffic_light();
}

void main_display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(view==0) {
		init();
		First_win();
	}
	else {
		//---------CONSTANT PARTS
		//ROAD STRIP
		road_strips();
	}
	glutSwapBuffers();
}

void traffic_start() {

}

void keyboard(unsigned char key, int x, int y) {
	
	switch(key) {
		case ESCAPE:exit(1);
		
		case ' ':
			view=1;
			glClearColor(1.0, 1.0, 1.0, 0);
			traffic_start();
			break;
		
		default:
			cout<<"You pressed: "<<key;
	}
}

void reshape(int w,int h) {
	glViewport(0,0,w,h);
	cout<<"Width="<<w<<" height= "<<h<<endl;

}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1000,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Traffic Light Simulation");
	
	//glutFullScreen();
	glutDisplayFunc(main_display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glutMouseFunc();
	glutMainLoop();
	return 0;
}
