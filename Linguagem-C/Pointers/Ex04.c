#include <stdio.h>
#include <stdlib.h>

float media(int x, int *v);

void main(){
	int *v,x,c;
	float m;

	printf("Digite o numero de elementos a serem digitados:\n");
	scanf("%d",&x);
	v = (int*)malloc(sizeof(int)*x);
	for(c=0;c<x;c++){
		printf("Digite o %d numero:\n", (c+1));
		scanf("%d",&v[c]);
	}
	m=media(x,v);
	printf("%.2f\n", m);
}

float media(int x, int *v){
	int s=0,c;
	float m;

	for(c=0;c<x;c++)
		s+=v[c];
	m=(float) s/(float) x;
	return(m);
}