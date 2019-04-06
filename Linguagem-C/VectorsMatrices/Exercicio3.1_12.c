#include <stdio.h>
#include <ctype.h>

void main(){

	char nome[100];
	char l=' ';
	int c,a,v,cs,b;

	printf("Digite o seu nome completo:");
	setbuf(stdin,NULL);
	fgets(nome,100,stdin);

	for(c=0;c<100;c++){
		if(((nome[c]>122) || (nome[c]<65)) && ((nome[c+1]>122) || (nome[c+1]<65)))
			break;
		if(nome[c]!=' ')
			a++;
	}	
	printf("Seu nome tem %d caracteres.\n", a);

	for(c=0;c<100;c++){
		if(((nome[c]>122) || (nome[c]<65)) && ((nome[c+1]>122) || (nome[c+1]<65)))
			break;
		if(nome[c]==' ')
			b++;
		else if(toupper(nome[c])=='A' || toupper(nome[c])=='E' || toupper(nome[c])=='I' || toupper(nome[c])=='O' || toupper(nome[c])=='U')
			v++;
		else
			cs++;
	}	
	printf("Seu nome tem %d espaços, %d vogais e %d consoantes.\n",b,v,cs);

	for(c=0;c<100;c++){
		if(((nome[c]>122) || (nome[c]<65)) && ((nome[c+1]>122) || (nome[c+1]<65)))
			break;
		if(nome[c]==' ')
			b++;
		else if(toupper(nome[c])=='A' || toupper(nome[c])=='E' || toupper(nome[c])=='I' || toupper(nome[c])=='O' || toupper(nome[c])=='U')
			v++;
		else
			printf("%c",nome[c]);
	}
	printf("\n");	

	printf("Digite uma letra para ser substituida: \n");
	setbuf(stdin,NULL);
	scanf("%c",&l);
	l=toupper(l);
	for(c=0;c<100;c++){
		if(((nome[c]>122) || (nome[c]<65)) && ((nome[c+1]>122) || (nome[c+1]<65))){
			if(nome[c]==42){
				continue;
			}else
				break;
		}
		if(toupper(nome[c])==l)
			nome[c]='*';
	}
	for(c=0;c<100;c++){
		if(((nome[c]>122) || (nome[c]<65)) && ((nome[c+1]>122) || (nome[c+1]<65))){
			if(nome[c]==42){
				printf("%c",nome[c]);
				continue;
			}
			else
				break;
		}
		printf("%c",nome[c]);
	}
	printf("\n");
}