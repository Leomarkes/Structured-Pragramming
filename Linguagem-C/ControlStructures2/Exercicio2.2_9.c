#include <stdio.h>
void main(){

	int op, c1=0, c2=0, b=0, n=0, c;

	printf("Digite os 20 votos (um de cada vez):");
	for(c=1; c<=20; c++){
		scanf("%d", &op);
		if(op==1)
			c1++;
		else if(op==2)
			c2++;
		else if(op==0)
			b++;
		else
			n++;
	}
	printf("Candidato 1: %d\nCandidato 2: %d\nBrancos: %d\nNulos: %d\n", c1, c2, b, n);
}