#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int copia(char *n1, char *n2, int x);

void main(){
	int a,tam;
	char *v,*n;

	printf("Digite o numero de caracteres:\n");
	scanf("%d",&tam);
	v=(char*)malloc(sizeof(char)*tam);
	printf("Digite a frase:\n");
	setbuf(stdin,NULL);
	fgets(v,tam,stdin);
	a=copia(v,n,tam);
	printf("%d\n", a);
}

int copia(char *n1, char *n2, int x){
	int c,d,i;

	for(c=0;c<x;c++){
		if(*(n1+c)==' '){
			d=c;
			break;
		}
	}
	n1-20;
	for(c=0;c<d;c++){
		*(n2+c)=*(n1+c);
	}
	*(n2+c)='\0';
	i=strlen(n2);
	return(i);
}