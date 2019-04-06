#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
	FILE *arq;
	char linha[50];
	int c=1;

	if((arq=fopen("arquivo2.txt","w+"))==NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
	}
	do{
		printf("Digite a %d linha:\n",c);
		setbuf(stdin,NULL);
		fgets(linha,49,stdin);
		fprintf(arq, "%s", linha);
		c++;
	}while(strcmp(linha,"FIM\n"));
	fclose(arq);
}