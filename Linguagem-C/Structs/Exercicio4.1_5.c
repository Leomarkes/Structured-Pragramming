#include <stdio.h>
#include <ctype.h>

void main(){

	typedef struct End{
		char rua[30];
		int numero;
		char complemento[30];
		char bairro[30];
		char cep[10];
		char cidade[30];
		char estado[3]; /*informar a sigla do estado*/
		char pais[3]; /*informar a sigla do pais*/
	}Endereco;

	typedef struct Telefone{
		char ddd[5];
		char numfone[10];
	}Fone;

	typedef struct Aniversario{
		int dia;
		char mes[10];
		int ano;
	}Niver;

	typedef struct Dados_Pessoa{
		char nome[50];
		char email[30];
		Endereco residencia;
		Fone fonecasa;
		Niver nasci;
		char observacoes[100];
	}Agenda;

	Agenda Dados_Pessoa;

	printf("Digite o nome: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.nome,49,stdin);
	printf("Digite o email: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.email,29,stdin);
	printf("Digite o nome da rua: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.rua,29,stdin);
	printf("Digite o numero: ");
	scanf("%d", &Dados_Pessoa.residencia.numero);
	printf("Digite o complemento: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.complemento,29,stdin);
	printf("Digite o bairro: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.bairro,29,stdin);
	printf("Digite o cep: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.cep,9,stdin);
	printf("Digite a cidade: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.cidade,29,stdin);
	printf("Digite o estado (UF): ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.estado,2,stdin);
	printf("Digite o pais (sigla): ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.residencia.pais,2,stdin);
	printf("Digite o DDD do telefone: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.fonecasa.ddd,4,stdin);
	printf("Digite o telefone: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.fonecasa.numfone,9,stdin);
	printf("Digite o dia do nascimento: ");
	scanf("%d", &Dados_Pessoa.nasci.dia);
	printf("Digite o mes: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.nasci.mes,9,stdin);
	printf("Digite o ano (4 digitos): ");
	scanf("%d", &Dados_Pessoa.nasci.ano);
	printf("Digite as observacoes: ");
	setbuf(stdin,NULL);
	fgets(Dados_Pessoa.observacoes,99,stdin);

	printf("%s %s %s %d \n %s %s %s %s %s %s %s %s %d \n %s %d \n %s",Dados_Pessoa.nome,Dados_Pessoa.email, Dados_Pessoa.residencia.rua, Dados_Pessoa.residencia.numero, Dados_Pessoa.residencia.complemento, Dados_Pessoa.residencia.bairro, Dados_Pessoa.residencia.cep, Dados_Pessoa.residencia.cidade, Dados_Pessoa.residencia.estado, Dados_Pessoa.residencia.pais, Dados_Pessoa.fonecasa.ddd, Dados_Pessoa.fonecasa.numfone, Dados_Pessoa.nasci.dia, Dados_Pessoa.nasci.mes, Dados_Pessoa.nasci.ano, Dados_Pessoa.observacoes);
}