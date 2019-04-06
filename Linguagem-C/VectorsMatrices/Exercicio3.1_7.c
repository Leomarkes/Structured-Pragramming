#include <stdio.h>

void main(){

	int i,c,a[5][5];

	for(c=0;c<5;c++){
		for(i=0;i<5;i++){
			printf("Digite o elemente %d X %d da matriz F:\n",(c+1),(i+1));
			scanf("%d", &a[c][i]);
		}
	}
	printf("Diagonal principal:");
	for(c=0;c<5;c++){
		printf("\n");
		for(i=0;i<5;i++){
			if(c!=i)
				printf("   ");	
			else if(c==i)
				if(a[c][i]<10)
					printf(" %d ",a[c][i]);
				else
					printf("%d ",a[c][i]);
		}
	}
	printf("\nTriângulo superior:");
	for(c=0;c<5;c++){
		printf("\n");
		for(i=0;i<5;i++){
			if(c>=i)
				printf("   ");	
			else if(c<i)
				if(a[c][i]<10)
					printf(" %d ",a[c][i]);
				else
					printf("%d ",a[c][i]);
		}
	}
	printf("\nTriângulo inferior:");
	for(c=0;c<5;c++){
		printf("\n");
		for(i=0;i<5;i++){
			if(c<=i)
				printf("   ");	
			else if(c>i)
				if(a[c][i]<10)
					printf(" %d ",a[c][i]);
				else
					printf("%d ",a[c][i]);
		}	
	}
	printf("\nMatriz sem a diagonal principal:");
	for(c=0;c<5;c++){
		printf("\n");
		for(i=0;i<5;i++){
			if(c==i)
				printf("   ");	
			else if(c!=i)
				if(a[c][i]<10)
					printf(" %d ",a[c][i]);
				else
					printf("%d ",a[c][i]);
		}
	}
	printf("\n");
}