#include <stdio.h>
#include <stdlib.h>

#define MAX_VETOR 5

typedef struct Vetor{
	int dados[MAX_VETOR];
	int inicio, fim;
}Tipo_Lista;

// 1-

int insere_fim_lista(Tipo_Lista *v, int dado){

 	if(v->fim < MAX_VETOR){
 		v->dados[v->fim] = dado;
 		(v->fim)++;
 		return 1;
 	}
 	return 0;
};

// 2-

int insere_inicio_lista(Tipo_Lista *v, int dado){
	int i;

	if(v->fim < MAX_VETOR){
		for(i=0; i <= v->fim; i++){
			v->dados[(v->fim)-i+1] = v->dados[(v->fim)-i];
		}
		v->dados[0] = dado;
		(v->fim)++;
		return 1;
	}
	return 0;
};

// 3-

int insere_ordenado(Tipo_Lista *v, int dado){
	int i, ch, a;

	if(v->fim < MAX_VETOR){
		if(v->fim == 0){
			v->dados[0] = dado;
			(v->fim)++;
		}else{
			for(i = (v->fim)-1; i>=0 ; i--){
				if(v->dados[i]>dado){
					v->dados[i+1] = v->dados[i];
					v->dados[i] = dado;
				}else{
					v->dados[i+1] = dado;
					break;
				}
			}
			(v->fim)++;
		}
		do{
			ch = 0;
			for(i=0; i < (v->fim)-1; i++){
				if(v->dados[i] > v->dados[i+1]){
					a = v->dados[i];
					v->dados[i] = v->dados[i+1];
					v->dados[i+1] = a;
					ch = 1;
				}
			}
		}while(ch==1);
		return 1;
	}
	return 0;
}


// 4-

int exclui_inicio_lista(Tipo_Lista *v, int *dado){
	int i;

	if(v->fim != 0){
		*dado = v->dados[0];
		for(i=0; i < (v->fim)-1 ; i++){
			v->dados[i] = v->dados[i+1];
		}
		(v->fim)--;
		return 1;
	}
	return 0;
};

// 5-

int exclui_fim_lista(Tipo_Lista *v, int *dado){

	if(v->fim != 0){
		*dado = v->dados[v->fim-1];
		(v->fim)--;
		return 1;
	}
	return 0;
};

// 6-

int exclui_elem_lista(Tipo_Lista *v, int indice){
	int i, dado;
 
	if(v->fim != 0){ //verifica se a lista está vazia
 		if((indice >=0) && (indice <= v->fim)){ //verifica se o indice está correto
 			if(indice == 0){ //verifica se exclui o primeiro elemento
 				if(exclui_inicio_lista(v, &dado)==1)
					printf("\nO elemento excluido da posicao %d foi: %d", indice, dado);
 				return 1;
 			}
			else{
 				if(indice == v->fim-1){ //verifica se exclui o ultimo elemento
 					if(exclui_fim_lista(v, &dado)==1)
 						printf("\nO elemento excluido da posicao %d foi: %d", indice, dado);
 					return 1;
 				}
 				else{
 					dado = v->dados[indice];
 					for(i=indice; i < v->fim; i++)
 						v->dados[i] = v->dados[i+1];
 					(v->fim)--;
 					printf("\nO elemento excluido da posicao %d foi: %d", indice, dado);
 					return 1;
 				}
 			}
 		}
 		return -1;
 	}
 	return 0;
};

// 7-

int imprime_lista(Tipo_Lista V){
	int i;
 
	printf("\n\n\n");
	if(V.fim != 0){
 		for(i=0; i < V.fim; i++)
 			printf("\n%d", V.dados[i]);
 		return 1;
 	}
 	return 0;
};

// 8-

int busca_lista(Tipo_Lista v, int dado, int *indice){
	int i, achou = 0;
	
	for(i=0; i < v.fim; i++){
		if(v.dados[i] == dado){
 			*indice = i;
 			achou = 1;
 			break;
 		}
 	}
	if(achou)
 		return 1;
 	return 0;
};


void main(){

	Tipo_Lista v;
	int op, r, dado, indice;

	v.fim = 0;
	v.inicio = 0;

	do{
		do{
			printf("\n\nEscolha uma opcao:\n1) Insercao no final.\n2) Insercao no inicio.\n3) Insere ordenada.\n4) Exclui do inicio.\n5) Exclui do final.\n6) Exclui determinado.\n7) Imprime lista.\n8) Busca na lista.\n9) Sair.\n");
			scanf("%d", &op);
		}while(op<1 || op>9);
		switch(op){
			case 1:
				printf("Informe a lista e o dado a ser incluído:\n");
				scanf(" %d",  &dado);
				r = insere_fim_lista(&v, dado);
				break;
			case 2:
				printf("Informe a lista e o dado a ser incluído:\n");
				scanf(" %d",  &dado);
				r = insere_inicio_lista(&v, dado);
				break;
			case 3:
				printf("Informe a lista e o dado a ser incluído:\n");
				scanf(" %d",  &dado);
				r = insere_ordenado(&v, dado);
				break;
			case 4:
				//printf("Informe a lista:\n");
				//scanf("%a", &v);
				r = exclui_elem_lista(&v, 0);
				break;
			case 5:
				//printf("Informe a lista:\n");
				//scanf("%a", &v);
				r = exclui_elem_lista(&v, (v.fim-1));
				break;
			case 6:
				printf("Informe a lista e o índice:\n");
				scanf(" %d",  &dado);
				r = exclui_elem_lista(&v, (dado-1));
				break;
			case 7:
				//printf("Informe a lista:\n");
				//scanf("%a", &v);
				r = imprime_lista(v);
				break;
			case 8:
				printf("Informe a lista e o dado:\n");
				scanf(" %d",  &dado);
				r = busca_lista(v, dado, &indice);
				if (r==1){
					printf("O elemente %d está no índice %d.\n", dado, (indice+1));
				}
				break;
			case 9:
				exit(0);
		}
		if (r == 1){
			imprime_lista(v);
		}
		if (r == 0){
			printf("Lista vazia.\n");
		}
		if (r == -1){
			printf("Índice inválido.\n");
		}
	}while(1==1);
}