#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
	typedef struct Alunos{
		char nome[40];
		float ira;
	}alu;

	int tam,c,e,t;
	alu *aluno,aux,aluno2;
	FILE *arq;

	printf("Digite quantos alunos há na turma:\n");
	scanf("%d", &tam);
	aluno=(alu*)malloc(sizeof(alu)*tam);

	for(c=0;c<tam;c++){
		printf("Digite o nome do %d aluno:\n", (c+1));
		setbuf(stdin,NULL);
		fgets(aluno[c].nome,39,stdin);
		setbuf(stdin,NULL);
		t=strlen(aluno[c].nome);
		aluno[c].nome[t-1]='\0';
		printf("Digite o IRA do %d aluno:\n", (c+1));
		scanf("%f",&aluno[c].ira);
	}
	c=0;
	do{
		e=0;
		for(c=0;c<(tam-1);c++){
			if((strcmp(aluno[c].nome,aluno[c+1].nome)>0)){
				aux=aluno[c];
				aluno[c]=aluno[c+1];
				aluno[c+1]=aux;
				e=1;
				break;
			}
		}
	}while(e!=0);

	if((arq=fopen("Alunos.txt","w"))==NULL){
		printf("Problemas no arquivo!\n");
		exit(0);
	}
	/*if((arq=fopen("Alunos.dat","w+b"))==NULL){
		printf("Problemas no arquivo!\n");
		exit(0);
	}*/
	for(c=0;c<tam;c++){
		fwrite(&aluno[c],1,sizeof(alu),arq);
	}
	fclose(arq);
	
	if((arq=fopen("Alunos.txt","r"))==NULL){
		printf("Problemas no arquivo!\n");
		exit(0);
	}
	/*if((arq=fopen("Alunos.dat","r+b"))==NULL){
		printf("Problemas no arquivo!\n");
		exit(0);
	}*/
	while(!feof(arq)){
		if((int*)(fread(&aluno2,1,sizeof(alu),arq))!=NULL){
			printf("%s %.2f\n",aluno2.nome,aluno2.ira);
		}
	}
	fclose(arq);
}