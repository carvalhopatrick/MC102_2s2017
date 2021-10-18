/* 
Lab06 - It's me, Mario!
MC102C 2s2017
Patrick Penacho Carvalho 185388

O programa lê as informações e o conteúdo de um mapa, no formato pbm (tipo P1).
Em seguida, faz a contagem do número de ilhas do mapa e imprime o valor na tela.
As ilhas são formadas por posições adjacentes do mapa, preenchidas com 1.

Exemplo de entrada:

P1				# Código que informa que a entrada é constituida de 0s e 1s (sendo preto = 1)
5 5				# Largura e altura do mapa
0 0 0 1 0	
1 0 0 1 0
1 1 0 1 0		# Conteúdo do mapa
0 0 1 0 0
0 0 0 0 1	

No caso acima, há apenas 2 ilhas.
*/

#include <stdio.h>

int main()
{
	char trash;		/* Para entradas não necessárias no programa */
	int width = 0;		/* Largura (colunas) do mapa */
	int height = 0;		/* Altura (linhas) do mapa */
	int mapa[302][302];	/* Matriz que compõe o mapa */
	int adj[8] = {0}; 	/* Vetor com o conteúdo das posições adjacentes no mapa */
	int menor_adj = 0;	/* Menor valor entre os adjcentes (diferente de 0 e 1) */
	int ilhas = 0;		/* Número de ilhas */
	int cont_ilha[2334] = {0};	/* Vetor para contagem de ilhas */
	int updated_flag = 0;	/* Controle da contagem */
	int i = 0, j = 0, f = 0, s = 0; /* Auxiliares de for */
	
	/* Lê os dados da entrada*/
	scanf("%c%c %d %d",&trash,&trash,&width,&height);
	
	for (i=1; i<=height; i++)
	{
		for (j=1; j<=width; j++)
		{
			scanf("%d",&mapa[i][j]);
		}
	}
	
	/* Faz a primeiro leitura do mapa, contando parcialmente o número de ilhas */
	for (i=1; i<=height; i++)
	{
		for (j=1; j<=width; j++)
		{
			if (mapa[i][j] != 0)
			{
				adj[0] = mapa[i-1][j];
				adj[1] = mapa[i-1][j+1];
				adj[2] = mapa[i][j+1];
				adj[3] = mapa[i+1][j+1];
				adj[4] = mapa[i+1][j];
				adj[5] = mapa[i+1][j-1];
				adj[6] = mapa[i][j-1];
				adj[7] = mapa[i-1][j-1];
				
				/* Verifica o menor adjacente já mapeado anteriormente */
				menor_adj = 0;
				for (f=0; f<8; f++)
				{
					if ((adj[f] >= 2) && (menor_adj == 0))
					{
						menor_adj = adj[f];
					}
					if ( (adj[f] < menor_adj) && (adj[f] != 0) && (adj[f] != 1) )
					{
						menor_adj = adj[f];
					}
				}
				
				/* Preenche a posição atual com o menor adjacente ou com um novo "número de ilha" */
				if (menor_adj != 0)
				{
					mapa[i][j] = menor_adj;
				}
				else
				{
					mapa[i][j] = ilhas+2;
					ilhas++;
				}
			}
		}
	}
	
	/* Leituras secundárias do mapa: reajeita as ilhas marcadas e diminui na contagem */
	for (s=0; s<50; s++)
	{
		for (i = height; i>0; i--)
		{
			for (j = width; j>0; j--)
			{
				if (mapa[i][j] != 0)
				{
					adj[0] = mapa[i-1][j];
					adj[1] = mapa[i-1][j+1];
					adj[2] = mapa[i][j+1];
					adj[3] = mapa[i+1][j+1];
					adj[4] = mapa[i+1][j];
					adj[5] = mapa[i+1][j-1];
					adj[6] = mapa[i][j-1];
					adj[7] = mapa[i-1][j-1];
					
					menor_adj = 0;
					for (f=0; f<8; f++)
					{
						if ((adj[f] >= 2) && (menor_adj == 0))
						{
							menor_adj = adj[f];
						}
						if ( (adj[f] < menor_adj) && (adj[f] != 0) && (adj[f] != 1) )
						{
							menor_adj = adj[f];
						}
					}
					
					if ( (menor_adj != 0) && (menor_adj != mapa[i][j]) )
					{
						mapa[i][j] = menor_adj;
					}
				}
			}
		}
	}
	
	/* Contagem das ilhas */
	for (i = height; i>0; i--)
	{
		for (j = width; j>0; j--)
		{
			if (mapa[i][j] != 0)
			{
				f = 0;
				updated_flag = 0;
				while (updated_flag == 0)
				{
					if (cont_ilha[f] == 0)
					{
						cont_ilha[f] = mapa[i][j];
					}
					if (cont_ilha[f] == mapa[i][j])
					{
						updated_flag = 1;
					}
					f++;
				}
			}
		}
	}
	
	f=0;
	while (cont_ilha[f] != 0)
	{
		f++;
	}
	
	ilhas = f;
	printf("%d\n",ilhas);
	
	return 0;
}