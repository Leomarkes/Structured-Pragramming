#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Velha{
	int partida;
	char JogVelha[3][3];
	char resultado;
}Partida;

void main(){
	FILE *pt, *pt2;
	Partida lt;
	int j=0;
	
	if((pt2 = fopen("Jogos.bin", "r+b")) == NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
 	}
	do{
		fread(&lt, 1, sizeof(Partida), pt2);
 		printf("%d\n", lt.partida);
 		printf("%c\n", lt.resultado);
 		for(int c=0;c<3;c++){
 			for(int i=0;i<3;i++){
 				printf("[%c]", lt.JogVelha[c][i]);
 			}
 			printf("\n");
 		}
 		j++;
 		printf("\n\n\n\n%d\n\n\n\n\n", j);
 	}while(j<3);
 	fclose(pt);
}