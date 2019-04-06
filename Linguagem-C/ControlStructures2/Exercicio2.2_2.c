#include <stdio.h>
void main(){

	int c;

	for(c=1;c<=15;c++){
		printf("%d ", c);
		if(c==1 || c==3 || c==6 || c==10 || c==15)
			printf("\n");
	}
}