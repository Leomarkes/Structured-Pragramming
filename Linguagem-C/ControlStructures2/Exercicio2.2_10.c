#include <stdio.h>
void main(){

	int i, c, d;

	for (i=1; i<=100; i++){
		d=0;
		for (c=1;c<=i;c++){
			if(i%c==0){
				d++;
			}
		}if(d<=2)
			printf("%d\n", i);
	}
}