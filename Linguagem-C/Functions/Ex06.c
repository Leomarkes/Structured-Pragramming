#include <stdio.h>
#include <stdlib.h>

int multmm(int *vetor, int tam);

void main(){
	int *vet, t, n;

	printf("Digite a quantidade de numero a ser digitada:\n");
	scanf("%d", &t);
	vet = (int*)malloc(sizeof(int)*t);
	for(int c=0;c<t;c++){
		printf("Digite o numero %d\n", (c+1));
		scanf("%d", &vet[c]);
	}
	n = multmm(&vet[0],t);
	printf("A multiplicacao do menor pelo maior numero eh: %d\n", n);
	free(vet);
}

int multmm(int *vetor, int tam){
	int maior, menor;

	maior = vetor[0];
	menor = vetor[0];
	for(int i=0;i<tam;i++){
		if (vetor[i]>maior)
			maior = vetor[i];
		if (vetor[i]<menor)
			menor = vetor[i];
	}
	return (menor*maior);
}