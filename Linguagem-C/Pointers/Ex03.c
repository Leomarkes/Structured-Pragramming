#include <stdio.h>
#include <stdlib.h>

int soma(int x);

void main(){
	int x,s;

	do{
		printf("Digite o numero ou 0 para encerrar:\n");
		scanf("%d",&x);
		if(x==0)
			exit(0);
		else{
			s=soma(x);
			printf("%d\n", s);
		}
	}while(x!=0);
}

int soma(int x){
	int i,s=0;

	for(i=0;i<=x;i++){
		s+=i;
	}
	return(s);
}