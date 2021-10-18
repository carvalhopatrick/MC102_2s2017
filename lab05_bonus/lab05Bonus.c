/*
Lab05 Bônus - Pareamento de Hipogrifos
MC102C 2s2017
Patrick Penacho Carvalho 185388

O programa lê as informações (n. de passos, direções e deslocamentos dos passos) 
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
	int d_femea[(1000)] = {0};	/* Deslocamentos fêmea */
	int d_macho[(1000)] = {0};	/* Deslocamentos macho */
	int r_femea[(1000)] = {0};	/* Direções (rotações) fêmea */
	int r_macho[(1000)] = {0};	/* Direções (rotações) macho */
	
	int d[8] = {0};
	int fase1_end = 0;		/* Passo em que termina a fase 1 */
	int fase2F_end = 0;		/* Passo em que termina a fase 2 da fêmea */
	int fase2M_end = 0;		/* Passo em que termina a fase 2 do macho */
	int passosF_fase3 = 0;		/* Número de passos da fase 3 da fêmea */
	int passosM_fase3 = 0;		/* Número de passos da fase 3 da fêmea */
	int rotacaoMF	= 0;	/* Diferença entre as direções das danças do macho e da fêmea */
	int rotacaoMFc	= 0;	/* Complementar de rotacaoMF */
	int incompativel_flag = 0;	
	int i = 0, f = 0, j = 0, aux = 0;

	passosF_fase3 += 1;
	passosF_fase3 -= 1;
	
	/* Lê o numero de passos da dança */
	scanf("%d %d",&passosF,&passosM);
	
	/* Lê a dança do macho e da fêmea, armazenando os dados num vetor */
	for (i=0; i<(passosF); i++)
	{
	   fscanf(stdin, "%d", &r_femea[i]);
	   fscanf(stdin, "%d", &d_femea[i]);
	}
	for (i=0; i<(passosM); i++)
	{
	   fscanf(stdin, "%d", &r_macho[i]);
	   fscanf(stdin, "%d", &d_macho[i]);
	}
	
	
	
	/* Detecta o fim da primeira fase da dança (fêmea volta no lugar em que começou) */
	i = 0;
	while ((fase1_end == 0) && (i < passosF))
	{
		/* Direções */
		aux = r_femea[i];

		/* Deslocamentos */
		d[(aux)] += d_femea[i];
	
		if (i > 0)
		{
			if ( ((d[0] - d[4]) == 0) && ((d[1] - d[5]) == 0) && ((d[2] - d[6]) == 0) && ((d[3] - d[7]) == 0) )
			{
				fase1_end = i+1;
			}
		}
		i++;
	}
	
	/* Detecta o fim da segunda fase da dança da fêmea (dá um passo pra trás maior que o anterior) */
	aux = 0;
	i = fase1_end;
	while ( (fase2F_end == 0) && (i < (passosF-1)) )
	{
		/* Fêmea */
		aux = (r_femea[i] - r_femea[(i+1)]);
		if ((aux == 4) || (aux == -4)) /* Houve um passo em direção oposta ao anterior */
		{
			if (d_femea[i] < d_femea[(i+1)])
			{
				fase2F_end = i+2;
			}
		}
		i++;
	}
	
	/* Loop principal dos testes de compatibilidade: roda uma vez com o vetor normal, outra com o reverso */
	for (j = 0; j < 2; j++)
	{		
		/* Detecta o fim da segunda fase da dança do macho */
		if ( (incompativel_flag == 0) || (incompativel_flag == 10) )
		{
			aux = 0;
			i = fase1_end;
			while ( (fase2M_end == 0) && (i < (passosM-1)) )
			{
				aux = (r_macho[i] - r_macho[(i+1)]);
				if ((aux == 4) || (aux == -4)) /* Houve um passo em direção oposta ao anterior */
				{
					if (d_macho[i] < d_macho[(i+1)])
					{
						fase2M_end = i+2;
					}
				}
				i++;
			}
			
			if (fase2M_end == 0) /* Se não foi possível detectar fim da segunda fase do macho */
			{
				if (incompativel_flag == 0) 	
				{
					incompativel_flag = 2;	/* Ainda pode haver comp. reversa */
				}
				if (incompativel_flag == 10)	
				{
					incompativel_flag = 11;	/* A dança já é incompatível */
				}	
			}
		}
		/* ========================= COMPATIBILIDADE DA PRIMEIRA FASE ================================= */
		/* Checa se os deslocamentos do macho são maiores, e se seguem uma razão constante na dança */
		for (i = 0; i < fase1_end; i++)
		{
			if (d_macho[i] > d_femea[i])
			{
				if ( ((d_macho[0]*1.0) / (d_femea[0]*1.0)) != ((d_macho[i]*1.0) / (d_femea[i]*1.0)) )
				{
					if (incompativel_flag == 0) 
					{
						incompativel_flag = 2;
					}
					if (incompativel_flag == 10)
					{
						incompativel_flag = 11;
					}	
				}
			}
			else 
			{
				if (incompativel_flag == 0) 
				{
					incompativel_flag = 2;
				}
				if (incompativel_flag == 10)
				{
					incompativel_flag = 11;
				}
			}	
		}
		

		/* Checa se as direções dos passos da dança são compatíveis, considerando a rotação no espaço */
		rotacaoMF = (r_femea[0] - r_macho[0]);
		if (rotacaoMF < 0)
			rotacaoMFc = rotacaoMF + 8;
		if (rotacaoMF > 0)
			rotacaoMFc = rotacaoMF - 8;
		if (rotacaoMF == 0)
			rotacaoMFc = rotacaoMF;
		
		for (i = 0; i < fase1_end; i++)
		{
			if ( ((r_femea[i] - r_macho[i]) != rotacaoMF) && ((r_femea[i] - r_macho[i]) != rotacaoMFc) )
			{
				if (incompativel_flag == 0) 
				{
					incompativel_flag = 2;
				}
				if (incompativel_flag == 10)
				{
					incompativel_flag = 11;
				}
			}
		}

		/* ========================= COMPATIBILIDADE DA SEGUNDA FASE ================================= */
		if ((fase2F_end - fase2M_end) < 0)
		{
			if (incompativel_flag == 0) 
			{
				incompativel_flag = 2;
			}
			if (incompativel_flag == 10)
			{
				incompativel_flag = 11;
			}
		}
	
		/* ========================= COMPATIBILIDADE DA TERCEIRA FASE ================================= */
		if (incompativel_flag == 0 || incompativel_flag == 10)
		{
			passosF_fase3 = (passosF - fase2F_end);
			passosM_fase3 = (passosM - fase2M_end);
			if (fase2M_end == 0)	
			{
				passosM_fase3 = 0;
				if (incompativel_flag == 0) 
				{
					incompativel_flag = 2;
				}
				if (incompativel_flag == 10)
				{
					incompativel_flag = 11;
				}
			}
			
			/* Checa se os deslocamentos do macho seguem uma razão constante na dança */
			for (i = 0; i < passosM_fase3; i++)
			{
				if ( ((d_macho[(fase2M_end)]*1.0) / (d_femea[(fase2F_end)]*1.0)) != ((d_macho[(fase2M_end+i)]*1.0) / (d_femea[(fase2F_end+i)]*1.0)) )
				{
					if (incompativel_flag == 0) 
					{
						incompativel_flag = 2;
					}
					if (incompativel_flag == 10)
					{
						incompativel_flag = 11;
					}
				}
			}

			/* Checa se as direções dos passos da dança são compatíveis, considerando a rotação no espaço */
			rotacaoMF = (r_femea[(fase2F_end)] - r_macho[(fase2M_end)]);
			if (rotacaoMF < 0)
				rotacaoMFc = rotacaoMF + 8;
			if (rotacaoMF > 0)
				rotacaoMFc = rotacaoMF - 8;
			if (rotacaoMF == 0)
				rotacaoMFc = rotacaoMF;
			
			for (i = 0; i < passosM_fase3; i++)
			{
				if ( 	((r_femea[(fase2F_end+i)] - r_macho[(fase2M_end+i)]) != rotacaoMF) \
					&& 	((r_femea[(fase2F_end+i)] - r_macho[(fase2M_end+i)]) != rotacaoMFc) )
				{
					if (incompativel_flag == 0) 
					{
						incompativel_flag = 2;
					}
					if (incompativel_flag == 10)
					{
						incompativel_flag = 11;
					}
				}
			}
		}
		
		/* Checar se pode haver compatibilidade reversa */
		if (incompativel_flag == 2)
		{
			/* Reverte a dança do macho */
			f = (passosM-1);
			for (i=0; i < (passosM/2); i++)
			{
				aux = r_macho[f];
				r_macho[f] = r_macho[i];
				r_macho[i] = aux;
				
				aux = d_macho[f];
				d_macho[f] = d_macho[i];
				d_macho[i] = aux;
				
				f--;		
			}
			incompativel_flag = 10;
			fase2M_end = 0;
		}
	}
	
	/* Imprime o resultado final */
	if (incompativel_flag == 0)
		printf("Compatibilidade natural.\n");
	if (incompativel_flag == 11)
		printf("Incompatibilidade total.\n");
	if (incompativel_flag == 10)
		printf("Reverso tem compatibilidade.\n");
	
	return 0;
}