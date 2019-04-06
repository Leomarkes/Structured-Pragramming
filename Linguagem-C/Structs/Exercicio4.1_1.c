#include <stdio.h>

void main(){

	typedef struct alu{
		char nome[30];
		int grr;
		float n1, n2, n3, media;
	}aluno;

	aluno alunos[5];
	int c,a;
	float ma,me;

	for(c=0;c<5;c++){
		printf("Informe o nome, a matrícula e as notas das 3 provas em sequência do aluno %d:",(c+1));
		setbuf(stdin, NULL);
		fgets(alunos[c].nome,30,stdin);
		scanf("%d",&alunos[c].grr);
		scanf("%f",&alunos[c].n1);
		scanf("%f",&alunos[c].n2);
		scanf("%f",&alunos[c].n3);
	}

	ma=alunos[0].n1;
	for(c=1;c<5;c++){
		if(alunos[c].n1>ma){
			ma=alunos[c].n1;
			a=c;
		}
	}
	printf("O aluno com a maior nota na profa 1 foi %s e ele tirou nota %.2f.\n",alunos[a].nome,alunos[a].n1);

	for(c=0;c<5;c++){
		alunos[c].media=((alunos[c].n1+alunos[c].n2+alunos[c].n3)/3);
	}
	ma=alunos[0].media;
	for(c=1;c<5;c++){
		if(alunos[c].media>ma){
			ma=alunos[c].media;
			a=c;
		}
	}
	printf("O aluno com a maior media foi %s e a media foi %.2f.\n",alunos[a].nome,alunos[a].media);

	me=alunos[0].media;
	for(c=1;c<5;c++){
		if(alunos[c].media<me){
			me=alunos[c].media;
			a=c;
		}
	}
	printf("O aluno com a menor media foi %s e a media foi %.2f.\n",alunos[a].nome,alunos[a].media);

	for(c=0;c<5;c++){
		if(alunos[c].media>=7){
			printf("%s Aprovado(a).\nMédia %.2f.\n", alunos[c].nome,alunos[c].media);
		}else{
			printf("%s Reprovado(a).\nMédia %.2f.\n", alunos[c].nome,alunos[c].media);
		}
	}
}