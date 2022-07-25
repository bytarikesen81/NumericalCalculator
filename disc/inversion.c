#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullanýlan Fonksiyonlar
void printMatrix(float[MAX][MAX],int,int);

//Program Gövdesi
int main(int argc, char *argv[]) {
	int i,j,k=0,N;
	float A[MAX][MAX],B[MAX][MAX],c;
	
	//Açýlýþ Ekraný
	printf("NXN'lik matrisin tersini bulma programina hos geldiniz.");
	printf("\nOncelikle gerekli kare matrisi olusturun.");
	
	//Matris Oluþturma
	printf("\n\n-----------------------------------------------------------------------\n");
	printf("WARNING:Invers matrisin hesaplanabilmesi icin girilen matristeki kosegen\ndegerlerinin 0 olmamasina dikkat ediniz.");
	printf("\n-----------------------------------------------------------------------\n");
	printf("\nMatrisin sutun/satir boyutunu giriniz:");
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("\nMatrisin elemanini giriniz a(%d)(%d):",i+1,j+1);
			scanf("%f",&A[i][j]);
			if(i == j)
			{
				B[i][j] = 1;
			}
			else
			{
				B[i][j] = 0;
			}
		}
	}
	printMatrix(A,N,N);
	//Gauss-Jordan ile invers alma iþlemlerini baþlatýr
	while(k<N)
	{
		for(i=0; i<N; i++)
		{
			if(i != k && A[i][k] != 0)
			{
				c = -1*(A[k][k]/A[i][k]);
				for(j=0; j<N; j++)
				{
					A[i][j] = c*(A[i][j]) + A[k][j];
					B[i][j] = c*(B[i][j]) + B[k][j];
				}
			}
		}
		k++;
	}
	for(i=0; i<N; i++)
	{
		c = (1/A[i][i]);
		A[i][i] = c*A[i][i];
		for(j=0; j<N; j++)
		{
			B[i][j] = (c*B[i][j]);
		}
	}
	
	//Oluþturulan ters matrisi yazdýr
	printf("\nGIRILEN MATRISIN INVERSI:\n-----------------------------------\n");
	printMatrix(B,N,N);
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
	printf("\n----------------------------------------------\n");
}
