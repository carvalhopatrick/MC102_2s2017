/* 
LAB02 - Explorador de Estrelas
MC102C 2s2017
Patrick Penacho Carvalho 185388
*/

#include <stdio.h>

int main()
{
	int tA=0, tB=0, tC=0, tD=0, tE=0, tF=0, tG=0, tH=0, tI=0, tJ=0, tK=0;	/* TEMPOS estrela-estrela */
	int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0,	c9=0;				/* Tempo de CAMINHOS Deneb-Altair */
	
	int menor=0;				/* Menor tempo dentre os caminhos */

	
	/* ========================== 1. LEITURA DOS DADOS ========================== */
	
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&tA,&tB,&tC,&tD,&tE,&tF,&tG,&tH,&tI,&tJ,&tK);
	
	
	/* ======================= 2. DETERMINAÇAO DOS CAMINHOS ======================= */
	
	c1 = tA + tE + tJ;				/*	c1: AEJ 	*/
	c2 = tA + tE + tI + tK;			/*	c2: AEIK 	*/
	c3 = tA + tD + tF + tJ;			/*	c3: ADFJ	*/
	c4 = tA + tD + tF + tI + tK;	/*	c4: ADFIK	*/
	c5 = tA + tD + tG + tK;			/*	c5: ADGK	*/
	c6 = tB + tF + tJ;				/*	c6: BFJ		*/
	c7 = tB + tF + tI + tK;			/*	c7: BFIK	*/
	c8 = tB + tG + tK;				/*	c8: BGK		*/
	c9 = tC + tH + tK;				/*	c9: CHK		*/
	
	
	/* ======================== 3. CHECAR MENOR TEMPO FINAL ======================== */
	
	if (c1<=c2 && c1<=c3 && c1<=c4 && c1<=c5 && c1<=c6 && c1<=c7 && c1<=c8 && c1<=c9)
		menor = c1;
	
	if (c2<=c1 && c2<=c3 && c2<=c4 && c2<=c5 && c2<=c6 && c2<=c7 && c2<=c8 && c2<=c9)
		menor = c2;
	
	if (c3<=c1 && c3<=c2 && c3<=c4 && c3<=c5 && c3<=c6 && c3<=c7 && c3<=c8 && c3<=c9)
		menor = c3;
	
	if (c4<=c2 && c4<=c3 && c4<=c1 && c4<=c5 && c4<=c6 && c4<=c7 && c4<=c8 && c4<=c9)
		menor = c4;
	
	if (c5<=c2 && c5<=c3 && c5<=c4 && c5<=c1 && c5<=c6 && c5<=c7 && c5<=c8 && c5<=c9)
		menor = c5;
	
	if (c6<=c2 && c6<=c3 && c6<=c4 && c6<=c5 && c6<=c1 && c6<=c7 && c6<=c8 && c6<=c9)
		menor = c6;
	
	if (c7<=c2 && c7<=c3 && c7<=c4 && c7<=c5 && c7<=c6 && c7<=c1 && c7<=c8 && c7<=c9)
		menor = c7;
	
	if (c8<=c2 && c8<=c3 && c8<=c4 && c8<=c5 && c8<=c6 && c8<=c7 && c8<=c1 && c8<=c9)
		menor = c8;
		
	if (c9<=c2 && c9<=c3 && c9<=c4 && c9<=c5 && c9<=c6 && c9<=c7 && c9<=c8 && c9<=c1)
		menor = c9;
	

	/* ===================== 4. CHECAR POSSIBILIDADE DE PORTAL ===================== */
	/* O portal pode ser utilizado quando o tempo parcial ou final for multiplo de 6 */

	if (tA<tB && tA<tC) 	/* A menor entre ABC */
	{
		if (tD<tE) 
		{
			if (tF<tG)
			{
				if (tI<tJ)
				{
					if((c4 % 6) == 0) menor = 0;
				}
				if (tJ<tI)
				{
					if((c3 % 6) == 0) menor = 0;
				}
			}
			if (tG<tF)
			{
				if((c5 % 6) == 0) menor = 0;
			}
		}
		if (tE<tD)
		{
			if (tJ<tI)
			{
				if((c1 % 6) == 0) menor = 0;
			}
			if (tI<tJ)
			{
				if((c2 % 6) == 0) menor = 0;
			}
		}
	}
	
	if (tB<tA && tB<tC) 	/* B menor entre ABC */
	{
		if (tF<tG)
		{
			if (tI<tJ)
			{
				if((c7 % 6) == 0) menor = 0;
			}
			if (tJ<tI)
			{
				if((c6 % 6) == 0) menor = 0;
			}
		}
		if (tG<tF)
		{
			if((c8 % 6) == 0) menor = 0;
		}
	}
	
	if (tC<tA && tC<tB) 	/* C menor entre ABC */
	{
		if((c9 % 6) == 0) menor = 0;
	}
	
	/* ======================= 5. IMPRIMIR MENOR TEMPO ======================= */
	
	printf("%d\n",menor);	
	
	return(0);
}	