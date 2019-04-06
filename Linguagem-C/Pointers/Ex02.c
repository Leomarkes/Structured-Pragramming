#include <stdio.h>

void comp(int a, int b, int c, int *ma, int *me);

void main(){
	int a, b, c, ma, me;

	printf("Digite tres numeros:\n");
	scanf("%d %d %d",&a,&b,&c);
	comp(a,b,c,&ma,&me);
	printf("O maior eh %d e o menor eh %d\n", ma, me);
}

void comp(int a, int b, int c, int *ma, int *me){
	*ma=a;
	*me=a;

	if(a>b)
		*me=b;
	if(b>c && a>c)
		*me=c;
	if(a<b)
		*ma=b;
	if(b<c && a<c)
		*ma=c;
}