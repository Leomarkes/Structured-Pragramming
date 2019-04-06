#include <stdio.h>
void main(){

	float n1, n2;
	char op;

	do{
		printf("Digite os valores para a operaçao:");
		scanf("%f %f", &n1, &n2);
		printf("Escolha uma opção: S(soma), P(produto), U(subtraçao), D(divisao) ou Q(sair):");
		scanf("%*c%c", &op);
		switch(op){
			case 'S':
				printf("A soma vale: %.2f\n", (n1+n2));	break;
			case 'P':
				printf("o produto vale: %.2f\n", (n1*n2)); break;
			case 'U':
				printf("A subtraçao vale: %.2f\n", (n1-n2)); break;
			case 'D':
				printf("A divisao vale: %.2f\n", (n1/n2)); break;
			case 'Q':
				break;
			default: printf("Opçao invalida.\n");
		};	
	}while(op!='Q');
}