/*
Lab08 - Superis Vincio Grandia
MC102C 2s2017
Patrick Penacho Carvalho 185388

O programa lê um arquivo .svg, contendo (em comentários) instruções para transformações dos 
polígonos contidos nele.
Em seguida, o programa realiza as transformações e gera o arquivo .svg de saída.

Necessário "lab08.h"

*/

#include "lab08.h"
#include <math.h>

#define MAX_POLIGONS    250
#define MAX_POINTS      500
#define MAX_OPERATIONS  60000
#define MAX_STYLE       256
#define PI 3.14159265358979323846

/* Função f_copy_svg
Objetivo:	Copia os dados do poligono original para o poligono de trabalho.

Entrada:	- Vetores do poligono de trabalho
			- Vetores do poligono original
			
Saída:		- Não retorna nenhum valor, porém modifica os vetores dos poligonos.
*/
void f_copy_svg(int n[], double p[][2], char s[], int original_n2[], double original_p2[][2], char original_s2[])
{
	int i = 0;
	
	n[0] = original_n2[0];
	
	for (i=0; i<MAX_POINTS; i++)
	{
		p[i][0] = original_p2[i][0];
		p[i][1] = original_p2[i][1];
	}
	
	for (i=0; i<MAX_STYLE; i++)
	{
		s[i] = original_s2[i];
	}
}

/* Função f_scale_svg

Objetivo:	Amplia (ou diminui) o tamanho de um poligono.

Entrada:	- Número de pontos do poligono (n_pontos = n2)
			- Coordenadas do poligono (coords = p2)
			- Parametros de escala (param = p1[op])
			
Saída:		- Não retorna nenhum valor, porém modifica os vetores dos poligonos.
*/
void f_scale_svg(int n_pontos[1], double coords[][2], double param[2])
{
	int i = 0;
	
	for (i=0; i<n_pontos[0]; i++)
	{
		coords[i][0] = coords[i][0] * param[0];
		coords[i][1] = coords[i][1] * param[1];
	}
}

/* Função f_translate_svg

Objetivo:	Amplia (ou diminui) o tamanho de um poligono.
			Lembrando que o padrão SVG considera o eixo X+ para direita e Y+ para baixo.

Entrada:	- Número de pontos do poligono (n_pontos = n2)
			- Coordenadas do poligono (coords = p2)
			- Parametros de translação (param = p1[op])
			
Saída:		- Não retorna nenhum valor, porém modifica os vetores dos poligonos.
*/
void f_translate_svg(int n_pontos[1], double coords[][2], double param[2])
{
	int i = 0;
	
	for (i=0; i<n_pontos[0]; i++)
	{
		coords[i][0] = coords[i][0] + param[0];
		coords[i][1] = coords[i][1] + param[1];
	}
}

/* Função f_rotate_svg		INCOMPLETA = procurar algoritmo de rotação

Objetivo:	Rotaciona um poligono. (Ângulo positivo = sentido horário)

Entrada:	- Número de pontos do poligono (n_pontos = n2)
			- Coordenadas do poligono (coords = p2)
			- Parametro (ângulo) de rotação (param = p1[op][0])
			
Saída:		- Não retorna nenhum valor, porém modifica os vetores dos poligonos.
*/
void f_rotate_svg(int n_pontos[1], double coords[][2], double angle)
{
	int i = 0;
	
	double s = sin(angle * PI / 180);
	double c = cos(angle * PI / 180);
	
	double x, y;
	
	for (i=0; i<n_pontos[0]; i++)
	{
		x = coords[i][0];
		y = coords[i][1];
		
		coords[i][0] = (x * c) - (y * s);		/* x */
		coords[i][1] = (x * s) + (y * c);   	/* y */
	}		
}


/* Função transform_svg

Objetivo:	Aplica todas as operações de transformação ordenadas num determinado
			poligono, além de "imprimi-lo" no arquivo SVG.

Entrada:	- Todos os vetores de entrada lidos pela primeira iteração de scan_svg
			- Todos os vetores lidos pelas iterações seguintes de scan_svg (original_)
			
Saída:		- Não retorna nenhum valor, porém utiliza a função print_svg.
*/
void transform_svg(int scan_n1[], double scan_p1[][2], char scan_s1[], int original_n2[1], double original_p2[][2], char original_s2[])
{
	int op = 0;
	int i = 0;
	
	int n[1] = {0};
	double p[MAX_POINTS][2];
	char s[MAX_STYLE];
	
	/* Inicialização dos vetores */
	for (i=0; i<MAX_POINTS; i++)
	{
		p[i][0] = 0;
		p[i][1] = 0;
	}
	s[0] = '\0';
	
	/* Loop principal: Cada iteração, uma operação */
	for (op = 0; op < scan_n1[0]; op++)
	{
		switch (scan_s1[op])
		{
			case 'C' :
				if (op > 0)
				{
					print_svg(n, p, s);
					/* O poligono atual será impresso após as transformações,
						exceto se for a primeira operação C do arquivo */
				}
				f_copy_svg(n, p, s, original_n2, original_p2, original_s2);
				break;
				
			case 'S' :
				f_scale_svg(n, p, scan_p1[op]);
				break;
				
			case 'T' :
				f_translate_svg(n, p, scan_p1[op]);
				break;
				
			case 'R' :
				f_rotate_svg(n, p, scan_p1[op][0]);
				break;
		}
	}
	
	/* Imprime o último poligono após as operações de transformação */
	print_svg(n, p, s);
}


int main()
{
	int scan_n1[1] = {0};
	double scan_p1[MAX_OPERATIONS][2];
	char scan_s1[MAX_OPERATIONS];
	
	int scan_n2[1] = {0};
	double scan_p2[MAX_POINTS][2];
	char scan_s2[MAX_STYLE];
	
	int i = 0;
	
	/* Inicialização dos vetores */
	for (i=0; i<MAX_OPERATIONS; i++)
	{
		scan_p1[i][0] = 0;
		scan_p1[i][1] = 0;
	}
	
	for (i=0; i<MAX_POINTS; i++)
	{
		scan_p2[i][0] = 0;
		scan_p2[i][1] = 0;
	}
	
	scan_s1[0] = '\0';
	scan_s2[0] = '\0';
	
	
	/* Primeiro scan do SVG */
	scan_svg(scan_n1, scan_p1, scan_s1);
	/* As variáveis contém agora:
		n1 	= 	número de operações da entrada
		p1 	=	parâmetros de cada operação
		s1	= 	caracteres que representam as operações
	*/
	
	/* Ao chegar no fim do arquivo, n2 valerá -1.
	   Portanto, esse loop irá ler os poligonos até o último. */
	while (scan_n2[0] >= 0)
	{
		scan_svg(scan_n2, scan_p2, scan_s2);
		/* As variáveis contém agora:
			n2	=	número de pontos do poligono i
			p2	=	coordenadas (x,y) de cada ponto do poligono i
			s2	=	Cadeia de formatação do poligono i
		*/
		
		if (scan_n2[0] >= 0)
		{
			transform_svg(scan_n1, scan_p1, scan_s1, scan_n2, scan_p2, scan_s2);
		}
	}
	
	close_svg();
	return 0;
}