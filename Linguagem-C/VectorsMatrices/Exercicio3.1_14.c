#include <stdio.h>
#include <string.h>

void main(){

	char var[80];
	int c,d=5,a=1,e=0,i=0;

	printf("Digite uma frase de no máximo 80 caracteres:");
	setbuf(stdin,NULL);
	fgets(var,80,stdin);

	do{
		a=1;
		for(c=e;c<d;c++){
			if(((var[c]>122) || (var[c]<65)) && ((var[c+1]>122) || (var[c+1]<65)))
				break;
			if(var[c]!=' '){
				var[c]=var[c]+a;
				a++;
			}else{
				d++;
				e++;
			}
		}
		d+=5;
		e+=5;
	}while(d<=strlen(var)+4);

	for(c=0;c<strlen(var);c++){
		if(var[c]!=' '){
			printf("%c",var[c]);
		}
	}
	printf("\n");
}