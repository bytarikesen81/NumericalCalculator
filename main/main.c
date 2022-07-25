#include <stdio.h>
#include <stdlib.h>
#define MAX 128

//Yardimci Fonksiyonlar
float f(float*,int,float);
void fCreate(float*,int*);
float max(float,float);
void printMatrix(float[MAX][MAX],int,int);
void listArray(int,int,float[]);
float der(float*,int,float);
void sDer(int);
void cDer();

//Islem Fonksiyonlari
void bisection(void);
void regulaFalsi(void);
void gaussSolve(void);
void gaussSeidelSolve(void);
void gnInterpolation(void);
void matrixInverter(void);
void numericDerivation(void);
void nrSolve(void);
void secantSolve(void);
void simpsonIntegral(void);
void trapezoidalIntegral(void);

int main(char* argv,int argc){
	int sel;
	printf("SAYISAL ANALIZ ISLEMLERI HESAPLAYICISI PROGRAMINA HOS GELDINIZ.\n");
	do{
		system("color a");
		printf("\n--------------------------------ANA MENU(ISLEM LISTESI)--------------------------------\n\n");
		printf("1-Bisection ile Aralikta Kok Bulma\n");
		printf("2-Regula Falsi ile Kok Hesaplama\n");
		printf("3-Gauss Eliminasyon Yontemi ile Lineer Denklem Sistemini Cozumleme\n");
		printf("4-Gauss-Seidel Eliminasyon Yontemi ile Lineer Denklem Sistemini Cozumleme\n");
		printf("5-Gregory-Newton Yontemi ile Interpolasyon Hesaplama\n");
		printf("6-Girilen Matrisin Tersini Hesaplama\n");
		printf("7-Numerik Yaklasim ile Turev Hesaplama\n");
		printf("8-Newton-Raphson ile Kok Hesaplama\n");
		printf("9-Secant Metodu ile Yaklasik Degerli Kok Hesaplama\n");
		printf("10-Simpson 1/3 Metodu ile Numerik Yaklasimli Integral Hesaplama\n");
		printf("11-Trapez Metodu ile Numerik Yaklasimli Integral Hesaplama\n");
		printf("Islem icin menude islemin solunda yer alan numarayi, cikis icin bu numaralardan farkli bir deger giriniz.\n");
		
		printf("\nSecim-->:");
		scanf("%d",&sel);
		
		switch(sel){
			case 1: bisection(); break;
			case 2: regulaFalsi(); break;
			case 3: gaussSolve(); break;
			case 4: gaussSeidelSolve(); break;
			case 5:	gnInterpolation(); break;
			case 6: matrixInverter(); break;
			case 7: numericDerivation(); break;
			case 8: nrSolve(); break;
			case 9: secantSolve(); break;
			case 10: simpsonIntegral(); break;
			case 11: trapezoidalIntegral(); break;
			default: break;
		}
		system("cls");
	}while(sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5 || sel == 6 || sel == 7 || sel == 8 || sel == 9 || sel == 10 || sel == 11);
	return 0;
}

void bisection(void){
	int N,i=1,r=2;
	float mul[MAX],a,b,mid,e,k;
	//Açýlýþ Ekraný
    printf("Bisection(yarilama) metodu ile kok degeri hesaplama programina hos geldiniz");
    printf("\nOncelikle ana fonksiyonu olusturun");
    
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
        
        //Baþlangýç iterasyonu
        mid = (a+b)/2;
        e = (b-a)/r;
        printf("\nIterasyon %d:\ta=%f\tb=%f\tmid=%f\tXk[f(mid)]=%f\tHata=%f\tMin h.p=%f",i,a,b,mid,f(mul,N,mid),e,k);
        
        //Ýterasyon adýmlarý
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
		
		//Iterasyonun tamamlanma durumlarý
		if (k > e)
		{
			printf("\nIterasyonlar %d adimda tamamlandi.",i);
			printf("\nYaklasik kok degeri:%f",mid);
		}
		else if(f(mul,N,a) == 0)
		{
		 printf("\na noktasýnda kok bulundu!(%f,0)",a);
		}
		else if(f(mul,N,b) == 0)
		{
		 printf("\nb noktasýnda kok bulundu(%f,0)",b); 
		}
		else
		{
		 printf("\nOrta noktada kok bulundu(%f,0)",mid); 
		}
	}
}

void regulaFalsi(void){
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
}

void gaussSolve(void){
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
}

void gaussSeidelSolve(void){
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
	printMatrix(A,N,N);
	
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
}

