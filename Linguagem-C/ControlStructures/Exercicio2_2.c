#include <stdio.h>

void main()
{
	int v=0,e=0,d=0,gmar=0,gsof=0;
	int j,c;
	float m1=0,m2=0;

	printf("Digite o numero de jogos do seu time:");
	scanf("%d", &j);
		for(c=1;c<=j;c++)
		{
			printf("Digite o numero de gols marcados no %d jogo:", c);
			scanf("%d", &gmar);
			printf("Digite o numero de gols sofridos no %d jogo:", c);
			scanf("%d", &gsof);
			m1=m1+gmar;
			m2=m2+gsof;
			if (gmar>gsof)
				v++;
			if (gmar<gsof)
				d++;
			if (gmar==gsof)
				e++;
		}
		m1=m1/j;
		m2=m2/j;
		printf("Seu time venceu %d, perdeu %d e empatou %d jogos. Teve uma média de %.2f gols marcados e %.2f gols sofridos.", v,d,e,m1,m2);
}