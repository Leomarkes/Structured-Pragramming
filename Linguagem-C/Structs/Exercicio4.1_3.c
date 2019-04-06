#include <stdio.h>

void main(){

	typedef struct carg
	{
		char nome[30];
		int cod;
		float salario;		
	}cargo;

	cargo cargos[17];
	int c,cod;
	char op;

	for(c=0;c<17;c++){
		cargos[c].cod=c;
		printf("Digite o nome e a remuneracao do cargo:\n");
		setbuf(stdin,NULL);
		fgets(cargos[c].nome,30,stdin);
		scanf("%f",&cargos[c].salario);
	}
	do{
		printf("Digite o codigo do cargo:");
		scanf("%d",&cod);
		cod=cod-1;
		if(cod<0 || cod>16)
			printf("Codigo inválido\n");
		else
			printf("Salario: %.2f Cargo: %s \n",cargos[cod].salario,cargos[cod].nome);
		printf("Deseja fazer nova consulta? (S/N)\n");
		scanf("%*c%c",&op);
	}while(op!='N');
}