// //@file matrixmultiply
//  @description Depad pad ekleyip koselere sifılrlayıp carpma ve düz carpma iki matrisi bunu sonuc matrisine ekleme
// * @assignment 1
// * @date  10 18.12
// * @author merve çelik merve-celik@stu.fsm.edu.tr
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixoperations.h"


int main(int argc, char const *argv[])
{
  int i;
    if(argc!=5){
      printf("Hata 5 den fazla girilmez");
      return 0 ;
    }
    if (argc==1)
    {
      printf("Program adı dışında girmeniz gerken argumanlar matris1 boytu,matirs2 boyutu,int islem tipi ve seed degeridir.");
      return 0 ;
    }
    
 
  
  int matris1col=atoi(argv[1]);
 
  int matris2col=atoi(argv[2]);

  int secimtpi=atoi(argv[3]);
  int srand =atoi(argv[4]);
   
  // printf("Matris1  satir boyutu giriniz");
  // scanf("%d", &matris1row);
  // printf("Matris1  sutun boyutu giriniz");
  // scanf("%d", &matris1col);
  // printf("Matris2  satir boyutu giriniz");
  // scanf("%d", &matris2row);
  // printf("Matris2  sutun boyutu giriniz");
  // scanf("%d", &matris2col);
  // printf("Secim tipi giriniz boyutu giriniz");
  // scanf("%d", &secimtpi);
  control(matris1col,  matris2col, secimtpi);
  int **matris1;

  matris1 = ikiBoyutDiziOlustur(matris1col, matris1col);
  ikiBoyutdiziDoldur(matris1, matris1col, matris1col,srand);
  ikiBoyutdiziYazdir(matris1, matris1col, matris1col);
  printf("\n");
  int **matris2;
  matris2 = ikiBoyutDiziOlustur(matris2col, matris2col);
  ikiBoyutdiziDoldur(matris2, matris2col, matris2col,srand);
  ikiBoyutdiziYazdir(matris2, matris2col, matris2col);
  printf("\n");
  
  matrisislem(matris1,matris2,matris1col,matris2col);
  operasyon1(matris1,matris2,secimtpi,matris1col,matris2col);
   freele(matris1,matris1col);
   freele(matris2,matris2col);

  return 0;
}