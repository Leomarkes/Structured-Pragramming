#include <stdio.h>
#include <stdlib.h>

int M[50][4];

void estoque();
int * estoque_total();
void relatorio();

void main(){
	int *p;

	printf("O estoque sera gerado.\n");
	estoque();
	printf("O estoque total sera atualizado.\n");
	p=estoque_total();
	printf("A verificacao de estoque baixo sera executada.\n");
	relatorio();
}

void estoque(){
	int i, c;

	for (c=0;c<50;c++){
		for (i=0;i<4;i++){
			M[c][i]=((2*i)+(3*(c+1)));
		}
	}
}

int * estoque_total(){
	int v[50],l,c,s=0;

	for(l=0;l<50;l++){
		for(c=0;c<4;c++){
			s+=M[l][c];
		}
		v[l]=s;
		s=0;
	}
}

void relatorio(){
	int l,c;

	for(l=0;l<50;l++){
		for(c=0;c<4;c++){
			if((M[l][c])<10){
				printf("Produto: %d\nLoja: %d\nEstoque: %d\n\n",(l+1),(c+1),M[l][c]);
			}
		}
	}
}