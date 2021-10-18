/*
Lab07 - Hipótese de Sapir–Whorf
MC102C 2s2017
Patrick Penacho Carvalho 185388

[descrição do programa]

*/

#include <stdio.h>
#include <string.h>
#include "lab07.h"

#define MAX_PALAVRAS 250
#define MAX_CARACTERES_PAL 21
#define MAX_CARACTERES_FRASE 251
#define MAX_FRASES 50

/* Função obrigatória proxima_palavra

Objetivo: função que extrai a próxima palavra da frase de entrada a partir do índice início.
 
Entrada:	- a string "frase" que será analisada
			- a string "palavra" onde vai ser copiada a palavra encontrada (com o \0 adicionado)
			- um inteiro que representa o índice do início da palavra na frase

Saida:   	devolve -1 se a string s chegou ao fim, caso contrário, devolve o índice de início da próxima palavra
 */
int proxima_palavra(char frase[], char palavra[], int inicio)
{
	int i, f;
	
	while ( (frase[inicio] < 'a') || (frase[inicio] > 'z') )
	{
		if (frase[inicio] == '\0')
		{
			return -1;
		}
		inicio++;
	}
	
	i = inicio;
	
	while ( (frase[i] >= 'a') && (frase[i] <= 'z') )
	{
		if (frase[i] == '\0')
		{
			return -1;
		}
		i++;
	}

	for (f = 0; f < (i-inicio); f++)
	{
		palavra[f] = frase[(inicio+f)];
	}
	palavra[(f)] = '\0';
	return i;
}


/* Função obrigatória verifica_marcador

Objetivo: verifica se palavra de entrada é um marcador temporal.
 
Entrada:	- a matriz de marcadores temporais "macVetor"
			- a palavra a ser analisada "palavra"

Saida:   	Se a palavra for um marcador, devolve o índice correspondente em "marcVetor", senão devolve -1
 */
int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[])
{
	int i;
	int dif_palavras;
	for (i = 0; i<N_MARCADORES; i++)
	{
		dif_palavras = strncmp(marcVetor[i], palavra, MAX_CARACTERES_PAL);
		
		if (dif_palavras == 0) /* Palavra é um marcador temporal */
		{
			return i;
		}
	}
	return -1;
}


/* Função MINHA analisa_ocorrencia

Objetivo: Verifica se, numa determinada frase, há tanto uma determinada palavra a ser analisada quanto um marcador temporal
		  (ambos dados na entrada).
 
Entrada:	- um vetor de strings com todas as palavras da frase (sem repetições) "palavras_frase"
			- o marcador a ser analisada "marcador"
			- a palavra a ser analisada "pal_analisada"

Saida:   	Se houver tanto a ocorrência do marcador quanto a palavra analisada na frase, a função devolve 2. Se ocorre
			apenas a palavra analisada, devolve 1. Senão, devolve 0.

*/
int analisa_ocorrencia(char palavras_frase[MAX_PALAVRAS][MAX_CARACTERES_PAL], char marcador[TAM_MARCADORES], char pal_analisada[MAX_CARACTERES_PAL])
{
	int i=0;
	int flag = 0;
	
	/* Loop roda até achar a palavra analisada no vetor de palavras de uma frase,
	   ou chegar no limite de palavras do vetor */
	while ((flag == 0) && (i<MAX_PALAVRAS))
	{
		if (strcmp(palavras_frase[i], pal_analisada) == 0)
		/* pal_analisada está em palavras_frase[i] */
		{
			flag = 1;
		}
	i++;
	}
	
	i=0;
	while ((flag == 1) && (i<MAX_PALAVRAS))
	{
		if (strcmp(palavras_frase[i], marcador) == 0)
		/* marcador está em palavras_frase[i] */
		{
			flag = 2;
		}
	i++;
	}
	
	if (flag == 1) return 1;
	else if (flag == 2) return 2;
	else return 0;
}


