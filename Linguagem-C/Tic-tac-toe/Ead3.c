#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int jogada_usuario(int lin, int col, char jog);
void jogada_computador(char jog, int nivel);
int menu();
void escolha_simb(char *jog1, char *jog2);
void inicializa_velha();
int verifica_ganhador(char jog);
void gravatxt(char *nome1, char *nome2, char simb1, char simb2);
void mostracampeonato(char *n1, char *n2, char s1, char s2);
void mostrapartida(char *nome,int p);

char M[3][3];
int partida=0;

typedef struct Velha{
	int partida;
	char JogVelha[3][3];
	char resultado;
}Partida;

int gravabin(char *nome, Partida p);

void main(){
	int opt,opt2,np,l,c,dif,z,e,i,j,k,m,njogada=1, ganhador=0,jgusr;
	char jog1, jog2, nome1[31], nome2[31];
	Partida resultado;

	opt = menu();
	if(opt==1){
		printf("Digite o nome do jogador 1:\n");
		setbuf(stdin,NULL);
		fgets(nome1,30,stdin);
		strcpy(nome2,"Computador");
		escolha_simb(&jog1,&jog2);
		gravatxt(nome1,nome2,jog1,jog2);
	}else{
		printf("Digite o nome do jogador 1:\n");
		setbuf(stdin,NULL);
		fgets(nome1,30,stdin);
		printf("Digite o nome do jogador 2:\n");
		setbuf(stdin,NULL);
		fgets(nome2,30,stdin);
		escolha_simb(&jog1,&jog2);
		gravatxt(nome1,nome2,jog1,jog2);
	}
	LOOP:
	if(partida>0){
		do{
			printf("Digite 1 para jogar outra partida. 2 para ver o resultado de uma partida. 3 para encerrar e mostrar o resultado do campeonato.\n");
			scanf("%d",&opt2);
		}while(opt2<1 || opt2>3);
		if(opt2==2){
			do{
				printf("Digite o numero da partida que quer ler ou 0 para cancelar a consulta:\n");
				scanf("%d",&np);
				if(np>partida){
					printf("Partida inexistente. Tente de novo.\n");
				}
			}while(np>partida);
			printf("\n");
			if(np==0)
				goto LOOP;
			else{
				mostrapartida("Jogos.bin",np);
				goto LOOP;
			}
		}else if(opt2==3){
			mostracampeonato(nome1, nome2, jog1, jog2);
		}else if(opt2==1){
			goto LOOP2;
		}
	}
	LOOP2:
	partida++;
	njogada=1;
	ganhador=0;

	if(opt==1){
		do{
			printf("Escolha a dificuldade (1-Facil; 2-Medio; 3-Dificil): \n");
			scanf("%d",&dif);
		}while(dif>3 || dif<1);
		printf("\n");
		inicializa_velha();
		e=0;
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(M[j][i]==' ')
					e=1;
			}
		}
		if(e==0){
			printf("Deu velha!\n");
			goto LOOP;
		}
		while(ganhador!=1){
			if (njogada%2!=0){
				do{
					printf("Escolha a linha e coluna para jogar: \n");
					scanf("%d %d", &l,&c);
					l-=1;
					c-=1;
					jgusr=jogada_usuario(l,c,jog1);
					if(jgusr==1){
						printf("Jogada invalida.\n");
					}else if(jgusr==2){
						printf("Campo ja preenchido\n");
					}else{
						njogada++;
					}
					ganhador=verifica_ganhador(jog1);
					if(ganhador==1){
						printf("Jogador 1 ganhou!\n\n");
						resultado.partida=partida;
						for (m=0;m<3;m++){
							for (k=0;k<3;k++){
								resultado.JogVelha[m][k]=M[m][k];
							}
						}
						resultado.resultado=jog1;
						z=gravabin("Jogos.bin", resultado);
						goto LOOP;
					}
				}while(jgusr!=0);
			}else if(njogada>9){
				printf("\nDeu velha!\n\n");
				resultado.partida=partida;
				for (m=0;m<3;m++){
					for (k=0;k<3;k++){
						resultado.JogVelha[m][k]=M[m][k];
					}
				}
				resultado.resultado='V';
				z=gravabin("Jogos.bin", resultado);
				goto LOOP;
			}else{
				jogada_computador(jog2,dif);
				njogada++;
				ganhador=verifica_ganhador(jog2);
				if(ganhador==1){
					printf("Computador ganhou!\n\n");
					resultado.partida=partida;
					for (m=0;m<3;m++){
						for (k=0;k<3;k++){
							resultado.JogVelha[m][k]=M[m][k];
						}
					}
					resultado.resultado=jog2;
					z=gravabin("Jogos.bin", resultado);
					goto LOOP;
				}
			}
		}
	}
	else if(opt==2){
		inicializa_velha();
		while(ganhador!=1){
		if (njogada%2!=0){
			do{
				printf("Jogador 1, escolha a linha e coluna para jogar: \n");
				scanf("%d %d", &l,&c);
				l-=1;
				c-=1;
				jgusr=jogada_usuario(l,c,jog1);;
				if(jgusr==1){
					printf("Jogada invalida.\n");
				}else if(jgusr==2){
					printf("Campo ja preenchido\n");
				}else{
					njogada++;
				}
				ganhador=verifica_ganhador(jog1);
				if(ganhador==1){
					printf("Jogador 1 ganhou!\n\n");
					resultado.partida=partida;
					for (m=0;m<3;m++){
						for (k=0;k<3;k++){
							resultado.JogVelha[m][k]=M[m][k];
						}
					}
					resultado.resultado=jog1;
					z=gravabin("Jogos.bin", resultado);
					goto LOOP;
				}
			}while(jgusr!=0);
		}else if(njogada>9){
				printf("\nDeu velha!\n\n");
				resultado.partida=partida;
				for (m=0;m<3;m++){
					for (k=0;k<3;k++){
						resultado.JogVelha[m][k]=M[m][k];
					}
				}
				resultado.resultado='V';
				z=gravabin("Jogos.bin", resultado);
				goto LOOP;
		}else{
			do{
				printf("Jogador 2, escolha a linha e coluna para jogar: \n");
				scanf("%d %d", &l,&c);
				l-=1;
				c-=1;
				jgusr=jogada_usuario(l,c,jog2);
				if(jgusr==1){
					printf("Jogada invalida.\n");
				}else if(jgusr==2){
					printf("Campo ja preenchido\n");
				}else{
					njogada++;
				}
				ganhador=verifica_ganhador(jog2);
				if(ganhador==1){
					printf("Jogador 2 ganhou!\n\n");
					resultado.partida=partida;
					for (m=0;m<3;m++){
						for (k=0;k<3;k++){
							resultado.JogVelha[m][k]=M[m][k];
						}
					}
					resultado.resultado=jog2;
					z=gravabin("Jogos.bin", resultado);
					goto LOOP;
				}
			}while(jgusr!=0);
		}
		}
	}
}

