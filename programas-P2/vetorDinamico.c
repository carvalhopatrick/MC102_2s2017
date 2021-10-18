#include <stdio.h>
#include <stdlib.h>
struct vetor_dinamico
{
	int *vet, nelementos, cap;
};

int main()
{
	struct vetor_dinamico a;
	
	a.vet = malloc(2*sizeof(int));
	a.nelementos = 0;
	a.cap = 2;
	
	while (scanf("%d", &a.vet[a.nelementos]) != EOF)
	{
		a.nelementos++;
		if(a.nelementos == a.cap)
		{
			a.cap *= 2;
			a.vet = realloc(a.vet, a.cap*sizeof(int));
		}
	}
	for(int i = 0; i < a.nelementos; i++)
	{
		printf("%d ", a.vet[i]);
	}
	printf("\n");
	return 0;
}

