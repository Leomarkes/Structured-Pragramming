#include <stdio.h>
void main(){

	float n1, n2, m;

	printf("Digite duas notas:");
	scanf("%f %f", &n1, &n2);
	m = (n1+n2)/2;
	if(m>=70){
		printf("Aprovado. Média: %.2f\n", m);
	}else if(40<=m<70){
		printf("Exame. Média: %.2f\n", m);
	}else{
		printf("Reprovado. Média: %.2f\n", m);
	}
}