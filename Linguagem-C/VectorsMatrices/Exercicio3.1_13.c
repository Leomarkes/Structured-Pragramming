#include <stdio.h>
#include <string.h>

void main(){

	char var[20];
	int c;

	printf("Digite o nome do arquivo .gif:\n");
	setbuf(stdin,NULL);
	fgets(var,20,stdin);

	for(c=0;c<strlen(var);c++){
		if(var[c]=='.'){
			var[c+1]-=5;
			var[c+2]+=4;
			var[c+3]+=10;
		}
	}
	for(c=0;c<strlen(var);c++){
		printf("%c",var[c]);
	}
	printf("\n");
}