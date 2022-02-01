#ifndef MATRIXOPERATIONS_H_
#define MATRIXOPERATIONS_H_

void control(int matris1row, int matris2row,int secimtpi);
int **ikiBoyutDiziOlustur(int satir, int sutun);
void ikiBoyutdiziDoldur(int **d, int satir, int sutun,int srand);
void ikiBoyutdiziYazdir(int **d, int satir, int sutun);

int **depad(int *s, int *d, int dim);
int** matrisislem(int **matris1,int **matris2, int m1,int m2);
int **operasyon1(int **matris1, int **matris2, int islemtipi,int r1,int r2);
void freele(int** a ,int a1);
#endif 