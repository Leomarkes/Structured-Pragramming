#include <stdio.h>
void main(){

	int c, i, k;
	char t, a;

	i = 48;
	k = 65;
	printf("  0 1 2 3 4 5 6 7 8 9 A B C D E F");
	for(c=0;c<=255;c++){
		if (c%16==0){
			if (i<=57){
				t = i;
				i++;
				printf("\n%c ",t);
			}else if(k<=70){
				t = k;
				k++;
				printf("\n%c ",t);
			}
		}
		if (c<32)
			t = 32;
		else
			t = c;
		printf("%c ", t);
	}
}