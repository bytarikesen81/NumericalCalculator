#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullan�lan Fonksiyonlar
float f(float*,int,float);
void fCreate(float*,int*);

int main(int argc, char *argv[]) {
	int i,j,N,k;
	float a,b,dx,sum,mul[MAX];
	
	//A��l�� Ekran�
    printf("Simpson'un 1/3 kurali ile belirli integral hesaplama programina hos geldiniz.");
    printf("\nOncelikle ana fonksiyonu olusturun.");
    
    //Fonksiyon olu�turucu (mul -> Katsay�lar, N->Fonksiyondaki terim say�s�(katsay� dizisinin boyutu))
    fCreate(mul,&N);
    
    //Belirli integrasyon i�in gerekli s�n�r de�erlerini alma
    do{
    	printf("\nIntegralin alt sinirini giriniz:");
    	scanf("%f",&a);
    	printf("\nIntegralin ust sinirini giriniz(alt sinirdan buyuk olmak zorundadir.):");
    	scanf("%f",&b);
    	if(b < a)
    	{
    		printf("\nUst sinir degeri alt sinir degerinden buyuk olmalidir.\nLutfen degerleri kosullara uyacak sekilde bir daha girin.");
		}
    }while(b < a);//�st s�n�r alt s�n�rdan b�y�k olana kadar de�erleri almaya devam et
    
    //Fonksiyonun en fazla ka� par�aya b�l�nece�ini belirleme
	printf("\n\nFonksiyon icin maks parcalanma degerini giriniz(Iterasyon sayisi):");
    scanf("%d",&k);
    
    //Iterasyonlar� ba�lat
    printf("ITERASYONLAR:\n----------------------------------------------------\n");
    for(i=1; i <= k; i++)
    {
    	dx = (b-a)/(2*i);
    	sum = f(mul,N,a) + f(mul,N,b);
    	for(j=1; j < (2*i); j++)
    	{
    		if(j%2 == 1)
    		{
    			sum += 4*(f(mul,N,(a+(j*dx))));
			}
			else
			{
				sum += 2*(f(mul,N,(a+(j*dx))));
			}
		}
		printf("\n[Iterasyon %d]Hesaplanan integral degeri:%f",i,(sum*(b-a))/(6*i));
		sum = 0;
	}
	return 0;
}

//Ana fonksiyonu olu�turur
void fCreate(float* mul,int* size){
	int i,N;
	printf("\n\nFONKSIYON OLUSTURUCU:\n-----------------------------------\n");
    printf("Fonksiyonun derecesini giriniz(max 32):");
    scanf("%d",&N);
    *size = N;
    for(i=0; i<=N; i++)
    {
        printf("%d.Terimin katsayisi:",i);
        scanf("%f",&mul[i]);
    }
    printf("\nFONKSIYON OLUSTURULDU:");
    for(i=N; i>=1; i--)
    {
    	printf("(%f)x^%d+",mul[i],i);
	}
	printf("%f",mul[0]);
    printf("\n----------------------------------\n");
}

//Fonksiyonun girilen noktadaki degerini verir
float f(float* a,int size,float x){
	int i,j;
	float y=a[0],r;
	for(i=1; i <= size; i++)
	{
		r=1;
		for(j=1; j <= i; j++)
		{
			r = r*x;
		}
		y = y+(a[i]*r);
	}
	return y;
}

