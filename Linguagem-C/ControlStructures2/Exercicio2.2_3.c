#include <stdio.h>
void main(){

	int a, b, c, me, ma, ml=0;
	float dv=0;

	do{
		printf("Digite um valor para a, b e c (todos maiores que 0):");
		scanf("%d %d %d", &a, &b, &c);
	}while((a<=0) || (b<=0) || (c<=0));
	me = a;
	ma = a;
	if (b<me){
		me = b;
	}
	if(c<me){
		me = c;
	}
	if (b>ma){
		ma = b;
	}
	if (c>ma){
		ma = c;
	}
	ml = ma * me;
	dv = (float)ma/me;
	printf("O maior vezes o menor vale %d, e o maior dividido pelo menor vale %.2f.\n", ml, dv);
}