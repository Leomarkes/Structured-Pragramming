#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Cad
	{
		char nome[50],endereco[30],fone[12];
		long int cep;
	}Cads;

Cads cadastrar();
char * consultar();
char consultarL();

void main(){
	
	Cads cadastro[100];
	int opt,c=0,i;
	char *consulta;
	char consultaL;

	do{	
		printf("Selecione uma opcao: 1-Cadastrar, 2-Consultar Cadastro, 3-Consultar Cadastros por Letra, 4-Sair.\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				cadastro[c]=cadastrar();
				c++;
				break;
			case 2:
				consulta=consultar();
				for(i=0;i<c;i++){
					if (!(strcmp(cadastro[i].nome,consulta))){
						printf("%s\n%s\n%s\n%ld\n", cadastro[i].nome,cadastro[i].endereco,cadastro[i].fone,cadastro[i].cep);
					}else
						printf("Cadastro nao encontrado.\n");
				}
				break;
			case 3:
				consultaL=consultarL();
				for(i=0;i<c;i++){
					if(!(consultaL==cadastro[i].nome[0]))
						printf("%s\n%s\n%s\n%ld\n", cadastro[i].nome,cadastro[i].endereco,cadastro[i].fone,cadastro[i].cep);
					else
						printf("Nenhum cadastro com essa letra.\n");
				}
				break;
			case 4:
				exit(0);
				break;
		}

	}while(0<opt<5);
}

Cads cadastrar(){
	Cads cadastro;

	printf("Digite o nome:\n");
	setbuf(stdin,NULL);
	fgets(cadastro.nome,49,stdin);
	printf("Digite o endereco:\n");
	setbuf(stdin,NULL);
	fgets(cadastro.endereco,29,stdin);
	printf("Digite o fone:\n");
	setbuf(stdin,NULL);
	fgets(cadastro.fone,11,stdin);
	printf("Digite o cep:\n");
	scanf("%ld", &cadastro.cep);
	return(cadastro);
}

char * consultar(){
	char consultaa[50];

	printf("Digite o nome a ser consultado:\n");
	setbuf(stdin,NULL);
	fgets(consultaa,49,stdin);
	return(consultaa);
}

char consultarL(){
	char consultaL;

	printf("Digite a letra a ser pesquisada na agenda:\n");
	scanf("%c", &consultaL);
	return(consultaL);
}