void inicializa_velha(){

	int c,i;

	for(c=0;c<3;c++){
		for(i=0;i<3;i++)
				M[c][i]=' ';
	}
	for(int c=0;c<3;c++){
		for(int l=0;l<3;l++){
			printf("[%c]", M[l][c]);
		}
		printf("\n");
	}
}

void escolha_simb(char *jog1, char *jog2){
	char a,b;

	do{
		printf("Informe qual o simbolo do jogador 1 (X ou O): \n");
		setbuf(stdin,NULL);
		scanf("%c", &a);
	}while((a!=79) && (a!=88));
	if (a=='X')
		b='O';
	else
		b='X';
	*jog1=a;
	*jog2=b;
}

int menu(){
	int opt;

	do{
		printf("Para jogar contra o PC digite 1 ou para jogar contra outra pessoa digite 2:\n");
		scanf("%d",&opt);
	}while(opt<1 || opt>2);
	return(opt);
}

int jogada_usuario(int lin, int col, char jog){
	int c,i;

	if((lin<0) || (lin>2) || (col<0) || (col>2)){
		return(1);
	}else if(M[lin][col]!=' '){
		return(2);
	}else if(M[lin][col]==' '){
		M[lin][col]=jog;
		for(c=0;c<3;c++){
			for(i=0;i<3;i++){
				printf("[%c]", M[c][i]);
			}
			printf("\n");
		}
		return(0);
	}
}

