1. Ler e criar a matriz mapa

	scanf("%c%c %d %d",&trash,&trash,&width,&height);
	
	for (i=1; i<=height; i++)
	{
		for (j=1; j<=width; j++)
		{
			scanf("%d",&mapa[i][j]);
		}
	}

	
2. Ler 1 por 1, de mapa[1][1] até mapa[height][width] o conteúdo do mapa,
   marcando e contando as possiveis ilhas

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
	

3. Reler o mapa, de trás para frente, reajeitando as ilhas marcadas e diminuindo
   na contagem.
   
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
					ilhas--;
				}
			}
		}
	}