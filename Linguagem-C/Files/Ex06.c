#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
	FILE *arq;
	int *v,c,t,i;
	char bin[8]={'0','0','0','0','0','0','0','0'};

	printf("Digite o numero de digitos que serao gravados:\n");
	scanf("%d",&t);
	v=(int*)malloc(sizeof(int)*t);
	for(c=0;c<t;c++){
		do{
			printf("Digite o %d numero (menor que 256): ", (c+1));
			scanf("%d",&v[c]);
		}while(v[c]>255);
	}
	if((arq=fopen("arqnbin.txt","w+"))==NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
	}
	for(c=0;c<t;c++){
		i=7;
		while(v[c]>1){
			if(v[c]%2==1){
				bin[i]='1';
				v[c]=v[c]/2;
				i--;
			}else{
				bin[i]='0';
				v[c]=v[c]/2;
				i--;
			}
		}
		bin[i]='1';
		fprintf(arq,"%s\n",bin);
		for(int l=0;l<7;l++)
			bin[l]='0';
	}
	fclose(arq);
}