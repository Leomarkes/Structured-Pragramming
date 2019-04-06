#include <stdio.h>
#include <string.h>

void main(){
	char frase[80];
	int v=0,c=0,i,j,n;

	do{
		printf("Digite o numero de frases que serao analisadas: ");
		scanf("%d", &n);
	}while(n<1 || n>1000);
	for(i=0;i<n;i++){
			printf("Digite a frase numero %d: ", (i+1));
			setbuf(stdin,NULL);
			fgets(frase,79,stdin);
			for(j=0;j<strlen(frase);j++){
				if((frase[j]>96) && (frase[j]<123)){
					if(frase[j]== 'a' || frase[j]== 'e' || frase[j]== 'i' || frase[j]== 'o' || frase[j]== 'u')
						v++;
					else
						c++;
				}
			}
		printf("%d %d \n", v, c);
		v=0;
		c=0;
	}
}