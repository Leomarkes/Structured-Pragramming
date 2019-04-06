#include <stdio.h>
void main(){

	int t, n, a1, a2, c;

	printf("Digite o numero de termos da sequencia de fibonacci que deseja exibir:");
	scanf("%d", &n);
	if (n==1)
		printf("0");
	else if (n==2)
		printf("0 1");
	else{
		a1 = 1;
		a2 = 0;
		printf("0 1 ");
		for (c=3;c<=n;c++){
			t = a1+a2;
			printf("%d ", t);
			a2=a1;
			a1=t;
		}
	}
	printf("\n");
}