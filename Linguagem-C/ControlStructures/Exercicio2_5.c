#include <stdio.h>
void main(){

	float n1, n2, n3, m;

	printf("Digite a nota das 3 avaliaçoes (negativo para a terceira nao feita):");
	scanf("%f %f %f", &n1, &n2, &n3);
	if (n3>0){
		if (n1<n3){
			n1 = n3;
		}else if (n2<n3){
			n2 = n3;
		}
	}
	m = (n1+n2)/2;
	printf("A média das notas foi: %.2f", m);
}