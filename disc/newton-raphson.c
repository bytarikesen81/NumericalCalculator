#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullanýlan Fonksiyonlar
float f(float*,int,float);
float der(float*,int,float);
void fCreate(float*,int*);

//Program Gövdesi
int main(int argc, char *argv[]) {
	float p,a,b,k,mul[MAX];
	int i=2,N;
	
	//Açýlýþ Ekraný
    printf("Newton-Raphson metodu ile kok degeri hesaplama programina hos geldiniz.");
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
	
	//Sýnýr deðerlerinde kök bulunmadýysa iterasyonlara baþla
	else
	{
		//Iterasyonlar için durma koþulu
		printf("\nIterasyonlar icin minimum hata payi degerini girin:");
    	scanf("%f",&k);
    	
    	//Iterasyonlarý baþlat
    	printf("\nIterasyon %d:\tx%d:%f\tf(x%d):%f\tHata:-\t\tMin h.p:%f",i-2,i-2,a,i-2,f(mul,N,a),k);
    	p = a - (f(mul,N,a)/der(mul,N,a));//a = xo, p = x1
    	printf("\nIterasyon %d:\tx%d:%f\tf(x%d):%f\tHata:%f\tMin h.p:%f",i-1,i-1,p,i-1,f(mul,N,p),(p-a),k);
    	while(f(mul,N,p) != 0 && (p-a) >= k)
    	{
    		a = p;
    		p = a - (f(mul,N,a)/der(mul,N,a));
    		printf("\nIterasyon %d:\tx%d:%f\tf(x%d):%f\tHata:%f\tMin h.p:%f",i,i,p,i,f(mul,N,p),(p-a),k);
    		i++;
		}
		
		//Tamamlanma Durumlarý
		if((p-a) < k)
		{
			printf("\nIterasyonlar %d adimda tamamlandi.",i-1);
			printf("\nYaklasik kok degeri:%f",p);
		}
		else
		{
			printf("\nIterasyonlar %d adimda tamamlandi.",i-1);
			printf("\n[X = %f] noktasinda kok bulundu!(x%d:%f,f[x%d]:%f)",p,i-1,p,i-1,f(mul,N,p));
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

//Fonksiyonun girilen noktada türevini hesaplar
float der(float* a,int size,float x){
	int i,j;
	float y=a[1],r;
	for(i=1; i<size; i++)
	{
		r=1;
		for(j=1; j <= i; j++)
		{
			r = r*x;
		}
		y = y+(a[i+1]*(i+1)*r);
	}
	return y;
}
