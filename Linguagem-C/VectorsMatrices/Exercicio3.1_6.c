#include <stdio.h>

void main(){

	int a,d,m,s,i,c,F[5][5],G[5][5],lif,lsf,cif,csf,lig,lsg,cig,csg;

	for(c=0;c<5;c++){
		for(i=0;i<5;i++){
			printf("Digite o elemente %d X %d da matriz F:\n",(c+1),(i+1));
			scanf("%d", &F[c][i]);
		}
	}
	for(c=0;c<5;c++){
		for(i=0;i<5;i++){
			printf("Digite o elemente %d X %d da matriz G:\n",(c+1),(i+1));
			scanf("%d", &G[c][i]);
		}
	}

	printf("Escolha o limite inferior da linha da matriz F:");
	scanf("%d", &lif);
	printf("Escolha o limite superior da linha da matriz F:");
	scanf("%d", &lsf);
	printf("Escolha o limite inferior da coluna da matriz F:");
	scanf("%d", &cif);
	printf("Escolha o limite superior da coluna da matriz F:");
	scanf("%d", &csf);

	printf("Escolha o limite inferior da linha da matriz G:");
	scanf("%d", &lig);
	printf("Escolha o limite superior da linha da matriz G:");
	scanf("%d", &lsg);
	printf("Escolha o limite inferior da coluna da matriz G:");
	scanf("%d", &cig);
	printf("Escolha o limite superior da coluna da matriz G:");
	scanf("%d", &csg);

	do{
	if(((csf-cif)+1)==((lsg-lig)+1)){
		printf("Resultado da multiplicação das submatrizes:\n");
		d=(lif-1);
		do{
			m=0;
			a=(cig-1);
			do{
				s=0;
				for(c=(cif-1);c<csf;c++){
					for(i=(lig-1);i<lsg;i++){
						if (c==i){
							m=F[d][c]*G[i][a];
							s=s+m;
						}
					}
				}
				printf("%d ",s);
				a++;
			}while(a<csg);
			printf("\n");
			d++;
		}while(d<lsf);
	}else
		printf("Multiplicação de submatrizes impossível.\n");
	}while(lif<=0 || lsf>=6 || cif<=0 || csf>=6 || lig<=0 || lsg>=6 || cig<=0 || csg>=6);
}