/* 	Nama: Haifa Fadhila Ilma
	NIM : 13516076
	Tanggal : 14 September 2017
	Nama file : nilaikelas.c
	Deskripsi : Soal No. 2  */
/* Program yang digunakan untuk mengelola data nilai mahasiswa pada
	beberapa mata kuliah di suatu kelas dengan memanfaatkan ADT Matriks
	yang sudah dimodifikasi sesuai soal no. 1. */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

void TulisNilaiX (MATRIKS M, indeks j, ElType X){
/* Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j.
 * 	Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X.
	Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ],
	tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir
	I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi
	F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
	Jika tidak ada elemen dengan nilai = X, menuliskan [] */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 2 dan X = 3, akan tercetak: [1,3] */
	int i;
	int jumlah = CountXKol(M,j,x);

	printf("[");
	int x = 0;
	for (i=BrsMin; i<=NBrsEff(M); i++){
		if (Elmt(M,i,j)==X){
			x++;
			printf("%d",i);
			if (x!=jumlah)
				printf(",");
		}
	}
	printf("]");
}

void TulisStatistikMhs (MATRIKS M, indeks i){
/* Menuliskan statistik untuk mahasiswa dengan nomor urut i.
 Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah.
 Pada dasarnya: menuliskan statistik untuk data pada baris ke-i
 I.S. M terdefinisi, i adalah indeks baris efektif M
 F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min>
 Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 2 akan tercetak:
[2] 62.33 72 55 */
	int max,min;
	//Algoritma

	MaxMinBrs(M, i, &max, &min);
	printf("[%d] ",i);
	printf("%.2f %d %d",RataBrs(M, i),max,min);
}

void TulisStatistikMK (MATRIKS M, indeks j){
/* Menuliskan statistik untuk mata kuliah dengan nomor urut j.
 * Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi
	(berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya),
	nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya).
 * Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j
 * I.S. M terdefinisi, j adalah indeks kolom efektif M
 * F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
	[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
	Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
	100 83 83
	72 55 60
	77 93 90
	maka jika j = 2 akan tercetak:
	[2] 77.00 [93 1 [3]] [55 1 [2]] */
	int max,min, jmax, jmin,i;
	//Algoritma
	jmax = 0;
	jmin = 0;
	MaxMinKol(M,j,&max,&min);
	for (i=BrsMin; i<=NBrsEff(M); i++){
		if (Elmt(M,i,j)==max)
			jmax++;
		if (Elmt(M,i,j)==min)
			jmin++;
	}
	float rata = RataKol(M,j);
	printf("[%d] ",j);
	printf("%.2f ",rata);

	printf("[%d %d ",max,jmax);
	TulisNilaiX (M, j, max);
	printf("] ");

	printf("[%d %d ",min,jmin);
	TulisNilaiX (M, j, min);
	printf("]");
}

int main(){
	MATRIKS M;
	int mhs,matkul,i,j;
	scanf("%d",&mhs);
	scanf("%d",&matkul);
	BacaMATRIKS(&M,mhs,matkul);
	printf("STATISTIK PER MAHASISWA\n");
	for (i=1; i<=mhs; i++){
		TulisStatistikMhs(M,i);
		printf("\n");
	}
	printf("STATISTIK PER MATA KULIAH\n");
	for (j=1; j<=matkul; j++){
		TulisStatistikMK(M,j);
		printf("\n");
	}
}
