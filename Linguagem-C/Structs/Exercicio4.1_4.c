#include <stdio.h>

void main(){

	typedef struct prod
	{
		char nome[15];
		int cod,qtde;
		float preco;
	}produto;

	produto produtos[5];
	int cod2,qtde2,c,a=0;

	for(c=0;c<5;c++){
		produtos[c].cod=c;
		printf("Digite o nome, preço e quantidade do produto:\n");
		setbuf(stdin,NULL);
		fgets(produtos[c].nome,15,stdin);
		scanf("%f",&produtos[c].preco);
		scanf("%d",&produtos[c].qtde);
	}
	do{
		printf("Digite o codigo e a quantidade do produto a ser comprado (codigo 0 para encerrar):\n");
		scanf("%d",&cod2);
		scanf("%d",&qtde2);
		cod2=cod2-1;
		for(c=0;c<5;c++){
			if(cod2==produtos[c].cod){
				a=0;
				break;
			}else
				a=1;
		}
		if(a==1){
			printf("Produto inexistente.\n");
		}else if(qtde2<=produtos[cod2].qtde){
			printf("Compra efetuada com sucesso!\n");
			produtos[cod2].qtde=produtos[cod2].qtde-qtde2;
		}else if(qtde2>=produtos[cod2].qtde)
			printf("Estoque insuficiente\n");
	}while(cod2>=0);
}