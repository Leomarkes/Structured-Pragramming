#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
	FILE *arq;
	char nome[30];
	int anos,c,t;

	if((arq=fopen("emp.txt","w+"))==NULL){
		printf("O arquivo nao pode ser aberto!");
		exit(0);
	}
	for(c=0;c<5;c++){
		printf("Digite o nome do %d funcionário:\n", (c+1));
		setbuf(stdin,NULL);
		fgets(nome,29,stdin);
		printf("Digite quantos anos o funcionário %d trabalhou:\n", (c+1));
		scanf("%d",&anos);
		t = strlen(nome);
		nome[t-1]='\0';
		fprintf(arq, "%s ", nome);
		fprintf(arq, "%d\n", anos);
	}
	rewind(arq);
	do{
		fscanf(arq, "%s %d", nome,&anos);
		printf("Funcionario %s \n", nome);
    	printf("Anos %d\n", anos);
    }while(!feof(arq));
    fclose(arq);
}