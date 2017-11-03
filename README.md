# Aplikasi Garis Dengan Algoritma DDA
Pembuatan aplikasi Garis menggunakan Algoritma DDA dengan menggunakan libray openGL dan Glut untuk membentuk sebuah garis.

## Deskripsi
Algoritma DDA adalah algoritma pembentukan garis menggunakan perhitungan Dx dan Dy. Garis dibuat berdasarkan 2 Titik, yaitu titik awal (x,y) dan titik akhir (x,y). Algoritma ini akan membentuk pixel dari perpindahan tiap titik (x,y) dimulai dari titik awal sampai titik akhir sehingga terbentuklah sebuah garis.

## Getting Started
Menentukan Titik
```
//tentukan titik awal dan akhir
x2 = 0;
y2 = 300;
x1 = 500;
y1 = 0;
x= x1;
y= y1;
```
## Masalah Yang Ditemukan
1. Tidak dapat membuat garis vertikal dan horizontal
2. Titik awal harus lebih kecil dari titik akhir

## Penyelesaian Masalah
1. Perbaikan Looping
```
int iterasi = 0;
//perulangan untuk menggambar titik-titik 
while (iterasi != steps)
{
	x += x_inc;
	y += y_inc;

	iterasi++;
	glVertex2i(x, y); // gambar 
}
```
2. Perbaikan Steps
```
  //hitung steps
if (abs(dx) > abs(dy)) {
	steps = abs(dx);	
}
else steps = abs(dy);
```
## Built With
* Microsoft Visual Studio Community 2015

## Contributors
* [Galang Rambu Anarki](https://dinus.ac.id/mahasiswa/A11.2015.08929)
* [Muhammad Wahyu Kuncoro](https://dinus.ac.id/mahasiswa/A11.2015.08930)
* [Rizki Ramadhan Fratama](https://dinus.ac.id/mahasiswa/A11.2015.08913)

## License
The GNU General Public License v3.0
