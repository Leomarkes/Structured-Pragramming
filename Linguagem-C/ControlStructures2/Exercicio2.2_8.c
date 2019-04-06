#include <stdio.h>
void main(){

	int n,c;

	printf("Digite um numero para ver a tabuada:");
	scanf("%d", &n);
	for(c=0;c<=10;c++){
	printf("%d x %d = %d\n", n,c,(n*c));
	}
}