#include <stdio.h>
#include <stdlib.h>
#define MAX 32
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float f(float[],int,float);
int main(int argc, char *argv[]) {
	float a,b,c,mul[MAX];
	int i,N,k;
	printf("The near value of root point determinator with Secant method");
    printf("\nCreate the main function first.");
    //Function Creation
    printf("\n\nFUNCTION CREATOR:\n-----------------------------------\n");
    printf("Enter a degree value for the function(max 32):");
    scanf("%d",&N);
    for(i=0; i<=N; i++)
    {
        printf("Enter multiply of term(%d of %d):",i,N);
        scanf("%f",&mul[i]);
    }
    printf("\nFUNCTION CREATED:");
    for(i=N; i>=1; i--)
    {
    	printf("(%f)x^%d+",mul[i],i);
	}
	printf("%f",mul[0]);
    printf("\n----------------------------------\n");
    
    //Starting Iterations
    printf("Enter the iteration count:");
    scanf("%d",&k);
    printf("\nEnter the first value of iterations:");
    scanf("%f",&a);
    printf("\nEnter the second value of iterations(should be near the first value):");
    scanf("%f",&b);
    i=2;
    if(f(mul,N,a) == 0)
    {
    	printf("Root found at the point [%f,%f]!",a,f(mul,N,a));
	}
	else if (f(mul,N,a) == 0)
	{
		printf("Root found at the point [%f,%f]!",b,f(mul,N,b));
	}
	else
	{
		c = b - ((f(mul,N,b)*(b-a))/(f(mul,N,b) - f(mul,N,a)));
		printf("\nIteration %d: Value(X%d):%f,Func Value[f(%f)]:%f",i-1,i-1,c,c,f(mul,N,c));
		a = b;
		b = c;
    	while(f(mul,N,c) && i <= k)
    	{
    		c = b - ((f(mul,N,b)*(b-a))/(f(mul,N,b) - f(mul,N,a)));
    		printf("\nIteration %d: Value(X%d):%f,Func Value[f(%f)]:%f",i,i,c,c,f(mul,N,c));
    		a = b;
    		b = c;
    		i++;
		}
	
		if(i > k)
		{
			printf("\nIterations completed in %d step(s)",k);
		}
		else
		{
			printf("\nIterations completed in %d step(s)",i);
			printf("\nIterations completed %d step(s) earlier because in iteration %d root found at the point [%f,%f]!",k-i,i,c,f(mul,N,c));
		}
	}
	return 0;
}

//Creating Main Func
float f(float a[],int size,float x){
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
