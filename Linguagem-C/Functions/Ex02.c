#include <stdio.h>

int ord(int *n1, int *n2);

void main(){
	int maior, menor, c;

	printf("Digite o primeiro numero:\n");
	scanf("%d", &maior);
	printf("Digite o segundo numero:\n");
	scanf("%d", &menor);
	c = ord(&maior, &menor);
	if (c==0){
		printf("Valores ja ordenados.\nMaior: %d \nMenor: %d\n", maior,menor);
	}else{
		printf("Valores ordenados:\nMaior: %d \nMenor: %d\n", maior,menor);
	}
}

int ord(int *n1, int *n2){
	int aux;

	if (*n1 < *n2){
		aux = *n1;
		*n1=*n2;
		*n2=aux;
		return (1);
	}else{
		return(0);
	}
}
