#include <stdio.h>
void main(){

	int c;

	for (c=1;c<=10;c++){
		if (c%2==0){
			printf("%d\n",c);
		}else{
			printf("\t %d\n",c);
		}
	}
}