void gnInterpolation(void){
	int i,j,N;
	float h,k,sum,x,p,A[MAX],M[MAX][MAX];
	
	//Açýlýþ Ekraný
	printf("Gregory-Newton ileri farklar yontemi ile interpolasyon programina hos geldiniz");
	
	//Veri kümesi için baþlangýç ve ortak fark deðerini belirler
	printf("\nLutfen baslangic degerini girin:");
	scanf("%3f",&A[0]);
	printf("\nVeri sayisini girin [x ve f(x)](MAX 16):");
	scanf("%d",&N);
	printf("\nVeriler arasindaki artis miktarini girin:");
	scanf("%3f",&h);
	
	//Girilen veri kümesini listeler
	printf("\nVeriler(x):\n--------------");
	for(i=0; i<N; i++)
	{
		A[i] = A[0] + (h*i);
		printf("\nx%d: %3f",i,A[i]);
	}
	printf("\n-----------------------------------\n");
	
	//Girilen verilerin görüntülerini oluþturan fonksiyonu belirler
	for(i=0; i<N; i++)
	{
		printf("x%d icin f(x%d) degerini girin:",i,i);
		scanf("%3f",&M[i][0]);
	}
	
	//Olusturulan veri seti icin degisim kümeleri 
	for(j=0; j<N-1; j++)
	{
		for(i=0; i<N-(j+1); i++)
		{
			M[i][j+1] = M[i+1][j] - M[i][j];
		}
	}
	
	//Veri seti ve deðiþim kümelerini listeler
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
	
	//Interpolasyon icin gerekli polinomu oluþturur ve istenilen deðeri bu fonksiyon üzerinden hesaplar
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
	//Sonucu ekrana yazdýr
	printf("\nInterpolasyonun Sonucu:%f",sum);	
}

void matrixInverter(void){
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
}

void numericDerivation(void){
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
}

void nrSolve(void){
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
}

void secantSolve(void){
	float a,b,c,mul[MAX];
	int i,N,k;
	printf("Secant metodu ile kokun yaklasik degerini hesaplama moduna hos geldiniz.");
    printf("\nOncelikle ana fonksiyonu olusturun.");
    
    //Fonksiyon oluþturucu (mul -> Katsayýlar, N->Fonksiyondaki terim sayýsý(katsayý dizisinin boyutu))
    fCreate(mul,&N);
    
    //Starting Iterations
    printf("Iterasyon sayisini giriniz.:");
    scanf("%d",&k);
    printf("\nIterasyonlar icin baslangic degerini girin:");
    scanf("%f",&a);
    printf("\nIterasyonlar icin ikinci degeri girin(ilk girilen baslangic degerine yakin olmali):");
    scanf("%f",&b);
    i=2;
    if(f(mul,N,a) == 0)
    {
    	printf("[%f,%f] noktasinda kok bulundu!",a,f(mul,N,a));
	}
	else if (f(mul,N,a) == 0)
	{
		printf("[%f,%f] noktasinda kok bulundu!",b,f(mul,N,b));
	}
	else
	{
		c = b - ((f(mul,N,b)*(b-a))/(f(mul,N,b) - f(mul,N,a)));
		printf("\nIterasyon %d: Deger(X%d):%f,Fonk Degeri[f(%f)]:%f",i-1,i-1,c,c,f(mul,N,c));
		a = b;
		b = c;
    	while(f(mul,N,c) && i <= k)
    	{
    		c = b - ((f(mul,N,b)*(b-a))/(f(mul,N,b) - f(mul,N,a)));
    		printf("\nIterasyon %d: Deger(X%d):%f,Fonk Degeri[f(%f)]:%f",i,i,c,c,f(mul,N,c));
    		a = b;
    		b = c;
    		i++;
		}
	
		if(i > k)
		{
			printf("\nIterasyonlar %d adimda tamamlandi",k);
		}
		else
		{
			printf("\nIterasyonlar %d adimda tamamlandi",i);
			printf("\nIterasyonlar %d adim erken tamamlandi cunku %d.interasyonda ve [%f,%f] noktasinda kok bulundu!",k-i,i,c,f(mul,N,c));
		}
	}
}

void simpsonIntegral(void){
	int i,j,N,k;
	float a,b,dx,sum,mul[MAX];
	
	//Açýlýþ Ekraný
    printf("Simpson'un 1/3 kurali ile belirli integral hesaplama programina hos geldiniz.");
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
}

void trapezoidalIntegral(void){
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
}

 //Ana fonksiyonu oluşturur
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
		printf("(%f)x^%d+",mul[i],i);
	
	printf("%f",mul[0]);printf("\n----------------------------------\n");
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
			r = r*x;
		
		y += r*(a[i]);
	}
	return y;
}


//Durma koşulu için maks hatayı alan fonksiyon
float max(float a,float b){if(a>b) return a; else return b;}

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

//Türev operasyonlari
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
