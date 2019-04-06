#include <stdio.h>
void main(){
	float s, v, sf=0;
	int op;

	printf("Digite o saldo atual da conta:");
	scanf("%f", &s);
	do{
		printf("Digite o tipo da operaçao e o valor (1-Deposito, 2-Retirada, 3-Fim)");
		scanf("%d %f", &op, &v);
		if (op==1){
			s = s + v;
		}else if(op==2){
			s = s - v;
		}
	}while(op!=3);
	if (s>0){
		printf("Conta preferencial. Saldo: %.2f",s);
	}else if(s==0){
		printf("Conta zerada. Saldo: %.2f", s);
	}else{
		printf("Conta estourada. Saldo: %.2f",s);
	}
}