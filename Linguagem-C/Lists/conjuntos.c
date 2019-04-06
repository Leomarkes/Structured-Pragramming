#include <stdio.h>
#include <stdlib.h>

typedef struct Bloco{
	int dado;
	struct Bloco *prox;
}Nodo;

typedef struct Vetor{
	int *dados;
	int inicio, fim, elemT;
}Tipo_Lista;

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

void insere_inicio_lista_enc(Nodo **N, int dado){
	Nodo *novo;

 	novo = Cria_Nodo();
 	novo->dado = dado;
 	novo->prox = *N;
 	*N = novo;
}


void insere_fim_lista_enc(Nodo **N, int dado){
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

int insere_ordenado_din(Tipo_Lista *v, int dado){
	int i, ch, a;

	if(v->fim < v->elemT){
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

void insere_ordenado_enc(Nodo **N, int dado){
	Nodo *novo, *aux, *aux2;

 	novo = Cria_Nodo( );
 	novo->dado = dado;
 	novo->prox = NULL;
 	if(*N == NULL)
 		*N = novo;
	else{
		if (novo->dado <= (*N)->dado)
		 	insere_inicio_lista_enc(N, dado);
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
					insere_fim_lista_enc(N, dado);
			}
		}
	}
}

int busca_lista_din(Tipo_Lista v, int dado){
	int i, achou = 0;

	for(i=0; i < v.fim-1; i++){
		if(v.dados[i] == dado){
 			achou = 1;
 			break;
 		}
 	}
 	if(achou)
 		return 1;
 	return 0;
}

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
  Tipo_Lista A,B;
  int valor;
  Nodo *r;
 	inicializa_lista(&r);

	printf("Digite o número de elementos que a lista A terá: \n");
	scanf("%d", &A.elemT);

	A.dados = malloc(sizeof(int)*A.elemT);
	A.inicio = 0;
	A.fim = 0;

  for(int i=0; i<A.elemT;i++){
    printf("Digite o %d elemento:", i+1);
    scanf("%d", &valor);
    insere_ordenado_din(&A, valor);
  }

  printf("Digite o número de elementos que a lista B terá: \n");
	scanf("%d", &B.elemT);

	B.dados = malloc(sizeof(int)*B.elemT);
	B.inicio = 0;
	B.fim = 0;

  for(int i=0; i<B.elemT;i++){
    printf("Digite o %d elemento:", i+1);
    scanf("%d", &valor);
    insere_ordenado_din(&B, valor);
  }

  printf("\n\nINTERSECCAO:\n\n");
	for(int i=0; i < A.fim; i++){
 		if(busca_lista_din(B, A.dados[i])==1){
      insere_ordenado_enc(&r, A.dados[i]);
    }
  }
  imprime_lista_encandeada(r);
  free(r);
  inicializa_lista(&r);

  printf("\n\nUniao:\n\n");
  for(int i=0; i < A.fim; i++){
    insere_ordenado_enc(&r, A.dados[i]);
  }
  for(int i=0; i < B.fim; i++){
 		if(busca_lista_din(A, B.dados[i])!=1){
      insere_ordenado_enc(&r, B.dados[i]);
    }
  }
  imprime_lista_encandeada(r);
  free(r);
  inicializa_lista(&r);

  printf("\n\nDiferenca:\n\n");
  for(int i=0; i < A.fim; i++){
 		if(busca_lista_din(B, A.dados[i])!=1){
      insere_ordenado_enc(&r, A.dados[i]);
    }
  }
  imprime_lista_encandeada(r);
  printf("\n\n");
  free(r);
}
