#include <stdio.h>

void converteHora(int total_segundos, int *hora, int *min, int *seg);

void main(){
	int sec,h=0,m=0,s=0;

	printf("Digite o total de segundos:\n");
	scanf("%d",&sec);
	converteHora(sec,&h,&m,&s);
	printf("%2d:%2d:%2d\n", h,m,s);
}

void converteHora(int total_segundos, int *hora, int *min, int *seg){

	*hora=total_segundos/3600;
	*seg=total_segundos-(*hora*3600);
	*min=*seg/60;
	*seg=*seg%60;
}