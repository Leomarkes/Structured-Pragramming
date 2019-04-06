#include <stdio.h>
#include <string.h>

void main(){

	typedef struct alu
	{
		char nome[30];
		float n1,n2,n3,n4,me;
	}aluno;

	int t,c;
	aluno alunos[8],a;

	for(c=0;c<8;c++){
		setbuf(stdin,NULL);
		printf("Digite o nome e as 4 notas do aluno %d: ",(c+1));
		fgets(alunos[c].nome,30,stdin);	
		scanf("%f",&alunos[c].n1);
		scanf("%f",&alunos[c].n2);
		scanf("%f",&alunos[c].n3);
		scanf("%f",&alunos[c].n4);
	}
	//for(c=0;c<8;c++){
	//	alunos[c].media=((alunos[c].n1+alunos[c].n2+alunos[c].n3+alunos[c].n4)/4);
	//}
	do{
		t=0;
		for(c=0;c<8;c++){
			if(strcmp(alunos[c].nome,alunos[c+1].nome)>0){
				a=alunos[c];
				alunos[c]=alunos[c+1];
				alunos[c+1]=a;
				t=1;
			}
		}
	}while(t!=0);
	for(c=0;c<8;c++){
		printf("%s nota 1: %.2f nota 2: %.2f nota 3: %.2f nota 4: %.2f\n\n",alunos[c].nome,alunos[c].n1,alunos[c].n2,alunos[c].n3,alunos[c].n4);
	}
}