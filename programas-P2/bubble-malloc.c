#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *v, int n)
{
	int i, j, aux;
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
		}
}

int main()
{
	int *p = NULL;
	int tam, i;
	
	printf("QUAL O TAMANHO DO VETOR??????? ");
	scanf("%d",&tam);
	printf("\n");
	p = malloc(tam*sizeof(*p));
	printf("DIGITE OS VALORES DO VETOR:\n");
	
	for (i=0; i<tam; i++) scanf("%d", &p[i]);	
	printf("Vetor:\n");
	for (i=0; i<tam; i++) printf("%d ",p[i]);
	printf("\n");
	
	bubbleSort(p, tam);
	
	printf("Vetor ordenado:\n");
	for (i=0; i<tam; i++) printf("%d ",p[i]);
	printf("\n");
}