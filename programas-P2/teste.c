#include <stdio.h>
#include <stdlib.h>

int pal(int *v, int i, int n)
{
	if (i < (n/2))
	{
		if (v[i] == v[(n-1)-i])
			pal(v, i+1, n);
		else
			return 0;
	}
	else
		return 1;
}


int main()
{
	int n, i, res;
	int *v;
	printf("Tamanho do vetor:\n");
	scanf("%d",&n);
	
	v = malloc(n*(sizeof(int)));
	
	printf("Conteudo:\n");
	for (i=0; i<n; i++)	scanf("%d",&v[i]);
	
	res = pal(v, 0, n);
	printf("e palindromo? %d\n",res);
}
