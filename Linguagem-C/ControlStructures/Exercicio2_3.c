#include <stdio.h>

void main()
{
int n=0, s=0, t=0;
float m=0;

do{
	printf("Digite um numero, negativo para encerrar:");
	scanf("%d", &n);
	if (n>=0){
		s=s+n;
		t=t+1;
	}
}while(n>=0);
m=(float)s/t;
printf("A média dos numeros digitados eh: %.2f",m);
}