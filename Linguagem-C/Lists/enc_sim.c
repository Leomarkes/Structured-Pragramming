#include<stdio.h>
#include<stdlib.h>

typedef struct Bloco{
	int dado;
	struct Bloco *prox;
}Nodo;

//funções auxiliares

void inicializa_lista(Nodo **N){ //inicializa a lista
	*N = NULL;
}

Nodo * Cria_Nodo(){ //aloca memória para o nodo
	Nodo *p;

	p = (Nodo *) malloc(sizeof(Nodo));
 	if(!p){
 		printf("Problema de alocação");
 		exit(0);
 	}
 	return p;
}



// 1 -

void insere_inicio_lista(Nodo **N, int dado){
	Nodo *novo;

 	novo = Cria_Nodo();
 	novo->dado = dado;
 	novo->prox = *N;
 	*N = novo;
}

// 2 -

void insere_fim_lista(Nodo **N, int dado){
	Nodo *novo, *aux;

 	novo = Cria_Nodo( );
 	novo->dado = dado;
 	novo->prox = NULL;
 	if(*N == NULL)
 		*N = novo;
 	else{
		aux = *N;
 		while(aux->prox != NULL)
 		aux = aux->prox;
 		aux->prox = novo;
 	}
}


// 3 -

void insere_ordenado(Nodo **N, int dado){
	Nodo *novo, *aux, *aux2;

 	novo = Cria_Nodo( );
 	novo->dado = dado;
 	novo->prox = NULL;
 	if(*N == NULL)
 		*N = novo;
	else{
		if (novo->dado <= (*N)->dado)
		 	insere_inicio_lista(N, dado);
		else{
			for(aux = *N; aux != NULL; aux = aux->prox){
				if (novo->dado < aux->dado){
					novo->prox = aux;
					for (aux2 = *N; aux2 != NULL; aux2 = aux2->prox){
						if (aux2->prox == aux){
							aux2->prox = novo;
							break;
						}
					}
					break;
				}
				if (aux->prox == NULL && novo->dado > aux->dado)
					insere_fim_lista(N, dado);
			}
		}
	}
}

// 4 -

int remove_inicio_lista(Nodo **N, int *dado){
	Nodo *aux;

 	if(*N == NULL) //verifica se a lista está vazia
 		return 0;
 	else{
		*dado = (*N)->dado;
 		aux = (*N)->prox;
 		free(*N);
 		*N = aux;
 	}
 	return 1;
}


// 5 -

int remove_fim_lista(Nodo **N, int *dado){
	Nodo *aux;

	if(*N == NULL) //verifica se a lista está vazia
 		return 0;
 	else{
 		if((*N)->prox == NULL){
 			remove_inicio_lista(N, dado);
 		}else{
			for(aux = *N; aux != NULL; aux = aux->prox){
				Nodo *aux2 = aux->prox;
				if (aux2->prox == NULL){
					aux->prox = NULL;
					*dado = aux2->dado;
					free(aux2);
				}
			}
			return 1;
		}
	}
}



// 6 -

int remove_elem_lista(Nodo **N, int dado){
	Nodo *aux, *aux2;

	if(*N == NULL) //verifica se a lista está vazia
		return 0;
	else{
		if((*N)->dado == dado){
			aux = *N;
			*N = (*N)->prox;
	 		free(aux);
			return 1;
		}else{
			for(aux = *N; aux != NULL; aux = aux->prox){
				if (aux->dado == dado){
					for(aux2 = *N; aux2 != NULL; aux2 = aux2->prox){
						if (aux2->prox == aux){
							aux2->prox = aux->prox;
							free(aux);
							return 1;
						}
					}
				}
			}		
		}
		return -1;
	}
}

// 7 -

int busca_lista_encadeada(Nodo *N, int dado){
	int achou = 0;
	Nodo *aux;

	if(N == NULL)
 		printf("\n A lista está vazia!!");
 	else{
 		for(aux = N; aux != NULL; aux = aux->prox){
 			if(aux->dado==dado){
 				achou = 1;
 				break;
 			}
 		}
 	}
 	if(achou)
 		return 1;
 	return 0;
}



// 8 -

void imprime_lista_encandeada(Nodo *N){
	Nodo *aux;

 	if(N == NULL)
 		printf("\n A lista está vazia!!");
 	else{
 		for(aux = N; aux != NULL; aux = aux->prox)
 			printf("\n%d", aux->dado);
 	}
}


void main(){

 	Nodo *v;
 	int op, valor, r;
 	inicializa_lista(&v);

	do{
		do{
			printf("\n\nEscolha uma opcao:\n1) Insercao no inicio.\n2) Insercao no final.\n3) Insere ordenada.\n4) Exclui do inicio.\n5) Exclui do final.\n6) Exclui determinado.\n7) Busca na lista.\n8) Imprime lista.\n9) Sair.\n");
			scanf("%d", &op);
		}while(op<1 || op>9);
		switch(op){
			case 1:
				printf("\nInforme o valor a ser inserido no inicio da lista:");
 				scanf("%d", &valor);
 				insere_inicio_lista(&v, valor);
 				break;
			case 2:
				printf("Informe o valor a ser inserido no final da lista:");
 				scanf("%d", &valor);
 				insere_fim_lista(&v, valor);
 				break;
			case 3:
				printf("Informe o valor a ser inserido na lista:");
				scanf("%d", &valor);
				insere_ordenado(&v, valor);
				break;
			case 4:
				if(remove_inicio_lista(&v, &valor) == 0)
 					printf("A lista está vazia!!");
 				else
 					printf("O valor excluido do inicio da lista foi: %d", valor);
 				break;
			case 5:
				if(remove_fim_lista(&v, &valor) == 0)
					printf("A lista está vazia!!\n");
				else
					printf("O valor excluido do fim da lista foi: %d\n", valor);
				break;
			case 6:
				printf("O valo a ser excluído:\n");
				scanf("%d", &valor);
				r = remove_elem_lista(&v, valor);
				if(r == 0)
					printf("A lista está vazia!!\n");
				else if(r==-1)
					printf("Elemento nao encontrado.\n");
				else
					printf("Elemento excluído\n");
				break;
			case 7:
				printf("Informe o valor a ser buscado: \n");
				scanf("%d", &valor);
				if (busca_lista_encadeada(v, valor))
					printf("Elemento %d encontrado.\n", valor);
				else
					printf("Elemento nao encontrado.\n");
				break;
			case 8:
				imprime_lista_encandeada(v);
				break;
			case 9:
				exit(0);
		}
	}while(1==1);
}
