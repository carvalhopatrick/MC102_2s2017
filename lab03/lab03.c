/*
LAB03 - Jóias Siderais
MC102C 2s2017
Patrick Penacho Carvalho 185388

O programa lê 4 números:
	O segundo menor valor de joia presente no cofre;
	O menor valor de joia em falta do universo;
	O segundo menor valor de joia em falta do universo;
	O valor da ordem de pagamento salarial, em galactônios reais.
	
Em seguida, apresenta a ordem de pagamento a ser feita, da maior para a maior jóia, usando as maiores jóias possíveis.
A ordem de pagamento é apresentada da seguinte forma:
	(Quantidade de jóias 1) (Valor da jóia 1)
	(Quantidade de jóias 2) (Valor da jóia 2)
			...					  ...
	(Quantidade de jóias n) (Valor da jóia n)
*/

#include <stdio.h>

unsigned long int segundoCofre = 0;		/* Segundo menor valor de jóia no cofre */
unsigned long int menorFalta = 0;		/* Menor valor de jóia em falta no cofre */
unsigned long int segundoFalta = 0;		/* Segundo menor valor em falta no cofre */
unsigned long int ordemPgto = 0; 		/* Valor da ordem de pagamento */

unsigned long int rPA = 0;
unsigned long int maiorJoiaPG = 0;
unsigned long int ordem_qntd = 0;

int main()
{
	/* Leitura dos dados de entrada */	
	scanf("%lu",&segundoCofre);
	scanf("%lu",&menorFalta);
	scanf("%lu",&segundoFalta);
	scanf("%lu",&ordemPgto);
	
	rPA = segundoFalta - menorFalta; 
	maiorJoiaPG = segundoCofre;
	
	/*Determinação das Jóias, por PG */
	while ((maiorJoiaPG < ordemPgto) && (maiorJoiaPG <= 4000000000))
		maiorJoiaPG = (maiorJoiaPG * segundoCofre);
	
	/* Como o loop acima termina com um valor 1 ordem acima do desejado, */
	maiorJoiaPG = (maiorJoiaPG / segundoCofre);
	
	while (ordemPgto > 0)
	{
		/* Se a maiorJoiaPG for menor que menorFalta, logicamente ela não estará em falta e poderá ser usada */
		if (maiorJoiaPG < menorFalta) 
		{
			ordem_qntd = (ordemPgto / maiorJoiaPG);
			if (ordem_qntd != 0)
			{
				printf("%lu %lu\n",ordem_qntd,maiorJoiaPG);
				ordemPgto = (ordemPgto - (ordem_qntd * maiorJoiaPG));
			}
		}
		else
		{
			/* Caso seja maior, checaremos se ela não está em falta: */
			if (((maiorJoiaPG - menorFalta) % rPA) != 0)
			{
				/* A qntd. de joias é dada pelo valor inteiro a divisão da ordemPgto com a jóia escolhida */
				ordem_qntd = (ordemPgto / maiorJoiaPG);
				if (ordem_qntd != 0)
				{
					printf("%lu %lu\n",ordem_qntd,maiorJoiaPG);
					ordemPgto = (ordemPgto - (ordem_qntd * maiorJoiaPG));
				}
			}
		}
		
		/* Reduziremos a joia escolhida 1 ordem para continuar o pagamento */
		maiorJoiaPG = (maiorJoiaPG / segundoCofre);
	}
	return(0);	
}