#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
	FILE *arq, *arq2, *arq3;
	char frase[30],frase2[30],frase3[30];
	int t,c,d,nlinhas=0,i=0,e;

	if((arq=fopen("arquivo7.txt","r+"))==NULL){
		printf("O arquivo nao pode ser aberto!");
		exit(0);
	}
	if((arq2=fopen("arquivo7sa.txt","w+r"))==NULL){
		printf("O arquivo nao pode ser aberto!");
		exit(0);
	}
	if((arq3=fopen("arquivo7sa2.txt","w+r"))==NULL){
		printf("O arquivo nao pode ser aberto!");
		exit(0);
	}
	while(fgets(frase,30,arq)){
		t=strlen(frase);
		t=t-2;
		d=(t+1);
		for(c=0;c<d;c++){
			frase2[c]=frase[t];
			t--;
		}
		frase2[c]='\0';
		fprintf(arq2, "%s\n", frase2);
		nlinhas++;
	}
	nlinhas--;
	e=(nlinhas+2);
	for(c=nlinhas;c>=0;c--){
		rewind(arq2);
		//e eh o numero da linha do arquivo2. Decrementa a cada vez que uma linha eh copiada pro arquivo3
		e--;
		while(fgets(frase3,30,arq2)){
			//i eh o contador de linhas do arquivo2
			i++;
			//quando as duas forem iguais (comeca na ultima linha) copia
			if(i==e){
				fprintf(arq3, "%s", frase3);
			}
		}
		i=0;
	}
	fclose(arq);
	fclose(arq2);
	fclose(arq3);
}