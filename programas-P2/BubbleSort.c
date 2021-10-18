#include <stdio.h>

int main()
{
	int n;
	int v[30];
	int i, j, k;
	int aux;
	
	printf("Digite o tamanho do vetor (max = 30):\n");
	scanf("%d",&n);
	printf("Digite os elementos do vetor:\n");
	
	for (i=0; i<n; i++)
	{
		scanf("%d",&v[i]);
	}
	
	for (i=0; i<n; i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n Começando bubble sort:\n");
	
	for (i=(n-1); i>=0; i--)
	{
		for (j=0; j<i; j++)
		{
			if (v[j] > v[j+1])    /* Usar ">" para crescente, "<" para descrescente */
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
		printf("Iteração %d:\t",(n-i));
		for (k=0; k<n; k++)
		{
			printf("%d ",v[k]);
		}
		printf("\n");
	}
}