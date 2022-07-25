#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullanýlan Fonksiyonlar
void printMatrix(float[MAX][MAX],int,int);

//Program Gövdesi
int main(void){
  int i,j,k=0,N;
  float p,row,A[MAX][MAX],X[MAX];
  
  //Açýlýþ Ekraný
  printf("Gauss eliminasyon metodu ile lineer denklem sistemini cozumleme programina hos geldiniz.");
  printf("\nOncelikle gerekli denklem sistemini olusturun.");
  
  //Denklem sistemini oluþtur
  printf("\n\nSISTEM OLUSTURUCU\n-----------------------------------------------\n");
  printf("Denklem/bilinmeyen sayisini girin:");
  scanf("%d",&N);
  printf("\n");
  for(i=0; i<N; i++)
  {
    for(j=0; j<N; j++)
    {
      printf("%d.Denklemdeki %d.Bilinmeyenin Katsayisi:",i+1,j+1);
      scanf("%3f",&A[i][j]);
    }
    printf("%d.Denklemdeki esitligin karsisinda yer alan sabit sayi:",i+1);
    scanf("%3f",&A[i][N]);
    printf("\n");
  }
  
  //Matrisleri yazdýr 
  printf("Girilen degerlerle olusturulan orijinal matris:");
  printf("\n-----------------------------------------------------------\n");
  printMatrix(A,N,N+1);
  printf("Matris Gauss eliminasyon metoduyla cozumlenmis hali:");
  printf("\n-----------------------------------------------------------\n");
  
  //Ýþlemleri baþlat
  while(k<N-1)
  {
    for(i=k+1; i<N; i++)
    {
      p = (-1)*(A[k][k]/A[i][k]);
      for(j=k; j<N+1; j++)
       {
        A[i][j] = p*A[i][j]+ A[k][j];
       }
    }
    k++;
  }
  X[N-1] = (A[N-1][N]/A[N-1][N-1]);
  for(i=N-2; i >= 0; i--)
  {
    row = 0;
    for(j=i+1; j<N; j++)
    {
  	  row = row+(X[j]*A[i][j]);
    }
    X[i] = (A[i][N]-row)/A[i][i];
  }
  
  //Sonucunda elde edilen çözüm kümesinin elemanlarýný yazdýr
  printf("\nSONUC:\n----------------------------\n");
  for(i=0; i<N; i++)
  {
  	printf("X%d:%f\n",i+1,X[i]);
  }
  return 0;
}

//Matrisi yazdýr
void printMatrix(float M[MAX][MAX],int sizeM,int sizeN)
{
  int i,j;
  for(i=0; i<sizeM; i++)
  {
    for(j=0; j<sizeN; j++)
    {
  	  printf("%f\t",M[i][j]);
	}
	printf("\n");
  }
  printf("\n\n");
}
 
