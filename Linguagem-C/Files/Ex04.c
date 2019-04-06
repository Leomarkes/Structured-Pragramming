#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
	FILE *arq;
	char a[49];
	int c=0;

	if((arq=fopen("Ex04.c","r+b"))==NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
	}
	while(fgets(a,50,arq)){
		printf("%d: %s \n", (c+1),a);
		c++;
	}
	fclose(arq);
}