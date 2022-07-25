#include <stdio.h>
#include <stdlib.h>
#define MAX 16
//Kullanýlan Fonksiyonlar
void printMatrix(int,float[MAX][MAX]);
void listArray(int,int,float[]);

//Program Gövdesi
int main(int argc, char *argv[]) {
	int i,j,p=1,k,N;
	float A[MAX][MAX],X[MAX],sum;
	//Açýlýþ Ekraný
	printf("Gauss-Seidel iterasyon metodu ile lineer denklem sistemlerini cozumleme programina hos geldiniz.");
	printf("\nOncelikle gerekli denklem sistemini olusturun.");
	
	//Denklem sistemini oluþtur
	printf("\n\nSISTEM OLUSTURUCU\n-----------------------------------------------\n");
	printf("UYARI:Girilen denklem sisteminden elde edilen katsayilar matrisinde\nkosegen degerleri bulunduklari satirin mutlak degerce en yuksek\ndegeri olmalidir");
	printf("\nDenklem/bilinmeyen sayisini girin:");
  	scanf("%d",&N);
  	printf("\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d.Denklemdeki %d.Bilinmeyenin Katsayisi:",i+1,j+1);
			scanf("%f",&A[i][j]);
		}
		printf("%d.Denklemdeki esitligin karsisinda yer alan sabit sayi:",i+1);
    	scanf("%f",&A[i][N]);
    	printf("\n");
	}
	//Oluþan ana matrisi yazdýr
	printMatrix(N,A);
	
	//Iterasyon sayýsýný belirle
	printf("\nIterasyon sayisini giriniz:");
	scanf("%d",&k);
	
	//Iterasyon adýmlarý için baþlangýç matrisini oluþtur ve yazdýr
	printf("\n\nIterasyonlar icin bilinmeyen matrisinin baslangic elemanlarini giriniz");
	for(i=0; i<N; i++)
	{
		printf("\n%d.bilinmeyen icin baslangic degeri:",i+1);
		scanf("%f",&X[i]);
	}
	listArray(0,N,X);
	printf("\n");
	
	//Iterasyonlarý baþlat
	while(p <= k)
	{
		for(i=0; i<N; i++)
		{
			sum=0;
			for(j=0; j<N; j++)
			{
				if(i != j)
				{
					sum += (A[i][j]*X[j]);
				}
			}
		    X[i] = (A[i][N]-sum)/A[i][i];
		}
		listArray(p,N,X);
		printf("\n");
		p++;
	}
	printf("\nIterasyonlar %d adimda tamamlandi.",k);
	return 0;
}

//Matrisi yazdýr
void printMatrix(int N,float matrix[MAX][MAX]){
	int i,j;
	printf("\nOLUSAN ANA MATRIS:\n\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("\t%f",matrix[i][j]);
		}
		printf("\n");
	}
}

//Her iterasyon sonucu oluþan matrisi listele
void listArray(int k,int N,float array[])
{
	int i;
	printf("%d.iterasyon icin sonuc matrisinin degerleri:\t[",k);
	for(i=0; i<N; i++)
	{
		if(i != N-1)
		{
			printf("%f\t",array[i]);
		}
		else
		{
			printf("%f",array[i]);
		}
	}
	printf("]");
}
