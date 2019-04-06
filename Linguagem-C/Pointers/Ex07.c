#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compara(char *v);

void main(){
	char n[10];

	printf("Digite um numero:\n");
	setbuf(stdin,NULL);
	fgets(n,9,stdin);
	if(compara(n)==1){
		printf("O numero eh capicua.\n");
	}else if(compara(n)==0){
		printf("O numero nao eh capicua.\n");
	}
}

int compara(char *v){
	char vi[9],va[9];
	int c,i=0,d,e=0,j;

	d=strlen(v);
	d-=2;
	for(c=d;c>=0;c--){
		vi[i]=*(v+c);
		i++;
	}
	for(j=0;j<=d;j++){
		if(vi[j]!=*(v+j))
			e=1;
	}
	if(e==0){
		return(1);
	}else
		return(0);
}