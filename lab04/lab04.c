
/*
LAB04 - Space Invaders
MC102C 2s2017
Patrick Penacho Carvalho 185388

O programa exibe, na tela, 10 iterações de uma versão simplificada do famoso game Space Invaders.
Dados de entrada:
	Tamanho (lado) do "tabuleiro" quadrado.
	5 pares ordenados, indicando a linha e a coluna de cada nave adversária
	Posição (coluna) da nave do jogador

Saída: 10 iterações (separadas) do jogo. A representação da iteração é dada da seguinte forma:
	Espaço em branco		.			(ponto)
	Nave do jogador			X			(caractere X)
	Nave adversária			*			(asterisco)
	Feixe de laser			|			(barra vertical)
	
*/

#include <stdio.h>

int sizeTabuleiro = 0;					/* Tamanho do lado do tabuleiro quadrado. Vai de 4 a 20. */
int player_col = 0;						/* Coluna de posição da nave do jogador */
int frame = 1;							/* Frame (iteração) atual do programa. Vai de 1 a 10. */
int cursorLinha = 1, cursorCol = 1;		/* Posição dos cursores de linha e coluna, para controle no loop de impressão */ 
int n1_linha = 0, n2_linha = 0, n3_linha = 0, n4_linha = 0, n5_linha = 0;	/* Linhas naves 1-5 */
int n1_col = 0, n2_col = 0, n3_col = 0, n4_col = 0, n5_col = 0;				/* Colunas naves 1-5 */

int i = 0;		/* Variável auxiliar de controle dos loops "for" */

int laser_linha = 0;		/* Linha em que se encontra a ponta do feixe de laser */
int atingida1_linha = 0;	/* Indica a linha em que possivelmente foi atingida a 1a nave em cada iteração */
int atingida2_linha = 0;	/* Indica a linha em que possivelmente foi atingida a 2a nave em cada iteração */
int atingida3_linha = 0;	/* Indica a linha em que possivelmente foi atingida a 3a nave em cada iteração */
int atingida4_linha = 0;	/* Indica a linha em que possivelmente foi atingida a 4a nave em cada iteração */
int atingida5_linha = 0;	/* Indica a linha em que possivelmente foi atingida a 5a nave em cada iteração */

/* 22 variáveis */

