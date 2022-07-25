#include <stdio.h>
#include <stdlib.h>
#define MAX 16
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Program g�vdesi
int main(int argc, char *argv[]) {
	int i,j,N;
	float h,k,sum,x,p,A[MAX],M[MAX][MAX];
	
	//A��l�� Ekran�
	printf("Gregory-Newton ileri farklar yontemi ile interpolasyon programina hos geldiniz");
	
	//Veri k�mesi i�in ba�lang�� ve ortak fark de�erini belirler
	printf("\nLutfen baslangic degerini girin:");
	scanf("%3f",&A[0]);
	printf("\nVeri sayisini girin [x ve f(x)](MAX 16):");
	scanf("%d",&N);
	printf("\nVeriler arasindaki artis miktarini girin:");
	scanf("%3f",&h);
	
	//Girilen veri k�mesini listeler
	printf("\nVeriler(x):\n--------------");
	for(i=0; i<N; i++)
	{
		A[i] = A[0] + (h*i);
		printf("\nx%d: %3f",i,A[i]);
	}
	printf("\n-----------------------------------\n");
	
	//Girilen verilerin g�r�nt�lerini olu�turan fonksiyonu belirler
	for(i=0; i<N; i++)
	{
		printf("x%d icin f(x%d) degerini girin:",i,i);
		scanf("%3f",&M[i][0]);
	}
	
	//Olusturulan veri seti icin degisim k�meleri 
	for(j=0; j<N-1; j++)
	{
		for(i=0; i<N-(j+1); i++)
		{
			M[i][j+1] = M[i+1][j] - M[i][j];
		}
	}
	
	//Veri seti ve de�i�im k�melerini listeler
	printf("\n\n");
	printf("f(x)\t\t");
	for(i=1; i<N; i++)
	{
		printf("D%dfo\t\t",i);
	}
	printf("\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N-i; j++)
		{
			printf("%3f\t",M[i][j]);
		}
		printf("\n");
	}
	
	//Interpolasyon icin gerekli polinomu olu�turur ve istenilen de�eri bu fonksiyon �zerinden hesaplar
	printf("\nOlusturulan veri setine ait fonksiyonda hesaplanmasini istediginiz degeri girin:");
	scanf("%f",&x);
	k = (x-A[0])/h;
	sum = M[0][0];
	for(i=1; i<N; i++)
	{
		p = M[0][i];
		for(j=0; j<i; j++)
		{
			p *= (k-j);
			p /= j+1;
		}
		sum += p;
	}
	//Sonucu ekrana yazd�r
	printf("\nInterpolasyonun Sonucu:%f",sum);
	return 0;
}




















