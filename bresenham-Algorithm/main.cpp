#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

//indetifier fungsi
void init();
void display(void);
void bresenham(void);

//posisi window dilayar
int window_x;
int window_y;

//ukuran window
int window_width = 520;
int window_height = 480;

//judul window
char *judul_window = "Algoritma Bresenham";

int main (int argc, char** argv) //int = void
{
	//inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	//set posisi window supaya berada ditengah
	int window_x = (glutGet(GLUT_SCREEN_WIDTH)-window_width)/2;
    int window_y = (glutGet(GLUT_SCREEN_HEIGHT)-window_height)/2;
    glutInitWindowSize(window_width, window_height); //set ukuran window
    glutInitWindowPosition(window_x, window_y); //set posisi window
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); //set display RGBA dan double buffer
    glutCreateWindow(judul_window); //set judul window
    
    init();//jalankan fungsi init
    glutDisplayFunc(display); //set fungsi display
    glutMainLoop(); //set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.58, 0.15, 0.13,0); //set warna background
	glColor3f(1, 1, 0.71); //set warna garis
	glPointSize(10.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matrix yang digunakan
	glLoadIdentity(); //load matriks identitas
	gluOrtho2D(120.0,160.0,90.0,130.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//clear color
	bresenham(); //jalankan fungsi beresenham
	glutSwapBuffers(); //swap buffer
}

void bresenham(){
	int x1, y1, x2, y2, x, y, dx, dy, xend, p, duady, duadydx;
	//tentukan titik awal dan akhir
	x1 = 125;
	y1 = 100;
	x2 = 155;
	y2 = 124;
	x = x1;
	y = y1;
	
	//hitung dx dan dy
	dx = abs(x2 - x1);
	dy = abs(y2-y1);
	
	//hitung p
	p = 2 * dy - dx;
	duady = 2 * dy;
	duadydx = 2 * (dy - dx);
	
	//tentukan titik awal dan akhir
	if (x1 > x2){
		x = x2;
		y = y2;
		xend = x1;
	}
	else
	{
		x = x1;
		y = y1;
		xend = x2;
	}
	
	//gambar titik awal
	glBegin(GL_LINES);
	glVertex2i(x,y);
	
	//perulangan untuk menggambar titik-titik
	while (x < xend) {
		x++;
		if (p < 0) {
			p += duady;
		}
		else
		{
			if (y1 > y2){
				y--;
			}
			else y++;
			p += duadydx;
		}
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
}