void jogada_computador(char jog, int nivel){
	int l,c,i,j,e=0,a,b;
	char jog2;

	if(nivel==1){
		srand(time(NULL));
		do{
			do{
				do{
					do{
						do{
							l=rand()%3;
							c=rand()%3;
							e++;
							if(e>9){
								break;
							}
						}while((M[0][0]==jog && M[1][1]==jog && M[2][2]==M[l][c]) || (M[0][0]==jog && M[1][1]==M[l][c] && M[2][2]==jog) || (M[0][0]==M[l][c] && M[1][1]==jog && M[2][2]==jog) || (M[2][0]==jog && M[1][1]==jog && M[0][2]==M[l][c]) || (M[2][0]==jog && M[1][1]==M[l][c] && M[0][2]==jog) || (M[2][0]==M[l][c] && M[1][1]==jog && M[0][2]==jog));
						if(e>9){
							break;
						}
					}while((M[0][0]==jog && M[0][1]==jog && M[0][2]==M[l][c]) || (M[0][0]==jog && M[0][1]==M[l][c] && M[0][2]==jog) || (M[0][0]==M[l][c] && M[0][1]==jog && M[0][2]==jog) || (M[1][0]==jog && M[1][1]==jog && M[1][2]==M[l][c]) || (M[1][0]==jog && M[1][1]==M[l][c] && M[1][2]==jog) || (M[1][0]==M[l][c] && M[1][1]==jog && M[1][2]==jog));
					if(e>9){
						break;
					}
				}while((M[2][0]==jog && M[2][1]==jog && M[2][2]==M[l][c]) || (M[2][0]==jog && M[2][1]==M[l][c] && M[2][2]==jog) || (M[2][0]==M[l][c] && M[2][1]==jog && M[2][2]==jog) || (M[0][0]==jog && M[1][0]==jog && M[2][0]==M[l][c]) || (M[0][0]==jog && M[1][0]==M[l][c] && M[2][0]==jog) || (M[0][0]==M[l][c] && M[1][0]==jog && M[2][0]==jog));
				if(e>9){
					break;
				}
			}while((M[0][1]==jog && M[1][1]==jog && M[2][1]==M[l][c]) || (M[0][1]==jog && M[1][1]==M[l][c] && M[2][1]==jog) || (M[0][1]==M[l][c] && M[1][1]==jog && M[2][1]==jog) || (M[0][2]==jog && M[1][2]==jog && M[2][2]==M[l][c]) || (M[0][2]==jog && M[1][2]==M[l][c] && M[2][2]==jog) || (M[0][2]==M[l][c] && M[1][2]==jog && M[2][2]==jog));
		}while(M[l][c]!= ' ');
		M[l][c]=jog;
		printf("\nJogada do computador\n");
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				printf("[%c]", M[j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}else if(nivel==2){
		srand(time(NULL));
		do{
			l=rand()%3;
			c=rand()%3;
		}while(M[l][c]!= ' ');
		M[l][c]=jog;
		printf("\nJogada do computador\n");
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				printf("[%c]", M[j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}else if(nivel==3){
		if (jog=='X')
			jog2='O';
		else
			jog2='X';
		srand(time(NULL));
		e=0;
		do{
			l=rand()%3;
			c=rand()%3;
			if(M[1][1]==' '){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog && M[0][1]==jog && M[0][2]== ' ')){
				M[0][2]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog && M[0][2]==jog && M[0][1]== ' ')){
				M[0][1]=jog;
				e=1;
				break;
			}else if((M[0][1]==jog && M[0][2]==jog && M[0][0]== ' ')){
				M[0][0]=jog;
				e=1;
				break;
			}else if((M[1][0]==jog && M[1][1]==jog && M[1][2]== ' ')){
				M[1][2]=jog;
				e=1;
				break;
			}else if((M[1][0]==jog && M[1][2]==jog && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog && M[1][2]==jog && M[1][0]== ' ')){
				M[1][0]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog && M[2][1]==jog && M[2][2]== ' ')){
				M[2][2]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog && M[2][2]==jog && M[2][1]== ' ')){
				M[2][1]=jog;
				e=1;
				break;
			}else if((M[2][1]==jog && M[2][2]==jog && M[2][0]== ' ')){
				M[2][0]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog && M[1][0]==jog && M[2][0]== ' ')){
				M[2][0]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog && M[2][0]==jog && M[1][0]== ' ')){
				M[1][0]=jog;
				e=1;
				break;
			}else if((M[1][0]==jog && M[2][0]==jog && M[0][0]== ' ')){
				M[0][0]=jog;
				e=1;
				break;
			}else if((M[0][1]==jog && M[1][1]==jog && M[2][1]== ' ')){
				M[2][1]=jog;
				e=1;
				break;
			}else if((M[0][1]==jog && M[2][1]==jog && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog && M[2][1]==jog && M[0][1]== ' ')){
				M[0][1]=jog;
				e=1;
				break;
			}else if((M[0][2]==jog && M[1][2]==jog && M[2][2]== ' ')){
				M[2][2]=jog;
				e=1;
				break;
			}else if((M[0][2]==jog && M[2][2]==jog && M[1][2]== ' ')){
				M[1][2]=jog;
				e=1;
				break;
			}else if((M[1][2]==jog && M[2][2]==jog && M[0][2]== ' ')){
				M[0][2]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog && M[1][1]==jog && M[2][2]== ' ')){
				M[2][2]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog && M[2][2]==jog && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog && M[2][2]==jog && M[0][0]== ' ')){
				M[0][0]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog && M[1][1]==jog && M[0][2]== ' ')){
				M[0][2]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog && M[0][2]==jog && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog && M[0][2]==jog && M[2][0]== ' ')){
				M[2][0]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog2 && M[0][1]==jog2 && M[0][2]== ' ')){
				M[0][2]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog2 && M[0][2]==jog2 && M[0][1]== ' ')){
				M[0][1]=jog;
				e=1;
				break;
			}else if((M[0][1]==jog2 && M[0][2]==jog2 && M[0][0]== ' ')){
				M[0][0]=jog;
				e=1;
				break;
			}else if((M[1][0]==jog2 && M[1][1]==jog2 && M[1][2]== ' ')){
				M[1][2]=jog;
				e=1;
				break;
			}else if((M[1][0]==jog2 && M[1][2]==jog2 && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog2 && M[1][2]==jog2 && M[1][0]== ' ')){
				M[1][0]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog2 && M[2][1]==jog2 && M[2][2]== ' ')){
				M[2][2]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog2 && M[2][2]==jog2 && M[2][1]== ' ')){
				M[2][1]=jog;
				e=1;
				break;
			}else if((M[2][1]==jog2 && M[2][2]==jog2 && M[2][0]== ' ')){
				M[2][0]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog2 && M[1][0]==jog2 && M[2][0]== ' ')){
				M[2][0]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog2 && M[2][0]==jog2 && M[1][0]== ' ')){
				M[1][0]=jog;
				e=1;
				break;
			}else if((M[1][0]==jog2 && M[2][0]==jog2 && M[0][0]== ' ')){
				M[0][0]=jog;
				e=1;
				break;
			}else if((M[0][1]==jog2 && M[1][1]==jog2 && M[2][1]== ' ')){
				M[2][1]=jog;
				e=1;
				break;
			}else if((M[0][1]==jog2 && M[2][1]==jog2 && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog2 && M[2][1]==jog2 && M[0][1]== ' ')){
				M[0][1]=jog;
				e=1;
				break;
			}else if((M[0][2]==jog2 && M[1][2]==jog2 && M[2][2]== ' ')){
				M[2][2]=jog;
				e=1;
				break;
			}else if((M[0][2]==jog2 && M[2][2]==jog2 && M[1][2]== ' ')){
				M[1][2]=jog;
				e=1;
				break;
			}else if((M[1][2]==jog2 && M[2][2]==jog2 && M[0][2]== ' ')){
				M[0][2]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog2 && M[1][1]==jog2 && M[2][2]== ' ')){
				M[2][2]=jog;
				e=1;
				break;
			}else if((M[0][0]==jog2 && M[2][2]==jog2 && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog2 && M[2][2]==jog2 && M[0][0]== ' ')){
				M[0][0]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog2 && M[1][1]==jog2 && M[0][2]== ' ')){
				M[0][2]=jog;
				e=1;
				break;
			}else if((M[2][0]==jog2 && M[0][2]==jog2 && M[1][1]== ' ')){
				M[1][1]=jog;
				e=1;
				break;
			}else if((M[1][1]==jog2 && M[0][2]==jog2 && M[2][0]== ' ')){
				M[2][0]=jog;
				e=1;
				break;
			}
			e=0;
		}while(M[l][c]!=' ');
	if(e!=1)
		M[l][c]=jog;
	printf("\nJogada do computador\n");
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			printf("[%c]", M[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	}
}

