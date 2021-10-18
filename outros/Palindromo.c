#include <stdio.h>

int main()
{
	char str[60];
	int tam = 0;
	int i = 0;
	int cont = 0;
	
	printf("Digite a palavra:\n");
	scanf("%s",str);
	
	while (str[i] != '\0')
	{
		tam++;
		i++;
	}
	tam--;
	
	for (i=0; i<((tam+1)/2); i++)
	{
		if (str[i] == str[(tam-i)])
			cont++;
	}
	
	tam++;
	if (tam%2 == 0)
		cont = cont*2;
	if(tam%2 == 1)
		cont = (cont*2)+1;
	if (cont == tam)
		printf("É palíndromo\n");
	else
		printf ("Não é palíndromo\n");
	
	return 0;
}
