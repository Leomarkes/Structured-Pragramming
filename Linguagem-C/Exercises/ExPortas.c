#include <stdio.h>

void main(){
	typedef struct por{
		int n;
		char estado;
	}port;

	port porta[100];
	int c,i,q,nr,a;

	do{
		for(i=0;i<100;i++){
			porta[i].n=(i+1);
			porta[i].estado='C';
		}
		printf("Digite o numero de andares e de jogadas que o peao fara:\n");
		scanf("%d %d",&a,&q);
		for(i=0;i<q;i++){
			printf("Digite o numero para a %d jogada:\n", (i+1));
			scanf("%d", &nr);
			for(c=0;c<a;c++){	
				if((c+1)%nr==0){
					if(porta[c].estado=='C')
						porta[c].estado='O';
					else
						porta[c].estado='C';
				}
				if(a==0 && q==0)
					break;
			}
		}	
		for(i=0;i<a;i++){
			printf("%c", porta[i].estado);
		}
		printf("\n");
	}while(a!=0 && q!=0);
}