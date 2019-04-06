#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * crip(char *f);

void main(){
	char v[21],*f;
	int c;

	printf("Digite uma frase (maximo 20 caracteres) para ser criptografada:\n");
	setbuf(stdin,NULL);
	fgets(v,20,stdin);
	f = crip(v);
	printf("%s\n", f);
}

char * crip(char *f){
	int i,c=0,d;
	char * vet;

	vet=(char*)malloc(sizeof(char)*21);
	d=strlen(f);
	d-=2;
	for(i=d;i>=0;i--){
		vet[c]=*(f+i);
		c++;
	}
	for(i=0;i<d;i++){
		if(vet[i]!=65 && vet[i]!=69 && vet[i]!=73 && vet[i]!=79 && vet[i]!=85 && vet[i]!=32){
			vet[i]='#';
		}
	}
	return(vet);
}