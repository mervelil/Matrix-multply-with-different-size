#include <stdio.h>
#include "matrixoperations.h"
#include <time.h>
//#define OddRow (satir1 % 2 != 0)
//#define OddColumn (sutun1 % 2 != 0)
  // typedef struct
  // {
  //    int Rows;
  //    int Cols;
  //    int elements[satir1][sutun1];
  // } Matrix;

//   int matrixAlloc(Matrix *mat){
//     mat-> elements=(int *)malloc(mat->numberofCols *mat-> numberofRows * sizeof(int) );

//  }
void control(int matris1col,int matris2col,int secimtpi){
   int deger= (matris2col!=3 ||matris2col!=5);
    if(matris1col<matris2col){
         printf("Matris2 boyutu matris1 den büyük olamaz\n");
    }
    if (secimtpi!=0 && secimtpi!= 1){
        printf("Gecersiz secim tipi 0 ya da 1 giriniz\n");
    }
    if (matris1col %2 ==0 &&deger)
    {
      printf("Hata\n");
    }
}
int **ikiBoyutDiziOlustur(int satir, int sutun)
{

  int i;
  int **dizi = malloc(satir * sizeof(int *));
  for (i = 0; i < satir; i++)
    dizi[i] = malloc(sutun * sizeof(int));
  return dizi;
}
void ikiBoyutdiziDoldur(int **d, int satir, int sutun,int arg4)
{
  int i, j;
  srand(arg4);
  for (i = 0; i < satir; i++)
    for (j = 0; j < sutun; j++)
      d[i][j] = (rand() % 10) + 1;
}
void ikiBoyutdiziYazdir(int **d, int satir, int sutun)
{
  int i, j;
  
  for (i = 0; i < satir; i++){
   for (j = 0; j < sutun; j++){
    printf("%d\t ", d[i][j]);
   }
   printf("\n");
     
  }
    
}


// void depad(int *s, int *d, int dim)
// {
//   int i, j;
//   dim = dim - 2;
//   for (i = 0; i < dim; i++)
//     for (j = 0; j < dim; j++)
//       *(d + i * dim + j) = *(s + (i * (dim + 2) + (dim + 3 + j)));
// }
int** matrisislem(int **matris1,int **matris2, int m1,int m2)
{
 
  int i, j, k, l;
  int **sum=ikiBoyutDiziOlustur(m1-m2+1,m1-m2+1);
  for (i = 0; i < m1-m2+1; i++)
  {
    for (j = 0; j <m1-m2+1; j++)
    {
        sum[i][j]=0;
      for (k = 0; k < m2; k++)
      {

        for (l = 0; l < m2; l++)
        {
          sum[i][j]+= matris1[k+i][l+j] * matris2[k][l];    
          //  total [k][m]+=matris1[k+1][m]*matris2[k][m];
          //   total [k][m]+=matris1[k][m+1]*matris2[k][m];
        }
      }
      //printf("%d ",sum);
    //  return
      //sum[i*cozummatrisrow+j]=sum;
      //sum elde etcezv
    }
  }
  return  sum;
}
int ** depad(int *s, int *d, int dim)
{
  int i, j;
  dim = dim - 2;
  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
     return *(d + i * dim + j) = *(s + (i * (dim + 2) + (dim + 3 + j)));

      
}
int **operasyon1(int **matris1, int **matris2, int islemtipi,int r1,int r2)
{
  int g=r1; //matris1 satir
  int f=r2; // matris2 satir
  int dolgu; //cikti boyutu
 
  int ** cikis;
  int *t;
  int *dpad;
 int **cikti;
  int ciktimatrisiboyutu;
  if (islemtipi == 0)
  {
    ciktimatrisiboyutu = ((g - f + 2 * 0) / 1) + 1;
     cikis= matrisislem(matris1,matris2,g,f);
    cikti=ikiBoyutDiziOlustur(ciktimatrisiboyutu,ciktimatrisiboyutu);  
    ikiBoyutdiziYazdir(cikis,ciktimatrisiboyutu,ciktimatrisiboyutu);
  }
  if (islemtipi == 1)
  {
     dolgu=(f - 1) / 2;
    ciktimatrisiboyutu = ((g - f + 2 * dolgu) / 1) + 1; 
     t = (int*) calloc((r1+2)*(r1+2),sizeof(int));   
    dpad = (int*) calloc(r1*r1,sizeof(int));
    int **a = depad(t, dpad,ciktimatrisiboyutu+dolgu);
    cikis=matrisislem(a,matris2,g,f);
    cikti=ikiBoyutDiziOlustur(ciktimatrisiboyutu,ciktimatrisiboyutu);
    ikiBoyutdiziYazdir(cikis,ciktimatrisiboyutu,ciktimatrisiboyutu);
  }
  //int ciktimatris [ciktimatrisiboyutu][ciktimatrisiboyutu]=ikiBuyutDiziOlusutur(ciktimatrisiboyutu,ciktimatrisiboyutu);
 
}
void freele(int** a ,int a1){
  int i ;
   for ( i = 0; i < a1; i++)
   {
     free(a[i]);
   }
   free(a);
   
}