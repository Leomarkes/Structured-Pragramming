#include <stdio.h>

void main()
{
	int x, y, s=0, c;
	long int m=1;

	do{
		printf("Digite dois numeros, sendo o segundo maior que o primeiro:");
		scanf("%d %d",&x, &y);
	}while(x>=y);
	for (c=x;c<=y;c++){
		if (c%2==0){
			s = s+c;
		}else{
			m = m*c;
		}
}
printf("A soma dos numeros pares entre %d e %d eh %d e a multiplicacao dos impares eh %ld", x,y,s,m);
}