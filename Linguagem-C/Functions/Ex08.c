#include <stdio.h>

char * imc(float alt, float pes);

void main(){
	float altura, peso;

	printf("Digite a sua altura:\n");
	scanf("%f", &altura);
	printf("Digite o seu peso:\n");
	scanf("%f", &peso);
	printf("Segundo a tabela de IMC voce esta com: %s\n", imc(altura,peso));
}

char * imc(float alt, float pes){
	float imc;

	imc = pes/(alt*alt);

	if(imc<=18.5)
		return("Abaixo do peso");
	else if ((imc>18.5) && (imc<25))
		return("Peso normal");
	else if ((imc>24.9) && (imc<30))
		return("Sobrepeso");
	else if ((imc>29.9) && (imc<35))
		return("Obesidade grau I");
	else if ((imc>34.9) && (imc<40))
		return("Obesidade grau II");
	else if (imc<=40)
		return("Obesidade grau III");
}