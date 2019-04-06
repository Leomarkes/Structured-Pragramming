#include <stdio.h>

void main(){
	int n, x, y, c, g, i;

	printf("Digite o numero de perguntas: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		do{
			printf("Digite o numero de cabecas e o numero de patas da %d pergunta: ",(i+1));
			scanf("%d %d",&x,&y);
		}while(0>=x || x>=500 || 2*x>=y>=4*x || y%2!=0);
		c=(y-2*x)/2;
		g=x-c;
		printf("%d %d \n", g, c);
	}
}