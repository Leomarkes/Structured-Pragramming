#include <stdio.h>
#include <string.h>

void main(){

	char var[50],var2[50];
	int c,p,a=0;

	printf("Digite uma frase (Maximo 50 caracteres)\n");
	setbuf(stdin, NULL);
	fgets(var, 50, stdin);
	printf("Digite outra frase (Maximo 50 caracteres)\n");
	setbuf(stdin, NULL);
	fgets(var2, 50, stdin);

	for(c=0;c<(strlen(var));c++){
		if(var[c]!=var2[c]){
			p=(c+1);
			a=1;
			break;
		}
	}
	if(a==0)
		printf("Frases iguais.\n");
	else
		printf("A %d letra das frases sao diferentes.\n",p);
}