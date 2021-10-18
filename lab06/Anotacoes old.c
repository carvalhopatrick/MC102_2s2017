Ler e criar a matriz mapa

Ler 1 por 1, de mapa[1][1] até mapa[height][width] o conteúdo do mapa

	if (mapa[i][j] == 1)
	{
		/* Se posições adjacentes forem 0 */
		if (	(mapa[i-1][j] == 0) && (mapa[i-1][j+1] == 0) && (mapa[i][j+1] == 0) \
			 &&	(mapa[i+1][j+1] == 0) && (mapa[i+1][j] == 0) && (mapa[i+1][j-1] == 0) \
			 &&	(mapa[i][j-1] == 0) && (mapa[i-1][j-1] == 0) )
		{
			mapa[i][j] = ilhas+2;
			ilhas++;
		}
		
		/* Se houve posição adjacente != 0 */
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
		if (mapa[i-1][j] != 0)
		{
			adjacente[0] = mapa[i-1][j]
		}
