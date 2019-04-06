#include <stdio.h>
void main(){

	int c;
	float vtot, ntot, s=0, v, d=0;

	printf("Digite o lote total e o numero de cheques:");
	scanf("%f %f", &vtot, &ntot);
	printf("Digite o valor de cada cheque separamente:");
	for (c=1;c<=ntot;c++){
		scanf("%f", &v);
		s = s + v;
	}
	d = s - vtot;
	if (d==0){
		printf("LOTE OK.");
	}else{
		printf("Lote errado. Diferença (soma calculada - soma informada): %.2f",d);
	}
}