int main()
{
	/* Leitura dos dados de entrada */
	scanf("%d",&sizeTabuleiro);
	scanf("%d %d",&n1_linha,&n1_col);
	scanf("%d %d",&n2_linha,&n2_col);
	scanf("%d %d",&n3_linha,&n3_col);
	scanf("%d %d",&n4_linha,&n4_col);
	scanf("%d %d",&n5_linha,&n5_col);
	scanf("%d",&player_col);
	
	laser_linha = (sizeTabuleiro+1);
	
	/* Controle dos frames */
	for (frame = 1; frame <= 10; frame++)
	{
		/* Reseta variaveis de controle do laser */
		atingida1_linha = 0;
		atingida2_linha = 0;
		atingida3_linha = 0;
		atingida4_linha = 0;
		atingida5_linha = 0;
		
		/* Movimentação em zig-zag das naves */
		if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
		{	/* Move todas as naves 1 casa para a direita */
			n1_col += 1;
			n2_col += 1;
			n3_col += 1;
			n4_col += 1;
			n5_col += 1;
		}
		
		if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
		{	/* Move todas as naves 1 casa para a esquerda */
			n1_col -= 1;
			n2_col -= 1;
			n3_col -= 1;
			n4_col -= 1;
			n5_col -= 1;
		}
			
		/* Checa se houve algum movimento invalido, e conserta */
		if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)	/* Frames com movimentação para a direita */
		{
			if (n1_col > sizeTabuleiro)
				n1_col -= 1;
			if (n2_col > sizeTabuleiro)
				n2_col -= 1;
			if (n3_col > sizeTabuleiro)
				n3_col -= 1;
			if (n4_col > sizeTabuleiro)
				n4_col -= 1;
			if (n5_col > sizeTabuleiro)
				n5_col -= 1;
		}
		if (frame == 3 || frame == 4 || frame == 7 || frame == 8)		/* Frames com movimentação para a esquerda */
		{
			if (n1_col < 1)
				n1_col += 1;
			if (n2_col < 1)
				n2_col += 1;
			if (n3_col < 1)
				n3_col += 1;
			if (n4_col < 1)
				n4_col += 1;
			if (n5_col < 1)
				n5_col += 1;
		}	

		/* Conserta possíveis problemas de duas naves ocupando o mesmo espaço */
		for (i = 1; i <= 5; i++)	/* Faz até 5 correções (máximo teórico) */
		{
			if (n1_linha == n2_linha && n1_col == n2_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n1_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n1_col += 1;
			}
			if (n1_linha == n3_linha && n1_col == n3_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n1_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n1_col += 1;
			}
			if (n1_linha == n4_linha && n1_col == n4_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n1_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n1_col += 1;
			}
			if (n1_linha == n5_linha && n1_col == n5_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n1_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n1_col += 1;
			}
			if (n2_linha == n3_linha && n2_col == n3_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n2_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n2_col += 1;
			}
			if (n2_linha == n4_linha && n2_col == n4_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n2_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n2_col += 1;
			}
			if (n2_linha == n5_linha && n2_col == n5_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n2_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n2_col += 1;
			}
			if (n3_linha == n4_linha && n3_col == n4_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n3_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n3_col += 1;
			}
			if (n3_linha == n5_linha && n3_col == n5_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n3_col -= 1;
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n3_col += 1;
			}
			if (n4_linha == n5_linha && n4_col == n5_col)
			{
				if (frame == 2 || frame == 5 || frame == 6 || frame == 9 || frame == 10)
					n4_col -= 1;			
				if (frame == 3 || frame == 4 || frame == 7 || frame == 8)
					n4_col += 1;
			}		
		}	/* Fim for dos 5 consertos */
		
		/* Elminação das naves */
		if (laser_linha > 1)
			laser_linha -= 1;
		
		if (n1_col == player_col)
		{
			if (n1_linha >= laser_linha)
			{
				atingida1_linha = n1_linha;
				n1_linha = -11;
			}
		}
		if (n2_col == player_col)
		{
			if (n2_linha >= laser_linha)
			{
				atingida2_linha = n2_linha;
				n2_linha = -11;
			}
		}
		if (n3_col == player_col)
		{
			if (n3_linha >= laser_linha)
			{
				atingida3_linha = n3_linha;
				n3_linha = -11;
			}
		}
		if (n4_col == player_col)
		{
			if (n4_linha >= laser_linha)
			{
				atingida4_linha = n4_linha;
				n4_linha = -11;
			}
		}
		if (n5_col == player_col)
		{
			if (n5_linha >= laser_linha)
			{
				atingida5_linha = n5_linha;
				n5_linha = -11;
			}
		}
		
		/* Recua o laser para 1 coluna abaixo do nave mais baixa atingida */
		if (atingida1_linha != 0 || atingida2_linha != 0 || atingida3_linha != 0 || atingida4_linha != 0 || atingida5_linha != 0)
		{
			if (atingida1_linha > atingida2_linha && atingida1_linha > atingida3_linha \
				&& atingida1_linha > atingida4_linha && atingida1_linha > atingida5_linha)
			{
				laser_linha = (atingida1_linha+1);
			}
			if (atingida2_linha > atingida1_linha && atingida2_linha > atingida3_linha \
				&& atingida2_linha > atingida4_linha && atingida2_linha > atingida5_linha)
			{
				laser_linha = (atingida2_linha+1);
			}
			if (atingida3_linha > atingida2_linha && atingida3_linha > atingida1_linha \
				&& atingida3_linha > atingida4_linha && atingida3_linha > atingida5_linha)
			{
				laser_linha = (atingida3_linha+1);
			}
			if (atingida4_linha > atingida2_linha && atingida4_linha > atingida3_linha \
				&& atingida4_linha > atingida1_linha && atingida4_linha > atingida5_linha)
			{
				laser_linha = (atingida4_linha+1);
			}
			if (atingida5_linha > atingida2_linha && atingida5_linha > atingida3_linha \
				&& atingida5_linha > atingida4_linha && atingida5_linha > atingida1_linha)
			{
				laser_linha = (atingida5_linha+1);
			}
		}
		
		/* Impressão do frame */
		for (cursorLinha = 1; cursorLinha < sizeTabuleiro; cursorLinha++)
		{
			for (cursorCol = 1; cursorCol <= sizeTabuleiro; cursorCol++)
			{
				if (n1_linha == cursorLinha && n1_col == cursorCol)      
					printf("* ");
				else
				{
					if (n2_linha == cursorLinha && n2_col == cursorCol)
						printf("* ");
					else
					{
						if (n3_linha == cursorLinha && n3_col == cursorCol)
							printf("* ");
						else
						{
							if (n4_linha == cursorLinha && n4_col == cursorCol)
								printf("* ");
							else
							{
								if (n5_linha == cursorLinha && n5_col == cursorCol)
									printf("* ");
								else
								{
									if (laser_linha <= cursorLinha && player_col == cursorCol)
										printf("| ");
									else
									{
										printf(". ");
									}
								}
							}
						}
					}
				}
			}	/* Fim do for cursorCol */
			printf("\n");
		} /* Fim do for cursorLinha */	
		
		/* Impressão da última linha */
		for (i = 1; i < (sizeTabuleiro - (sizeTabuleiro - player_col)); i++)
		{
			printf(". ");
		}
		printf("X ");
		for (i = 1; i <= (sizeTabuleiro - player_col); i++)
		{
			printf(". ");
		}
		printf("\n\n");
	}	/* Fim for dos Frames */

	return 0;
}