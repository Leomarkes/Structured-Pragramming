#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *arq, *arq2;
	int i,j, k, l, c, n, la, ca;
	int *M;

	if((arq=fopen("matrix.txt","r"))==NULL){
		printf("Erro.\n");
		exit(0);
	}
	fscanf(arq,"%d %d %d", &l, &c, &n);
	M=(int*)malloc(sizeof(int)*l*c);
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			*(M+(i*c+j))=1;
		}	
	}
	for(k=0;k<2;k++){
		fscanf(arq,"%d %d",&la,&ca);
		*(M+(la*c+ca))=0;		
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%d ", *(M+(i*c+j)));
		}
		printf("\n");
	}
	if((arq2=fopen("matrixsa.txt","w"))==NULL){
		printf("Erro.\n");
		exit(0);
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			fprintf(arq2,"%d ", *(M+(i*c+j)));
		}
		fprintf(arq2,"\n");
	}
}