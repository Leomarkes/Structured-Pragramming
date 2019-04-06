#include <stdio.h>

void main(){
	int l, c, i, s=0;

	do{
		printf("Digite o numero de linhas e colunas do tabuleiro: ");
		scanf("%d %d", &l, &c);
		if(l%2==0)
			s=(l/2);
		else
			s=((l+1)/2);
		if(c%2==0)
			s= s*(c/2);
		else
			s= s*((c+1)/2);
		if(l==0 && c==0)
			break;
		printf("%d\n", s);
	}while(0<=l<=10000 && 0<=c<=10000);
}