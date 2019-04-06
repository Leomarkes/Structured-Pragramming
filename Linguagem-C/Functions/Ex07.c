#include <stdio.h>

void promo(int *vet, int *promo);

void main(){
	int vetor[10] = {30, 15, 5, 10, 45, 50, 30, 10, 15, 60}, promocao[10];

	promo(vetor,promocao);
	for(int i=0;i<10;i++){
		printf("O numero de locacoes gratuitas do cliente %d é: %d\n", (i+1), promocao[i]);
	}
}

void promo(int *vet, int *promo){
	for (int c=0;c<10;c++){
		*(promo+c) = (*(vet+c))/15;
	}
}