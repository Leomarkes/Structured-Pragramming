#include <stdio.h>
#include <stdlib.h>

void main(){

	int v[10]={7,5,12,10,2,-6,9,1,0,-3},c,i,x,s=0,ma,me,pa,pe,v2[10],y;
	int op;

	printf("Escolha uma opção:\n1)Procurar um numero no vetor.\n2)Encontrar o maior e o menor no vetor.\n3)Ver numeros pares e impares do vetor\n4)Soma dos valores.\n5)Soma dos valores positivos.\n6)Soma dos valores negativos.\n7)Elementos comuns aos 2 vetores.\n8)Sair.\n");
	scanf("%d",&op);
	switch(op){

	case 1:
	printf("Informe o número a ser procurado no vetor:");
	scanf("%d", &x);
	for(c=0;c<10;c++){
		if(x==v[c]){
			printf("Número encontrado na posição %d.\n\n", (c+1));
			s++;
		}
	}
	if(s==0)
		printf("O número não foi encontrado no vetor.\n\n");
	break;

	case 2:
	ma=v[0];
	me=v[0];
	for(c=0;c<10;c++){
		if(v[c]<me){
			me=v[c];
			pe=(c+1);
		}
		if(v[c]>ma){
			ma=v[c];
			pa=(c+1);
		}
	}
	printf("O maior número do vetor é %d e está na posição %d.\nO menor número do vetor é %d e está na posição %d.\n\n",ma,pa,me,pe);
	break;

	case 3:
	for(c=0;c<10;c++){
		if(v[c]%2==0)
			printf("Número %d = %d é par.\n",(c+1),v[c]);
		else
			printf("Número %d = %d é ímpar.\n",(c+1),v[c]);
	}
	printf("\n");
	break;

	case 4:
	s=0;
	for(c=0;c<10;c++){
		s=s+v[c];
	}
	printf("A soma dos valores do vetor é %d.\n\n",s);
	break;

	case 5:
	s=0;
	for(c=0;c<10;c++){
		if(v[c]>0)
			s=s+v[c];
	}
	printf("A soma dos valores positivos do vetor é %d.\n\n",s);
	break;

	case 6:
	s=0;
	for(c=0;c<10;c++){
		if(v[c]<0)
			s=s+v[c];
	}
	printf("A soma dos valores negativos do vetor é %d.\n\n",s);
	break;

	case 7:
	for(c=0;c<10;c++){
		v2[c]=rand()%10;
	}
	for(c=0;c<10;c++){
		for(i=0;i<10;i++){
			if(v[c]==v2[i]){
				printf("O elemento %d aparece nos dois vetores, nas posições %d e %d.\n",v[c],(c+1),(i+1));
			}
		}
	}
	break;

	case 8:
	break;
    }
}