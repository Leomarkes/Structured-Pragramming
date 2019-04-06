#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  float dado;
  int lin, col;
  struct Nodo *prox;
}ME;

void inicializa_lista(ME **N){ //inicializa a lista
	*N = NULL;
}

ME * Cria_Nodo(){ //aloca memória para o nodo
	ME *p;

	p = (ME *) malloc(sizeof(ME));
 	if(!p){
 		printf("Problema de alocação");
 		exit(0);
 	}
 	return p;
}

float busca_lista_encadeada(ME *N, int l, int c){
	ME *aux;

	if(N == NULL)
 		printf("\n A lista está vazia!!");
 	else{
 		for(aux = N; aux != NULL; aux = aux->prox){
 			if(aux->lin == l && aux->col == c){
        return aux->dado;
      }
 		}
    return 0;
 	}
}

void insere_fim_lista_enc(ME **N, float dado, int lin, int col){
	ME *novo, *aux;

 	novo = Cria_Nodo();
 	novo->dado = dado;
  novo->lin = lin;
  novo->col = col;
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

void adicao(ME *N, ME *N2, ME **res, int lin, int col, char s){
  int i, j;
  float add, dado1, dado2;

  for(i=0; i<lin;i++){
    for(j=0; j<col; j++){
      dado1 = busca_lista_encadeada(N, i, j);
      dado2 = busca_lista_encadeada(N2, i, j);
      if(dado1 != 0 && dado2 != 0){
        if(s=='+')
          add = dado1 + dado2;
        else
          add = dado1 - dado2;
        insere_fim_lista_enc(res, add, i, j);
      }else if(dado1 != 0){
        insere_fim_lista_enc(res, dado1, i, j);
      }else if(dado2 != 0){
        if(s=='-')
          add = dado2*(-1);
        else
          add = dado2;
        insere_fim_lista_enc(res, add, i, j);
      }
    }
  }
}

void multiplicacao(ME *N, ME *N2, ME **res, int lin, int col, int lin2, int col2){
  int i, j, z, y;
  float mult = 0, soma = 0;
  ME *aux, *aux2;

  for(i=0;i<lin;i++){
    y=0;
    while(y<col2){
      j=0;
      while(j<col){
        z=j;
        for(aux = N; aux != NULL; aux = aux->prox){
          if(aux->lin==i && aux->col==j){
					  for(aux2 = N2; aux2 != NULL; aux2 = aux2->prox){
              if(aux2->lin==z && aux2->col==y){
                mult = (aux->dado) * (aux2->dado);
                soma+=mult;
                break;
              }
            }
            break;
          }
        }  
        j++;
      }
      insere_fim_lista_enc(res, soma, i, y);
      soma = 0;
      mult = 0;
      y++;
    }
  }
}

void transposta(ME *N, int lin, int col){
  int i, j, e;
  ME *aux;

  for(j=0; j<lin; j++){
    for(i=0;i<col;i++){
      e = 0;
      for(aux = N; aux != NULL; aux = aux->prox){
 			  if(aux->lin==i && aux->col==j){
 				  printf("%.2f ", aux->dado);
          e = 1;
 				  break;
        }
 			}
      if(e==0)
        printf("0.00 ");
    }
    printf("\n");
  }
  printf("\n");
}

void diagonal(ME *N, int lin, int col){
  int i, j, e;
  float dado;
  ME *aux;

  for(i=0;i<lin;i++){
    for(j=0; j<col; j++){
      if(i==j){
        dado = busca_lista_encadeada(N, i, j);
        if (dado == 0){
          printf("0.00 ");
        }else{
          printf("%.2f ", dado);
        }
      }else{
        printf("   ");
      }
    }
    printf("\n");
  }
  printf("\n");
}



void imprime_lista_encandeada(ME *N, int lin, int col){
	ME *aux;
  int i, j, e;

 	if(N == NULL)
 		printf("\n A lista está vazia!!");
 	else{
    for(i=0;i<lin;i++){
      for(j=0; j<col; j++){
        e = 0;
        for(aux = N; aux != NULL; aux = aux->prox){
 			    if(aux->lin==i && aux->col==j){
 				    printf("%.2f ", aux->dado);
            e = 1;
 				    break;
           }
 			  }
        if(e==0)
          printf("0.00 ");
      }
      printf("\n");
    }
    printf("\n");
  }  
}

void main(){
  ME *matriz1, *matriz2, *res;
  int tl1, tc1, tl2, tc2, i, j, op;
  float dado, valor;
  char s;


  inicializa_lista(&matriz1);
  inicializa_lista(&matriz2);

  printf("Digite quantas linhas tem a primeira matriz: ");
  scanf("%d", &tl1);
  printf("Digite quantas colunas tem a primeira matriz: ");
  scanf("%d", &tc1);

  for(i=0; i<tl1; i++){
    for(j=0; j<tc1; j++){
      printf("Digite o elemento da linha %d e coluna %d: ", (i+1), (j+1));
      scanf("%f", &dado);
      if(dado!=0){
        insere_fim_lista_enc(&matriz1, dado, i, j);
      }
    }
  }

  printf("Digite quantas linhas tem a segunda matriz: ");
  scanf("%d", &tl2);
  printf("Digite quantas colunas tem a segunda matriz: ");
  scanf("%d", &tc2);
  
  for(i=0; i<tl1; i++){
    for(j=0; j<tc1; j++){
      printf("Digite o elemento da linha %d e coluna %d: ", (i+1), (j+1));
      scanf("%f", &dado);
      if(dado!=0){
        insere_fim_lista_enc(&matriz2, dado, i, j);
      }
    }
  }

  do{
    do{
      printf("1 - Adicao\n2 - Subtracao\n3 - Multiplicacao\n4 - Transposta\n5 - Diagonal Principal\n6 - Busca\n7 - Impressao\n8 - Sair\n");
      scanf("%d", &op);
    }while(op<0 && op>8);
    switch(op){
      case 1:
        if(tl1 != tl2 || tc1!=tc2){
          printf("Dimensoes incompativeis!");
          break;
        }else{
          inicializa_lista(&res);
          s = '+';
          adicao(matriz1, matriz2, &res, tl1, tc1, s);
          imprime_lista_encandeada(res, tl1, tc1);
          free(res);
          break;
        }
      case 2:
        if(tl1 != tl2 || tc1!=tc2){
          printf("Dimensoes incompativeis!");
          break;
        }else{
          inicializa_lista(&res);
          s = '-';
          adicao(matriz1, matriz2, &res, tl1, tc1, s);
          imprime_lista_encandeada(res, tl1, tc1);
          free(res);
          break;
        }
      case 3:
        if(tl1 != tc2){
          printf("Dimensoes incompativeis!");
          break;
        }else{
          inicializa_lista(&res);
          multiplicacao(matriz1, matriz2, &res, tl1, tc1, tl2, tc2);
          imprime_lista_encandeada(res, tl1, tc1);
          free(res);
          break;
        }
      case 4:
        transposta(matriz1, tl1, tc1);
        transposta(matriz2, tl2, tc2);
        break;
      case 5:
        diagonal(matriz1, tl1, tc1);
        diagonal(matriz2, tl2, tc2);
        break;
      case 6:
        
      case 7:
        imprime_lista_encandeada(matriz1, tl1, tc1);
        imprime_lista_encandeada(matriz2, tl2, tc2);
        break;
      case 8:
        exit(0);
    }
  }while(1==1);
}