#include <stdio.h>
#include <stdlib.h>

void main(){

	FILE *pt;

	if((pt = fopen("arquivo.bin", "w+b")) == NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
 	}
 	for(int c=0;c<100;c++){
 		fprintf(pt,"%d\n",(c+1));
 	}
}