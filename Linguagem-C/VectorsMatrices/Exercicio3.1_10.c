#include <stdio.h>
#include <string.h>

void main(){

	char var[40];
	int c;

	do{
		printf("Digite uma frase (Maximo 40 caracteres)\n");
		setbuf(stdin, NULL);
		scanf("%[^\n]s",var);
		if (strlen(var)>40)
			printf("Frase com mais que 40 caracteres. Digite novamente:");
	}while(strlen(var)>40);

	for(c=0;c<strlen(var);c++){
		printf("%c\n",var[c]);
	}
}