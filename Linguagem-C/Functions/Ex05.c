#include <stdio.h>

int testval(int i, int f, int *par, int *imp);

void main(){
	int n, ini, fim, pares=0, impares=0;

	printf("Digite o inicio do intervalo:\n");
	scanf("%d", &ini);
	printf("Digite o fim do intervalo:\n");
	scanf("%d", &fim);
	n = testval(ini,fim,&pares,&impares);
	printf("Numero de valoros: %d\nNumero de pares: %d\nNumero de impares: %d\n", n, pares, impares);
}

int testval(int i, int f, int *par, int *imp){
	int n=0;

	for (int c=i;c<(f+1);c++){
		n++;
		if(c%2==0)
			(*par)++;
		else
			(*imp)++;
	}
	return(n);
}