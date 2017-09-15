#include<stdio.h>
#include "boolean.h"
#include "matriks.h"


int main() {
  /* code */
  MATRIKS M1;
  MATRIKS M2;

  BacaMATRIKS(&M1,3,3);
  BacaMATRIKS(&M2,3,3);
  TulisMATRIKS(M1);printf("\n" );
  TulisMATRIKS(M2);printf("\n" );

  CopyMATRIKS(M1,&M2);
  TulisMATRIKS(M2);printf("\n" );

  TulisMATRIKS(KaliMATRIKS(M1,M2));

  printf("eaa bingung" );
  //PInverse1(&M1);
  // TulisMATRIKS(M);
  return 0;
}
