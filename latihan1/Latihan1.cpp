#include <windows.h>
#include <string.h>
#include <stdarg.h>
#include <gl\glut.h>
#include <gl\glu.h>
#include <stdlib.h> 
void mydisplay (){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON); //Tambahan persegi panjang
	glColor3f(0.92, 0.2, 0.67); //warna objek Merah maroon
	glVertex2f(-0.4,.67); //Titik I
	glVertex2f(0.4,0.67); //Titik J
	glVertex2f(0.4,-0.7); //Titik I
	glVertex2f(-0.4,-0.7); //Titik I
	glEnd();
	
	glBegin(GL_POLYGON); //polygon dasar dari soal
	glColor3f(0,1,0); //warna hijau
	glVertex2f(-0.5,-0.5); //Titik A
	glVertex2f(-0.75,0); //Titik B
	glVertex2f(-0.5,0.5); //Titik C
	glVertex2f(0,0.75);	//Titik D
	glVertex2f(0.5,0.5); //Titik E
	glVertex2f(0.75,0); //Titik F
	glVertex2f(0.5,-0.5); //Titik G
	glVertex2f(0,-0.75); //Titik H
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.2, 0.67);
	glVertex2f(0,0.6); glColor3f(0.92, 0.2, 0.67); //Titik N , 
	glVertex2f(-0.6,0); glColor3f(0.92, 0.2, 0.67);//Titik J
	glVertex2f(0,-0.6); glColor3f(0.92, 0.2, 0.67);//Titik I
	glVertex2f(0.6,0); glColor3f(0.92, 0.2, 0.67);//Titik I
	glEnd();
	
	glFlush();}
	int main(int argc,char**argv){
		glutInit(&argc,argv);
		glutCreateWindow("Polygon_209");
		glutInitWindowSize(500,500);
		glutDisplayFunc(mydisplay);
		glutMainLoop();	}

