#include <stdio.h>

int ver(int dado, char *cod);

void main(){
	int d, a;
	char c;

	printf("Digite o valor para verificacao:\n");
	scanf("%d", &d);
	a = ver(d,&c);
	if(a==0){
		printf("Verificacao confirmada (codigo): %c\n", c);
	}else{
		printf("Falha na verificacao (codigo): %c\n", c);
	}
}

int ver(int dado, char *cod){
	
	int v=25;

	if (dado*dado == v){
		*cod = '+';
		return(0);
	}else{
		*cod = '-';
		return(1);
	}
}