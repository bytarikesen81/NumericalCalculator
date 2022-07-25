#include <stdio.h>
#include <stdlib.h>
#define MAX 128
//Kullan�lan Fonksiyonlar
float f(float*,int,float);
void fCreate(float*,int*);

//Program G�vdesi
int main(int argc,char *argv[])
{
    int N,i=1,r=2;
	float mul[MAX],a,b,mid,e,k;
	//A��l�� Ekran�
    printf("Bisection(yarilama) metodu ile kok degeri hesaplama programina hos geldiniz");
    printf("\nOncelikle ana fonksiyonu olusturun");
    
    //Fonksiyon olu�turucu (mul -> Katsay�lar, N->Fonksiyondaki terim say�s�(katsay� dizisinin boyutu))
    fCreate(mul,&N);
    
    //Kullan�lacak ba�lang�� de�erleri i�in aral�k belirle
    do
    {
    	printf("\nIterasyonlar icin araligin alt sinirini girin:");
    	scanf("%f",&a);
    	printf("\nIterasyonlar icin araligin ust sinirini girin:");
    	scanf("%f",&b);
    	if(f(mul,N,a)*f(mul,N,b) > 0)
    	{
    		printf("\nGirdiginiz aralikta kok bulunamadi. Lutfen degerleri tekrar girin\n");
		}
		else
		{
			printf("\nAralikta en az 1 kok bulundu!");
		}
		if(b<=a)
		{
			printf("\nAraligin ust sinir degeri,alt sinir degerinden buyuk olamaz.\nLutfen kosullari saglayacak sekilde degerleri tekrar girin.");
		}
		printf("\n");
	}while (f(mul,N,a)*f(mul,N,b) > 0 || b <= a);//[a,b] aral���nda k�k olana ve b>a olana kadar almaya devam et
    
    //f(a) ve f(b) de�erlerinden birinin veya her ikisinin 0'a e�it olup olmad���n� kontrol et ve e�itlik varsa k�k� direkt yazd�r
	if(f(mul,N,a) == 0 && f(mul,N,b) != 0)
	{
		printf("\na noktasinda kok bulundu! (%f,0)",a);
	}
	else if(f(mul,N,a) != 0 && f(mul,N,b) == 0)
	{
		printf("\nb noktasinda kok bulundu! (%f,0)",b); 
	}
	else if(f(mul,N,a) == 0 && f(mul,N,b) == 0)
	{
		printf("\nHem a hem de b degerlerinde kok bulundu!\nX1[a]:(%f,0)\nX2[b]:(%f,0)",a,b);
	}
	
	//S�n�r de�erlerinde k�k bulunmad�ysa iterasyonlara ba�la
	else 
	{
		//Iterasyonlar i�in durma ko�ulu
		printf("\nIterasyonlar icin minimum hata payi degerini girin:");
        scanf("%f",&k);
        
        //Ba�lang�� iterasyonu
        mid = (a+b)/2;
        e = (b-a)/r;
        printf("\nIterasyon %d:\ta=%f\tb=%f\tmid=%f\tXk[f(mid)]=%f\tHata=%f\tMin h.p=%f",i,a,b,mid,f(mul,N,mid),e,k);
        
        //�terasyon ad�mlar�
		while(k <= e && f(mul,N,a)*f(mul,N,b)*f(mul,N,mid) != 0)
		{
			if(f(mul,N,a)*f(mul,N,mid) < 0)
			{
				b = mid;
				mid = (a+b)/2;
			}
			else
			{
				a = mid;
				mid = (a+b)/2;
			}
			r *= 2;
			e = (b-a)/r;
			printf("\nIterasyon %d:\ta=%f\tb=%f\tmid=%f\tXk[f(mid)]=%f\tHata=%f\tMin h.p=%f",i+1,a,b,mid,f(mul,N,mid),e,k);
			i++;
		}
		
		//Iterasyonun tamamlanma durumlar�
		if (k > e)
		{
			printf("\nIterasyonlar %d adimda tamamlandi.",i);
			printf("\nYaklasik kok degeri:%f",mid);
		}
		else if(f(mul,N,a) == 0)
		{
		 printf("\na noktas�nda kok bulundu!(%f,0)",a);
		}
		else if(f(mul,N,b) == 0)
		{
		 printf("\nb noktas�nda kok bulundu(%f,0)",b); 
		}
		else
		{
		 printf("\nOrta noktada kok bulundu(%f,0)",mid); 
		}
	}
    return 0;
}

//Ana fonksiyonu olu�turur
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
float f(float* a,int size,float x)
{
    int i,j;
	float r, y=a[0];
    for(i=1; i<=size; i++)
    {
        r=1;
        for(j=1; j<=i; j++)
        {
            r = r*x;
        }
        y += r*(a[i]);
    }
    return y;
}
