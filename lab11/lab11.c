#include <stdio.h>

int digitos(int n)
{
	int a, b;
	a = ((n % 100)-(n % 10))/10;
	b = n % 10;
	/*printf("n = %d\t a = %d\t b = %d\n",n,a,b);*/
	return(a*b);
	
}

int gremlin(int n)
{
	if (n == 42) return 1;
	else if (n < 42) return 0;
	else
	{
		/*printf("\nNOVA - n = %d\n",n);*/
		if (n % 2 == 0) /* Regra 1 */
		{
			if (gremlin(n/2) == 1)	return 1;
			/*printf("regra 1 nao rolou n = %d\n", n);*/
		}
		if ((n % 3 == 0) || (n % 4 == 0)) /* Regra 2 */
		{
			if (digitos(n) != 0)
			{
				if (gremlin(n-(digitos(n))) == 1)	return 1;
				/*printf("regra 2 nao rolou n = %d\n", n);*/
			}
		}
		if (n % 5 == 0) /* Regra 3 */
		{
			if	(gremlin(n-42) == 1)	return 1;
			/*printf("regra 3 nao rolou n = %d\n", n);*/
		}
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	if (gremlin(n) == 1)	printf("Sim\n");
	else 	printf("Nao\n");
	return 0;
}