int verifica_ganhador(char jog){

    if((M[0][0]==jog && M[0][1]==jog && M[0][2]==jog) || (M[1][0]==jog && M[1][1]==jog && M[1][2]==jog) || (M[2][0]==jog && M[2][1]==jog && M[2][2]==jog) || (M[0][0]==jog && M[1][0]==jog && M[2][0]==jog) || (M[0][1]==jog && M[1][1]==jog && M[2][1]==jog) || (M[0][2]==jog && M[1][2]==jog && M[2][2]==jog) || (M[0][0]==jog && M[1][1]==jog && M[2][2]==jog) || (M[2][0]==jog && M[1][1]==jog && M[0][2]==jog))
    	return(1);
    else
        return(0);
}

void gravatxt(char *nome1, char *nome2, char simb1, char simb2){
    int tam;
    FILE *arquivo;

    if((arquivo = fopen("arquivo.txt", "w"))== NULL){
        printf("O arquivo não pode ser aberto!");
        exit(0);
        }
    tam=strlen(nome1);
    if(nome1[tam-1]=='\n')
        nome1[--tam]='\0';
    tam=strlen(nome2);
    if(nome2[tam-1]=='\n')
        nome2[--tam]='\0';
    fprintf(arquivo, "%s;%c %s;%c.",nome1, simb1, nome2, simb2);
    fclose(arquivo);
}

