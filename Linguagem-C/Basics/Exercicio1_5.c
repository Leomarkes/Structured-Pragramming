#include <stdio.h>

void main()
{
	int i,j,k=3;
	int m,n=5;

	k%=m=-(1+n/(2-n));
	printf("%d %d %d %d %d ", i,j,k,m,n);
}