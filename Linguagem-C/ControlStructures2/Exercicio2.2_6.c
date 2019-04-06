#include <stdio.h>
void main(){

	int a, b, c, me, ma, m;

	printf("Digite tres valores:");
	scanf("%d %d %d", &a, &b, &c);
	me=a;
	if(b<me){
		me=b;
	}
	if(c<me){
		me=c;
	}
	if(me==a){
		if (b>c){
			ma = b;
			m = c;
		}else{
			ma = c;
			m = b;
		}
	}else if(me==b){
		if (a>c){
			ma = a;
			m = c;
		}else{
			ma = c;
			m = a;
		}
	}else if(me==c){
		if(a>b){
			ma = a;
			m = b;
		}else{
			ma = b;
			m = a;
		}
	}
	printf("%d %d %d\n",me, m, ma);
}