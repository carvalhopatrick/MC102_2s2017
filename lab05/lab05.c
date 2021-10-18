/*
LAB05 - Pareamento de Hipogrifos
MC102C 2s2017
Patrick Penacho Carvalho 185388

O programa as informações (n. de passos, direções e deslocamentos dos passos) 
das danças de acasalamento de uma hipogrifo fêmea e um hipogrifo macho. Em seguida, compara-os
para descobrir se os dois espécimes têm danças de acasalamento compatíveis, incompatíveis, ou compatíveis
por meio da filmagem e reversão da dança.

*/


#include <stdio.h>

int main()
{
	/* Declaração de variáveis */
	int passosF = 0;
	int passosM = 0;
	int femea[(2000)] = {0};
	int macho[(2000)] = {0};
	int rotacaoMF	= 0;		/* Diferença entre as direções das danças do macho e da fêmea */
	int rotacaoMFc	= 0;		/* Complementar de rotacaoMF */
	int incompativel_flag = 0;
	int i = 0, f = 0, aux = 0;
	
	int d[8] = {0};
	int d_select = 0;

	/* Lê o numero de passos da dança */
	scanf("%d %d",&passosF,&passosM);
	
	/* Lê a dança do macho e da fêmea, armazenando os dados num vetor */
	for (i=0; i<(passosF*2); i++)
	{
	   fscanf(stdin, "%d", &femea[i]);
	}
	for (i=0; i<(passosM*2); i++)
	{
	   fscanf(stdin, "%d", &macho[i]);
	}
	
	/* Se o número de passos da F e do M forem diferentes, encerra o programa */
	if (passosF != passosM)
	{
		printf("Incompatibilidade total.\n");
		return 0;
	}
	
	/* Checa se a dança da fêmea termina no mesmo lugar que começa. Se não, encerra o programa.*/
	for (i = 0; i<(passosF*2); i++)
	{
		if ((i % 2) == 0) /* Direções */
		{
			d_select = femea[i];
		}
		if ((i % 2) == 1) /* Deslocamentos */
		{
			d[(d_select)] += femea[i];
		}
	}
	
	if ((d[0] - d[4]) != 0 )	
	{
		printf("Incompatibilidade total.\n");
		return 0;
	}
	if ((d[1] - d[5]) != 0 )
	{
		printf("Incompatibilidade total.\n");
		return 0;
	}
	if ((d[2] - d[6]) != 0 )
	{
		printf("Incompatibilidade total.\n");
		return 0;
	}
	if ((d[3] - d[7]) != 0 )
	{
		printf("Incompatibilidade total.\n");
		return 0;
	}
	
	/* Checa se os deslocamentos do macho são maiores, e se seguem uma razão constante na dança */
	for (i = 1; i<(passosF*2); i+=2)
	{
		if (macho[i] > femea[i])
		{
			for (f = 1; f<(passosF*2); f+=2)
			{
				if ( ((macho[i]*1.0) / (femea[i]*1.0)) != ((macho[f]*1.0) / (femea[f]*1.0)) )
				{
					incompativel_flag = 2;
					/*printf("debug  vetor %d\t\tfemea %d\t\tmacho %d\n",i,femea[i],macho[i]);*/
				}
			}
		}
		else 
		{
			incompativel_flag = 2; 
			/* Não haverá compatibilidade natural, mas pode haver reversa */
		}
		
	}
	
	
	/* Checa se as direções dos passos da dança são compatíveis, considerando a rotação no espaço */
	rotacaoMF = (femea[0] - macho[0]);
	if (rotacaoMF < 0)
		rotacaoMFc = rotacaoMF + 8;
	if (rotacaoMF > 0)
		rotacaoMFc = rotacaoMF - 8;
	if (rotacaoMF == 0)
		rotacaoMFc = rotacaoMF;
	
	for (i = 0; i<(passosF*2); i+=2)
	{
		if ( ((femea[i] - macho[i]) != rotacaoMF) && ((femea[i] - macho[i]) != rotacaoMFc) )
		{
			incompativel_flag = 2; 
			/* Não haverá compatibilidade natural, mas pode haver reversa */
		}
	}
	
	/* Checar se pode haver compatibilidade reversa */
	if (incompativel_flag == 2)
	{
		/* Reverte a dança do macho */
		f = ((passosF*2)-1);
		
		for (i=0; i<passosF; i++)
		{
			aux = macho[f];
			macho[f] = macho[i];
			macho[i] = aux;
			f--;		
		}
		for (i = 0; i<((passosF*2)-1); i+=2)
		{
			aux = macho[i+1];
			macho[(i+1)] = macho[i];
			macho[i] = aux;
		}
		
		/* Teste de rotação da dança reversa */
		rotacaoMF = (femea[0] - macho[0]);
		if (rotacaoMF < 0)
			rotacaoMFc = rotacaoMF + 8;
		if (rotacaoMF > 0)
			rotacaoMFc = rotacaoMF - 8;
		if (rotacaoMF == 0)
			rotacaoMFc = rotacaoMF;
		for (i = 0; i<(passosF*2); i+=2)
		{
			if ( ((femea[i] - macho[i]) != rotacaoMF) && ((femea[i] - macho[i]) != rotacaoMFc) )
			{
				incompativel_flag = 1;
			}
		}
		
		/* Teste de deslocamentos da dança reversa */
		if (incompativel_flag != 1)
		{
			for (i = 1; i<(passosF*2); i+=2)
			{
				if (macho[i] > femea[i])
				{
					for (f = 1; f<(passosF*2); f+=2)
					{
						if ( ((macho[i]*1.0) / (femea[i]*1.0)) != ((macho[f]*1.0) / (femea[f]*1.0)) )
						{
							incompativel_flag = 1;
							/*printf("debug2  vetor %d\t\tfemea %d\t\tmacho %d\n",i,femea[i],macho[i]);*/
						}
					}
				}
				else 
				{
					incompativel_flag = 1;
				}
			}
		}
	}
	
	/* Imprime o resultado final */
	if (incompativel_flag == 0)
		printf("Compatibilidade natural.\n");
	if (incompativel_flag == 1)
		printf("Incompatibilidade total.\n");
	if (incompativel_flag == 2)
		printf("Reverso tem compatibilidade.\n");
	
	return 0;
}