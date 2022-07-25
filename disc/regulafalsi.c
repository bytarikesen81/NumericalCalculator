#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullanýlan Fonksiyonlar

void fCreate(float*,int*);
float f(float*,int,float);
float max(float,float);

//Program Gövdesi
int main(int argc, char *argv[]) {
	float a,b,e,k,xf,mul[MAX];
	int i=1,N;
	
	//Açýlýþ Ekraný
    printf("Regula-Falsi metodu ile kok degeri hesaplama programina hos geldiniz.");
    printf("\nOncelikle ana fonksiyonu olusturun.");
    
    //Fonksiyon oluþturucu (mul -> Katsayýlar, N->Fonksiyondaki terim sayýsý(katsayý dizisinin boyutu))
    fCreate(mul,&N);
    
    //Kullanýlacak baþlangýç deðerleri için aralýk belirle
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
	}while (f(mul,N,a)*f(mul,N,b) > 0 || b <= a);//[a,b] aralýðýnda kök olana ve b>a olana kadar almaya devam et
	
	//f(a) ve f(b) deðerlerinden birinin veya her ikisinin 0'a eþit olup olmadýðýný kontrol et ve eþitlik varsa kökü direkt yazdýr
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
	
	else
	{
		//Iterasyonlar için durma koþulu
		printf("\nIterasyonlar icin minimum hata payi degerini girin:");
    	scanf("%f",&k);
    	
    	//Iterasyonlarý baþlat
		xf = (b*f(mul,N,a)-a*f(mul,N,b))/(f(mul,N,a)-f(mul,N,b));
		e = max((xf-a),(b-xf));
		printf("\nIterasyon %d:\tx%d:%f\tf(x%d):%f\tHata:%f\tMin h.p:%f",i,i,xf,i,f(mul,N,xf),e,k);
		while(e >= k && f(mul,N,a)*f(mul,N,b)*f(mul,N,xf) != 0)
		{
			if(f(mul,N,a)*f(mul,N,xf)<0)
			{
				b = xf;
				xf = (b*f(mul,N,a)-a*f(mul,N,b))/(f(mul,N,a)-f(mul,N,b));
			}
			else
			{
				a = xf;
				xf = (b*f(mul,N,a)-a*f(mul,N,b))/(f(mul,N,a)-f(mul,N,b));
			}
			e = max((xf-a),(b-xf));
			printf("\nIterasyon %d:\tx%d:%f\tf(x%d):%f\tHata:%f\tMin h.p:%f",i+1,i+1,xf,i+1,f(mul,N,xf),e,k);
			i++;
		}
		
		//Tamamlanma Durumlarý
		if (k > e)
		{
		 	printf("\nIterasyonlar %d adimda tamamlandi.",i);
			printf("\nYaklasik kok degeri:%f",xf);
		}
		else if(f(mul,N,a) == 0)
		{
		 	printf("\nIterasyonlar %d adimda tamamlandi.",i);
		 	printf("\n[X = %f] noktasinda kok bulundu!(x%d:%f,f[x%d]:%f)",a,i,a,i,f(mul,N,a));
		}
		else if(f(mul,N,b) == 0)
		{
		 	printf("\nIterasyonlar %d adimda tamamlandi.",i);
		 	printf("\n[X = %f] noktasinda kok bulundu!(x%d:%f,f[x%d]:%f)",b,i,b,i,f(mul,N,b));
		}
		else
		{
		 	printf("\nIterasyonlar %d adimda tamamlandi.",i);
			printf("\n[X = %f] noktasinda kok bulundu!(x%d:%f,f[x%d]:%f)",xf,i,xf,i,f(mul,N,xf));
		}
	}
	return 0;
}
//Ana fonksiyonu oluþturur
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
float f(float a[],int size,float x)
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

//Durma koþulu için maks hatayý alan fonksiyon
float max(float a,float b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

