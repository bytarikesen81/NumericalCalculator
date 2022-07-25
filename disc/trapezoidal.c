#include <stdio.h>
#include <stdlib.h>
#define MAX 32

//Kullanýlan Fonksiyonlar
float f(float*,int,float);
void fCreate(float*,int*);

//Program gövdesi
int main(int argc, char *argv[]) {
	int i,j,N,k;
	float a,b,dx,sum,mul[MAX];
	
	//Açýlýþ Ekraný
    printf("Trapez kurali ile belirli integral hesaplama programina hos geldiniz.");
    printf("\nOncelikle ana fonksiyonu olusturun.");
    
    //Fonksiyon oluþturucu (mul -> Katsayýlar, N->Fonksiyondaki terim sayýsý(katsayý dizisinin boyutu))
    fCreate(mul,&N);
    
    //Belirli integrasyon için gerekli sýnýr deðerlerini alma
    do{
    	printf("\nIntegralin alt sinirini giriniz:");
    	scanf("%f",&a);
    	printf("\nIntegralin ust sinirini giriniz(alt sinirdan buyuk olmak zorundadir.):");
    	scanf("%f",&b);
    	if(b < a)
    	{
    		printf("\nUst sinir degeri alt sinir degerinden buyuk olmalidir.\nLutfen degerleri kosullara uyacak sekilde bir daha girin.");
		}
    }while(b < a);//Üst sýnýr alt sýnýrdan büyük olana kadar deðerleri almaya devam et
    
	//Fonksiyonun en fazla kaç parçaya bölüneceðini belirleme
	printf("\n\nFonksiyon icin maks parcalanma degerini giriniz(Iterasyon sayisi):");
    scanf("%d",&k);
    
    //Iterasyonlarý baþlat
    printf("ITERASYONLAR:\n----------------------------------------------------\n");
    printf("[Iterasyon 1] Hesaplanan integral degeri:%f",(b-a)*((f(mul,N,a)+f(mul,N,b))/2));
    for(i=1; i < k; i++)
    {
    	dx = (b-a)/(i+1);
    	sum = f(mul,N,a)+f(mul,N,b);
    	for(j=0; j<i; j++)
    	{
    		sum += 2*f(mul,N,(a+((j+1)*dx)));
		}
		printf("\n[Integrasyon %d] Hesaplanan integral degeri:%f",i+1,(dx/2)*sum);
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
