#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){

	char var[100];
	int c;

	printf("Digite uma frase (Maximo 100 caracteres)\n");
	setbuf(stdin, NULL);
	fgets(var, 100, stdin);

	for(c=0;c<strlen(var);c++){
		if((var[c]==' ') && (var[c+1]==' '))
			break;
		else{	
			var[0]=toupper(var[0]);
			printf("%c",var[c]);
			if (var[c]==' ')
				var[c+1]=toupper(var[c+1]);
		}	
	}
}