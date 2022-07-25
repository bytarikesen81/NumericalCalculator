#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullanýlan Fonksiyonlar
float f(float*,int,float);
void fCreate(float*,int*);
void sDer(int);
void cDer();

int main(int argc, char *argv[]) {
	int k,N,h,exit=0;
	float mul[MAX];
	//Açýlýþ Ekraný
	printf("Numerik turev alma programina hos geldiniz.");
	printf("\nLutfen program menusu uzerinden istediginiz isleme ait secimi yapin.");
	do{
		//Ana Seçim Menüsü
		printf("\n\nANA MENU\n-----------------------------------------------------------\n");
		printf("1-Ileri farklar ile sayisal turev");
		printf("\n2-Geri farklar ile sayisal turev");
	    printf("\n3-Merkezi farklar ile sayisal turev");
	    printf("\n4-Cikis");
	    printf("\nSecim imleci----->:");
	    scanf("%d",&k);
	    
	    //Seçim sonucu gerçekleþecek iþlemler
	    if(k == 1)
	    {
	    	sDer(1);//Ýleri farklar ile türev alýr
		}
		else if(k == 2)
		{
			sDer(-1);//Geri farklar ile türev alýr
		}
		else if(k == 3)
		{
			cDer();//Merkezi farklar ile türev alýr
		}
		//Çýkýþ deðiþkenini 1'e eþitle ve programdan çýk
		else if(k == 4)
		{
			printf("\nProgramdan cikis yapildi.");
			exit = 1;
		}
		
		//Geçersiz iþlem uyarýsý 
		else
		{
			printf("\nWARNING:Lutfen menude gecerli olan islemlere ait bir numara girin.");
			printf("\nAna menuye yonlendiriliyorsunuz.");
		}
		
	}while(exit != 1);
	return 0;
}

//Ana fonksiyonu oluþturur
void fCreate(float* mul,int* size)
{
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

//Türev operasyonlarý
void sDer(int op)
{
	int N;
	float x,h,mul[MAX],der;
	fCreate(mul,&N);
	printf("\nTurevini almak istediginiz degeri giriniz:");
	scanf("%f",&x);
	printf("\nTurev icin gerekli fark degerini giriniz:");
	scanf("%f",&h);
	h *= op;
	der = (f(mul,N,x+h)-f(mul,N,x))/h;
	printf("\nGirilen noktadaki turev degeri: %f",der);
}

void cDer()
{
	int N;
	float x,h,mul[MAX],der;
	fCreate(mul,&N);
	printf("\nTurevini almak istediginiz degeri giriniz:");
	scanf("%f",&x);
	printf("\nTurev icin gerekli fark degerini giriniz:");
	scanf("%f",&h);
	der = (f(mul,N,x+h)-f(mul,N,x-h))/(h*2);
	printf("\nGirilen noktadaki turev degeri: %f",der);
}

