#include <stdio.h>

void main(){

	int v[15],t,a,c;

	for(c=0;c<15;c++){
		printf("Digite o %d elemento do vetor:\n",(c+1));
		scanf("%d", &v[c]);
	}

	do{
		t=0;
		for(c=0;c<14;c++){
			if(v[c]<v[c+1]){
				a=v[c];
				v[c]=v[c+1];
				v[c+1]=a;
				t=1;
			}
		}
	}while(t!=0);
	printf("O vetor em ordem descrescente:");
	for(c=0;c<15;c++){
		printf("%d ",v[c]);
	}
	printf("\n");
}