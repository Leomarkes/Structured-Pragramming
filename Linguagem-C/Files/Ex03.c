#include <stdlib.h>
#include <stdio.h>

void main(){

	FILE *pt;
	char ch;

	if((pt=fopen("arquivo.bin","r"))==NULL){
		printf("O arquivo nao pode ser aberto!\n");
		exit(0);
	}

	do{
		puts(pt);
	}while(!feof(pt));
	fclose(pt);
}