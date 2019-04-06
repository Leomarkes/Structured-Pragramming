#include <stdio.h>
#include <string.h>

int cmp(char *fra, char c);

void main(){
	char letra, frase[50];
	int n;

	printf("Digite a frase:\n");
	setbuf(stdin,NULL);
	fgets(frase,49,stdin);
	printf("Digite a letra:\n");
	setbuf(stdin,NULL);
	scanf("%c", &letra);
	n = cmp(&frase[0],letra);
	printf("Numero de ocorrencias da letra na frase: %d\n", n);
}

int cmp(char *fra, char c){
	int n=0,i;

	for (i=0;i<50;i++){
		if ( *(fra + i) == c)
			n++;
	}
	return(n);
}