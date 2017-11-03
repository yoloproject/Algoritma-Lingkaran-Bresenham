// Lingkaran Dengan Algoritma Perbaikan Bresenham
// Team		: Yolo
// Tanggal  : 2 November 2017
// Di Ubah  : 2 November 2017

// Pustaka
#include <GL\freeglut.h> 
#include <GL\glut.h> // Pustaka window  
#include <iostream> // Header / Pustaka C++ input dan output

using namespace std;

//identifier fungsi
void init(); // Fungsi inisialisasi
void display(void); // Fungsi Display
void lingkaranOpenGl(void);

//  posisi window di layar
int win_x; // Posisi Layar X
int win_y; // Posisi Layar Y

//  ukuran window
int win_width = 400; // Tinggi Window
int win_height = 400; // Lebar Window

//  judul window
char *judul_win = "Aplikasi Algoritma Pembuat Lingkaran";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	win_x = (glutGet(GLUT_SCREEN_WIDTH) - win_width) / 2;
	win_y = (glutGet(GLUT_SCREEN_HEIGHT) - win_height) / 2;
	glutInitWindowSize(win_width, win_height); //set ukuran window 
	glutInitWindowPosition(win_x, win_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_win);


	init();

	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set background 
	glColor3f(1.0, 0.0, 0.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks  
	glLoadIdentity(); // set matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	lingkaranOpenGl(); //panggil fungsi ddaOpenGl
	glutSwapBuffers(); //swap buffer 
}

void lingkaranOpenGl(void) {
	//tentukan titik pusat dan jari-jari
	int xc, yc, r;
	r = 20;
	xc = 100;
	yc = 100;

	//hitung p awal dan set nilai awal untuk x dan y
	int p = 1 - r;
	int x = 0;
	int y = r;
	glBegin(GL_POINTS);
	
	//perulangan untuk menggambar titik
	for(int i = x; i <= y; i++)
	{
		x++; //tambah nilai x
		if (p < 0) {
			p += +2 * x + 1; //hitung p selanjutnya jika p < 0 
		}
		else {
			y--; //kurangi nilai y
			p += 2 * (x - y) + 1; //hitung p selanjutnya jika p > 0 atau p = 0
		}

		// translasi terhadap titik pusat
		glVertex2i(xc + x, yc + y); 
		glVertex2i(xc + y, yc + x); 
		glVertex2i(xc + y, yc - x); 
		glVertex2i(xc + x, yc - y); 
		glVertex2i(xc - x, yc - y); 
		glVertex2i(xc - y, yc - x);  
		glVertex2i(xc - y, yc + x); 
		glVertex2i(xc - x, yc + y); 

	}

	glEnd();
	glFlush();
}