// Algoritma pembuat lingkaran

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void lingkaran(int jari, int hor, int ver);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Pembuat Lingkaran";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window);

	init(); // jalankan fungsi init
	glutDisplayFunc(display); // set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(1.0, 1.0, 1.0); //set warna titik
	glPointSize(3.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	lingkaran(40, 250, 300); //jalankan fungsi lingkaran
	lingkaran(20, 250,300);
	lingkaran(10, 250, 300);

	lingkaran(40, 350, 300);
	lingkaran(20, 350, 300);
	lingkaran(10, 350, 300);

	lingkaran(100, 300, 300);
	glutSwapBuffers(); //swap buffer 
}

void lingkaran(int jari, int hor, int ver) {
	//tentukan titik pusat dan jari-jari
	int xc,yc,r;
	r = jari;
	xc = hor;
	yc = ver;

	//hitung p awal dan set nilai awal untuk x dan y
	int p = 1-r;
	int x = 0;
	int y = r;

	glBegin(GL_POINTS);

	//perulangan untuk menggambar titik
	while (x <= y) {
		x++; //tambah nilai x
		if (p < 0) { 
			p += 2 * x + 1; //hitung p selanjutnya jika p < 0 
		}
		else {
			y--; //kurangi nilai y
			p += 2 * (x - y) + 1; //hitung p selanjutnya jika p > 0 atau p = 0
		}

		// translasi terhadap titik pusat dan cerminkan
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc - y, yc - x);
	}

	glEnd();
	glFlush();
}