int main()
{
	char marcadores[N_MARCADORES][TAM_MARCADORES] = MARCADORES;
	char palavra[MAX_PALAVRAS][MAX_CARACTERES_PAL];
	char palavra_aux[MAX_CARACTERES_PAL];
	char frase[MAX_FRASES][MAX_CARACTERES_FRASE];
	char palavra_frase[MAX_FRASES][MAX_PALAVRAS][MAX_CARACTERES_PAL];
	char palavra_analise[MAX_PALAVRAS][MAX_CARACTERES_PAL];
	
	int n_frases  = 0;
	int n_analise = 0;
	int soma_simultanea[MAX_PALAVRAS][N_MARCADORES];
	int soma_ocorrencia[MAX_PALAVRAS][N_MARCADORES];
	int result[MAX_PALAVRAS][N_MARCADORES];
	int maior_result[MAX_PALAVRAS] = {0};
	int naoRelacionou_flag[MAX_PALAVRAS] = {0};
	int cont[MAX_PALAVRAS] = {0};
	
	int i=0, j=0, k=0;
	int aux = 0, flag = 0;
	
	/* Inicialização das vetores multidimensionais */
	for (i=0; i<MAX_PALAVRAS; i++)
	{
		palavra[i][0] = '\0';
		palavra_analise[i][0] = '\0';
	}
	
	palavra_aux[0] = '\0';
	
	for (i=0; i<MAX_FRASES; i++)
	{
		frase[i][0] = '\0';
		for (j=0; j<MAX_PALAVRAS; j++)
		{
			palavra_frase[i][j][0] = '\0';
		}
	}
	
	for (i=0; i<MAX_PALAVRAS; i++)
	{
		for (j=0; j<N_MARCADORES; j++)
		{
			soma_simultanea[i][j] = 0;
			soma_ocorrencia[i][j] = 0;
			result[i][j] = 0;
		}
	}
	
	/* Lê o numero de frases que serão processadas */
	scanf("%d",&n_frases);
	
	/* Lê, uma por uma, as frases */
	getchar(); /* Pega o \n depois de leitura do int */
	for (i=0; i<n_frases; i++)
	{
		fgets(frase[i], MAX_CARACTERES_FRASE, stdin);
	}
	
	/* Le a número de palavras que serão analisadas com os marcadores temporais */
	scanf("%d",&n_analise);
	
	/* Lê, uma por uma, as palavras que serão analisadas */
	getchar();
	for (i=0; i<n_analise; i++)
	{
		fgets(palavra_analise[i], MAX_CARACTERES_PAL, stdin);
		
		j = 0;
		while (palavra_analise[i][j] != '\n')
		{
			j++;
		}
		palavra_analise[i][j] = '\0';
	}
	
	/* Transforma todas as frases em caracteres minusculos, eliminando tambem os pontos */
	for (i=0; i<n_frases; i++)
	{
		minusculas(frase[i]);
	}
	
	for (i=0; i<n_analise; i++)
	{
		minusculas(palavra_analise[i]);
	}
	
	
	
	/* Cria um vetor com todas palavras das frases, sem repetir */
	for (i=0; i<n_frases; i++)
	{
		aux = 0;
		for (j=0; j<MAX_PALAVRAS; j++)
		{
			aux = proxima_palavra(frase[i], palavra_aux, aux);
			
			/* Palavra contida na string palavra_aux, resta saber se ela já está no vetor de palavras */
			flag = 0;
			k = 0;
			while ( (flag == 0) && (k < MAX_PALAVRAS) )
			{
				if (strcmp (palavra_aux, palavra[k]) == 0)
				/* Se palavra[k] for igual palavra_aux */
				{
					flag = 1;
					/* palavra_aux já está no vetor palavra[] */
				}
				else if (strcmp (palavra[k], "") == 0)
				/* palavra[k] está vazia e pode receber palavra_aux */
				{
					strcpy(palavra[k], palavra_aux);
					flag = 1;
				}
				k++;
				/* Loop roda até achar uma posição livre para copiar palavra_aux
				   ou chegar na ultima posição do vetor palavra[] 
				   ou detectar que palavra_aux já está no vetor palavra[] */
			}
		}
	}
	
	/* Cria um vetor tridimensional, com todas as palavras frase-a-frase, sem repetir
		palavra_frase[n da frase][n da palavra][palavra]	*/
	for (i=0; i<n_frases; i++)
	{
		aux = 0;
		for (j=0; j<MAX_PALAVRAS; j++)
		{
			aux = proxima_palavra(frase[i], palavra_aux, aux);
			/* Palavra contida na string palavra_aux, resta saber se ela já está no vetor de palavras daquela frase */
			flag = 0;
			k = 0;
			while ( (flag == 0) && (k < MAX_PALAVRAS) )
			{
				if (strcmp (palavra_aux, palavra_frase[i][k]) == 0)
				/* Se palavra_frase[i][k] for igual palavra_aux */
				{
					flag = 1;
					/* palavra_aux já está no vetor palavra[] */
				}
				else if (strcmp (palavra_frase[i][k], "") == 0)
				/* palavra_frase[i][k] está vazia e pode receber palavra_aux */
				{
					strcpy(palavra_frase[i][k], palavra_aux);
					flag = 1;
				}
				k++;
			}
		}
	}
	
	
	/* Soma as ocorrencias simutâneas ou não de palavras a serem analisadas e marcadores temporais de todas as frase
		soma_ocorrencia[n da palavra em "palavra_analise"][n do marcador em "marcadores"] = valor da soma para todas as frases
			só ocorrencia da palavra analisada
		soma_simultanea[n da palavra em "palavra_analise"][n do marcador em "marcadores"] = valor da soma para todas as frases 
			ocorrencia da palavra analisada E marcador temporal SIMULTANEAMENTE.  */
	for (i=0; i<n_analise; i++)
	{
		maior_result[i] = 0;
		
		for (j=0; j<N_MARCADORES; j++)
		{
			soma_ocorrencia[i][j] = 0;
			soma_simultanea[i][j] = 0;
			result[i][j] = 0;
			
			for (k=0; k<n_frases; k++)
			{
				if (analisa_ocorrencia(palavra_frase[k], marcadores[j], palavra_analise[i]) == 1)
				{
					soma_ocorrencia[i][j] += 1;
				}
				if (analisa_ocorrencia(palavra_frase[k], marcadores[j], palavra_analise[i]) == 2)
				{
					soma_simultanea[i][j] += 1;
					soma_ocorrencia[i][j] += 1;
				}	
			}
			
			if (soma_simultanea[i][j] != 0)
			{
				result[i][j] = ((soma_simultanea[i][j])*100) / (soma_ocorrencia[i][j]);
				if (result[i][j] > maior_result[i])		maior_result[i] = result[i][j];
			}
		}
	}
	
	for (i=0; i<n_analise; i++)
	{
		aux = 0;
		for (j=0; j<n_frases; j++)
		{
			for (k=0; k<N_MARCADORES; k++)
			{
				if (analisa_ocorrencia(palavra_frase[j], marcadores[k], palavra_analise[i]) == 2)
				{
					aux++;
				}
			}
		}
		
		if (aux == 0)
		{
			naoRelacionou_flag[i] = 1;
		}
	}
	
	/* Imprime os resultados, na ordem em que foram entradas as palavras a serem analisadas */
	for (i=0; i<n_analise; i++)
	{
		if (naoRelacionou_flag[i] == 1)
		{
			printf("<");
			printf("%s",palavra_analise[i]);
			printf("> nao se relacionou com nenhum marcador temporal.\n");
		}
		else
		{
			for (j=0; j<N_MARCADORES; j++)
			{
				if (result[i][j] == maior_result[i] && result[i][j] != 0)
				{
					printf("<");
					printf("%s",palavra_analise[i]);
					printf("> se relaciona com <");
					printf("%s",marcadores[j]);
					printf("> em %d %% das ocorrencias.\n",maior_result[i]);
				}
			}
		}
	}
	
	/* Imprime o vetor com todas as palavras, sem repetições */
	i=0;
	while ((palavra[i][0] != '\0') && (i<MAX_PALAVRAS))
	{
		printf("%s ",palavra[i]);
		i++;
	}
	printf("\n");
	
	/* Cria e imprime o vetor com o número de ocorrências em frases de cada palavra do vetor anterior */
	i=0;
	while (palavra[i][0] != '\0')
	{
		for (j=0; j<n_frases; j++)
		{
			cont[i] += analisa_ocorrencia(palavra_frase[j], "asdf7", palavra[i]);
		}
		
		printf("%d ",cont[i]);
		i++;
	}
	
	printf("\n");
	
	return 0;
}