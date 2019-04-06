#include <stdio.h>

int div(int x, int y);

void main(){
	int x,y,c;

	printf("Testador de divisibilidade\n\n");
	printf("Digite o primeiro numero:\n");
	scanf("%d",&x);
	printf("Digite o segundo numero:\n");
	scanf("%d",&y);
	c = div(x,y);
	if(c==1)
		printf("%d eh divisivel por %d\n",x,y);
	else
		printf("%d nao eh divisivel por %d\n",x,y);
}

int div(int x, int y){

	if(x%y==0)
		return(1);
	else
		return(0);
}