int gravabin(char *nome, Partida p){
	FILE *pt;

	if(p.partida==1){
		if((pt = fopen(nome, "w+b")) == NULL){
			printf("O arquivo não pode ser aberto!");
			exit(0);
 		}
 		fwrite(&p, 1, sizeof(Partida), pt);
 		fclose(pt);
 	}else{
 		if((pt = fopen(nome, "r+b")) == NULL){
			printf("O arquivo não pode ser aberto!");
			exit(0);
 		}
 		fseek(pt,0,SEEK_END);
 		fwrite(&p, 1, sizeof(Partida), pt);
 		fclose(pt);
 	}
 	return(0);
}

void mostrapartida(char *nome,int p){
	FILE *pt;
	Partida lt;

	if((pt = fopen(nome,"r+b")) == NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
 	}
 	p--;
 	fseek(pt,p*sizeof(Partida),SEEK_SET);
 	fread(&lt,1, sizeof(Partida), pt);
 	printf("%d\n", lt.partida);
 	printf("%c\n", lt.resultado);
 	for(int c=0;c<3;c++){
 		for(int i=0;i<3;i++){
 			printf("[%c]", lt.JogVelha[c][i]);
 		}
 		printf("\n");
 	}
}

void mostracampeonato(char *n1, char *n2, char s1, char s2){

	FILE *pt, *pt2;
	Partida lt;
	char s[64],nomex[31],nomeo[31];
	int j=0,X=0,O=0;

	system("cls");
    if (s1=='X'){
        strcpy(nomex,n1);
        strcpy(nomeo,n2);
    }else{
        strcpy(nomex,n2);
        strcpy(nomeo,n1);}

    if((pt = fopen("arquivo.txt", "r")) == NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
 	}
    while (!feof(pt)){
    	fscanf(pt,"%s",s);
    	printf("%s \n",s);
    }
	if((pt2 = fopen("Jogos.bin", "r+b")) == NULL){
		printf("O arquivo não pode ser aberto!");
		exit(0);
 	}
    while(!feof(pt2)){
		if((int *)(fread(&lt, 1, sizeof(Partida), pt2))!=NULL){
 		printf("\nPartida: %d\n", lt.partida);
 		printf("Vencedor: %c\n", lt.resultado);
 		if (lt.resultado=='X')
            X++;
        else if(lt.resultado=='O')
            O++;
 		for(int c=0;c<3;c++){
 			for(int i=0;i<3;i++){
                printf("[%c]", lt.JogVelha[c][i]);
 			}
 			printf("\n");
 		}
 		}
 	}
 	fclose(pt);

 	if (X>O)
 		printf("\n%s:%d X %d:%s\n%s ganhou o campeonato de jogo da velha!\n",nomex,X,O,nomeo,nomex);
 	else
        printf("\n%s:%d X %d:%s\n%s ganhou o campeonato de jogo da velha!\n",nomeo,O,X,nomex,nomeo);
    exit(0);
}