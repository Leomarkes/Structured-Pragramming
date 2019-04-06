#include <stdio.h>

float ler_num();
float calculo(float q, float valor, float *d);

int main(void)
{
	float quant, unitario, final, desc;
 
 	printf("Quantidade vendida: ");
 	quant = ler_num();
 	printf("Preco unitario: ");
 	unitario = ler_num();
 	final = calculo(quant, unitario, &desc);
 	printf("Valor a pagar: R$ %.2f\n", final);
 	printf("Desconto concedido: R$ %.2f\n", desc);
	return(0);
}

float ler_num(){
	float n;

	do{
		scanf("%f", &n);
	}while(n<=0);
	return(n);
}

float calculo(float q, float valor, float *d){
	float t;

	t = q*valor;
	(*d)=(t*0.1);
	t = t - (t*0.1);
	return(t);
}