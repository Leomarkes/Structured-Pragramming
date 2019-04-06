#include <stdio.h>
#include <string.h>

void cabecalho(char *n);

void main(){
	char nome[30];

	printf("Digite o nome que aparecera no cabecalho:\n");
	setbuf(stdin,NULL);
	fgets(nome,29,stdin);
	cabecalho(nome);
}

void cabecalho(char *n){
	printf("============================================\n");
	printf("UFMG – Universidade Federal de Minas Gerais \n");
	printf("ICEx – Instituto de Ciências Exatas\n");
	printf("Disciplina de Programação de Computadores\n");
	printf("Nome: %s", n);
	printf("============================================\n");
}