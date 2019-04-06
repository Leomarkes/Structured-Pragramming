#include <stdio.h>
#include <string.h>

void min(char *fra);

void main(){
	char frase[50];

	printf("Digite uma frase:\n");
	setbuf(stdin,NULL);
	fgets(frase,49,stdin);
	min(&frase[0]);
	printf("A frase minuscula:\n");
	for (int c=0;c<strlen(frase);c++){
		printf("%c", frase[c]);
	}
}

void min(char *fra){
	for(int c=0; c<50; c++){
		if ((*(fra + c) < 91) && (*(fra + c) > 64)){
			*(fra+c)=*(fra+c)+32;
		}
	}
}