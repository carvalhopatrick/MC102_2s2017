/* 
LAB01 - Paleocontato
MC102C 2s2017
Patrick Penacho Carvalho 185388
*/

#include <stdio.h>

int main()
{
	int b1=0, b2=0, b3=0, b4=0, b5=0, b6=0, b7=0, b8=0;
	int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0;
	int i_prodDiacriticos = 0;
	int f1=0, f2=0, f3=0, f4=0, f5=0, f6=0, f7=0, f8=0;
	
	
	/* ========================== 1. LEITURA DOS DADOS ========================== */
	
	scanf("%d%d%d%d%d%d%d%d",&b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8);
	scanf("%d%d%d%d%d%d%d%d",&c1,&c2,&c3,&c4,&c5,&c6,&c7,&c8);
	
	
	/* ============================= 2. OPERAÇOES LOGICAS ===================== */
	
	/* 1. Todos os números devem ser somados a 3, se o quarto diacrítico não for 2 ou 9. */
	if((c4 != 2) && (c4 != 9))
	{
		b1 = b1+3;
		b2 = b2+3;
		b3 = b3+3;
		b4 = b4+3;
		b5 = b5+3;
		b6 = b6+3;
		b7 = b7+3;
		b8 = b8+3;
	}
	
	/* 2. Se o primeiro diacrítico estiver entre 11 e 42 (ambos inclusive), some 7 no oitavo número e 8 no sétimo número. */
	if((c1 >= 11) && (c1 <= 42))
	{
		b8 = b8+7;
		b7 = b7+8;
	}
	
	/* 3. Se nenhum diacrítico for par, some o dobro do quinto diacrítico ao primeiro número. */
	if(((c1 % 2) != 0) && ((c2 % 2) != 0) && ((c3 % 2) != 0) && ((c4 % 2) != 0) && ((c5 % 2) != 0) && ((c6 % 2) != 0) && ((c7 % 2) != 0) && ((c8 % 2) != 0))
	{
		b1 = b1+(2*c5);
	}
	
	/* 4. Se ou o terceiro ou o sexto diacríticos forem menores que 20, mas não ambos, some 6 no quarto e quinto números. */
	if((c3 < 20) ^ (c6 < 20)) 	/*   (a ^ b) = a XOR b    */
	{
		b4 = b4+6;
		b5 = b5+6;
	}

	/* 5. Se o último diacrítico não for 3 nem menor que o penúltimo diacrítico, some o segundo diacrítico ao terceiro número */
	if((c8 != 3) && (c8 >= c7))
	{
		b3 = b3+c2;
	}

	/* 6. Se o produto dos diacríticos for um múltiplo de 5 e não for um múltiplo de 10, com exceção do 30, some 1 ao sexto número. */
	i_prodDiacriticos = (c1*c2*c3*c4*c5*c6*c7*c8);
	if( (i_prodDiacriticos == 30) || ( ((i_prodDiacriticos % 5) == 0) && ((i_prodDiacriticos % 10) != 0) ) )
	{
		b6 = b6+1;
	}
	
	/* 7. Se o segundo diacrítico for igual ao último ou o terceiro for igual ao sétimo, também some 1 ao sexto número. */
	if((c2 == c8) || (c3 == c7))
	{
		b6 = b6+1;
	}
	
	
	/* ================= 3. IMPRESSAO DAS LETRAS ============= */

	/* printf("%d %d %d %d %d %d %d %d\n",b1,b2,b3,b4,b5,b6,b7,b8); */ /* only debugging, ****APAGAR DEPOIS**** */
	
	/* Convertendo para ASCII (1=65=A, 2=66=B, ...) */
	f1 = b1+64;
	f2 = b2+64;
	f3 = b3+64;
	f4 = b4+64;
	f5 = b5+64;
	f6 = b6+64;
	f7 = b7+64;
	f8 = b8+64;
	
	/* Resultados invalidos, devem ser descartados (mapeados para 0 ASCII) */
	if (f1 > 91 || f1 < 1) f1 = 0;
	if (f2 > 91 || f2 < 1) f2 = 0;
	if (f3 > 91 || f3 < 1) f3 = 0;
	if (f4 > 91 || f4 < 1) f4 = 0;
	if (f5 > 91 || f5 < 1) f5 = 0;
	if (f6 > 91 || f6 < 1) f6 = 0;
	if (f7 > 91 || f7 < 1) f7 = 0;
	if (f8 > 91 || f8 < 1) f8 = 0;
	/* Nao funciona por si só, invalida os testes com menos de 8 caracteres */
	
	
	/* Espaço em branco (27=91 mapeado para 27=32) */
	if (f1 == 91) f1 = 32;
	if (f2 == 91) f2 = 32;
	if (f3 == 91) f3 = 32;
	if (f4 == 91) f4 = 32;
	if (f5 == 91) f5 = 32;
	if (f6 == 91) f6 = 32;
	if (f7 == 91) f7 = 32;
	if (f8 == 91) f8 = 32;
	
	/* Imprime os caracteres válidos */
	if (f1 != 0) printf("%c",f1);
	if (f2 != 0) printf("%c",f2);
	if (f3 != 0) printf("%c",f3);
	if (f4 != 0) printf("%c",f4);
	if (f5 != 0) printf("%c",f5);
	if (f6 != 0) printf("%c",f6);
	if (f7 != 0) printf("%c",f7);
	if (f8 != 0) printf("%c",f8);	
	printf("\n");
	
    return 0;
}
