/* 	Nama: Haifa Fadhila Ilma
	NIM : 13516076
	Tanggal : 14 September 2017 */

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	return (i>=BrsMin)&&(i<=BrsMax)&&(j>=KolMin)&&(j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return IsIdxValid(i,j)&&(i<=NBrsEff(M))&&(j<=NKolEff(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	int i,j;
	NBrsEff(*MHsl)=NBrsEff(MIn);
	NKolEff(*MHsl)=NKolEff(MIn);
	for (i=BrsMin; i<=NBrsEff(*MHsl); i++){
		for (j=KolMin; j<=NKolEff(*MHsl); j++){
			Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
	int i,j;
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
	MakeMATRIKS(NB,NK,M);
	for (i=BrsMin; i<=NBrsEff(*M); i++){
		for (j=KolMin; j<=NKolEff(*M); j++){
			scanf("%d",&Elmt(*M,i,j));
		}
	}
}

void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
	int i,j;
	for (i=BrsMin; i<=NBrsEff(M); i++){
		for (j=KolMin; j<=NKolEff(M); j++){
			printf("%d",Elmt(M,i,j));
			if (j!=NKolEff(M))
				printf(" ");
		}
		if (i!=NBrsEff(M))
			printf("\n");
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
	int i,j;
	
	for (i=BrsMin; i<=NBrsEff(M1); i++){
		for (j=KolMin; j<=NKolEff(M1); j++){
			Elmt(M1,i,j)+=Elmt(M2,i,j);
		}
	}
	return M1;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
	int i,j;
	
	for (i=BrsMin; i<=NBrsEff(M1); i++){
		for (j=KolMin; j<=NKolEff(M1); j++){
			Elmt(M1,i,j)-=Elmt(M2,i,j);
		}
	}
	return M1;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
	int i,j,k;
	MATRIKS Mnew;
	
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&Mnew);
	
	for (i=BrsMin; i<=NBrsEff(M1); i++){
		for (j=KolMin; j<=NKolEff(M2); j++){
			Elmt(Mnew,i,j) = 0;
			for (k=1; k<=NKolEff(M1); k++){
				Elmt(Mnew,i,j)+=(Elmt(M1,i,k)*Elmt(M2,k,j));
			}
		}
	}
	return Mnew;
}

/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
	int i,j;
	
	for (i=BrsMin; i<=NBrsEff(M); i++){
		for (j=KolMin; j<=NKolEff(M); j++){
			Elmt(M,i,j)*=X;
		}
	}
	return M;
}

void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
	int i,j;
	for (i=BrsMin; i<=NBrsEff(*M); i++){
		for (j=KolMin; j<=NKolEff(*M); j++){
			Elmt(*M,i,j)*=K;
		}
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
	boolean iseq = true;
	int i,j;
	if ((NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2))){
		i=BrsMin; 
		while (i<=NBrsEff(M1)&&iseq){
			j=KolMin;
			while (j<=NKolEff(M1)&&iseq){
				if (Elmt(M1,i,j)!=Elmt(M2,i,j))
					iseq = false;
				else j++;
			}
			i++;
		}
	}
	else iseq = false;
	return iseq;
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	return (NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
	return NBrsEff(M)*NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	return NBrsEff(M)==NKolEff(M);
}

boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
	int i,j;
	boolean issim = true;
	if (IsBujurSangkar(M)){
		i=BrsMin; 
		while (i<=NBrsEff(M)&&issim){
			j=KolMin;
			while (j<=NKolEff(M)&&issim){
				if (Elmt(M,i,j)!=Elmt(M,j,i))
					issim = false;
				else j++;
			}
			i++;
		}
	}
	else issim = false;
	return issim;
}

boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   	int i,j;
	boolean issat = true;
	if (IsBujurSangkar(M)){
		i=BrsMin; 
		while (i<=NBrsEff(M)&&issat){
			j=KolMin;
			while (j<=NKolEff(M)&&issat){
				if (i==j){
					if (Elmt(M,i,j)!=1)
						issat = false;
				}
				else{
					if (Elmt(M,i,j)!=0)
						issat = false;
				}
				j++;
			}
			i++;
		}
	}
	else issat = false;
	return issat;
}

boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
   	int i,j;
	float count = 0;
	for (i=BrsMin; i<=NBrsEff(M); i++){
		for (j=KolMin; j<=NKolEff(M); j++){
			if (Elmt(M,i,j)!=0)
				count++;
		}
	}
	return (count/NBElmt(M)*100)<=5;
}

MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	return KaliKons(M,-1);
}

float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */

	 MATRIKS temp;
	 float hasil = 0;
	 float dt;

	 int c,i,nB,nK;

	 if ( (NBrsEff(M)== 1) && (NKolEff(M)==1) ){
	  hasil+=Elmt(M,1,1);
	 }
	 else if ((NBrsEff(M)==2) && (NKolEff(M)==2)){
	  hasil+=Elmt(M,1,1)*Elmt(M,2,2) - Elmt(M,1,2) * Elmt(M,2,1);
	 }
	 else{
	  i = GetFirstIdxBrs(M);
	  MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&temp);

	  for (int j = GetFirstIdxKol(M); j<= GetLastIdxKol(M); j++) {
	   c = (i+j)%2 == 0 ? 1 : -1;

	   nB = 1; nK=1;
	   for (int a = GetFirstIdxBrs(M); a <= GetLastIdxBrs(M); a++) {
		nK=1;
		for (int b = GetFirstIdxKol(M);b<= GetLastIdxKol(M);b++)
		 if ((a!=i) && (b!=j)){
		  Elmt(temp,nB,nK) = Elmt(M,a,b);
		  nK++;
		 }
		if (a!=i) nB++;
	   }
	   dt = Determinan(temp);
	   hasil+=dt*c*Elmt(M,i,j);
	  }
	 }
	 return hasil;
}

void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	*M=Inverse1(*M);
}

void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	MATRIKS Mnew;
	MakeMATRIKS(BrsMax,KolMax,&Mnew);
	NBrsEff(Mnew)=NBrsEff(*M);
	NKolEff(Mnew)=NKolEff(*M);
	int i,j;
	for (i=BrsMin; i<=NBrsEff(*M); i++){
		for (j=KolMin; j<=NKolEff(*M); j++){
			Elmt(Mnew,j,i)=Elmt(*M,i,j);
		}
	}
	for (i=BrsMin; i<=NBrsEff(*M); i++){
		for (j=KolMin; j<=NKolEff(*M); j++){
			Elmt(*M,i,j)=Elmt(Mnew,i,j);
		}
	}
}
/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
	float sum = 0;
	int j;
	for (j=KolMin; j<=NKolEff(M); j++){
		sum+=Elmt(M,i,j);
	}
	
	return (sum/NKolEff(M));
}

float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
	float sum = 0;
	int i;
	for (i=BrsMin; i<=NBrsEff(M); i++){
		sum+=Elmt(M,i,j);
	}

	return (sum/NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
	*max = Elmt(M,i,1);
	*min = Elmt(M,i,1);
	int j;
	for (j=KolMin; j<=NKolEff(M); j++){
		if (Elmt(M,i,j)>=*max)
			*max = Elmt(M,i,j);
		if (Elmt(M,i,j)<=*min)
			*min = Elmt(M,i,j);
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    *max = Elmt(M,1,j);
	*min = Elmt(M,1,j);
	int i;
	for (i=BrsMin; i<=NBrsEff(M); i++){
		if (Elmt(M,i,j)>=*max)
			*max = Elmt(M,i,j);
		if (Elmt(M,i,j)<=*min)
			*min = Elmt(M,i,j);
	}
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
	int count = 0;
	int j;
	for (j=KolMin; j<=NKolEff(M); j++){
		if (Elmt(M,i,j)==X)
			count++;
	}
	return count;
}
int CountXKol (MATRIKS M, indeks j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
	int count = 0;
	int i;
	for (i=BrsMin; i<=NBrsEff(M); i++){
		if (Elmt(M,i,j)==X)
			count++;
	}
	return count;
}

#endif
