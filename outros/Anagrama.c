#include <stdio.h>

int main()
{
	char str1[30];
	char str2[30];
	
	int tam1=0;
	int tam2=0;
	int cont=0;
	
	int i=0, j=0;
	
	printf("Digite a primeira palavra.\n");
	scanf("%s",str1);
	printf("Digite a segunda palavra.\n");
	scanf("%s",str2);
	
	while(str1[i] != '\0')
	{
		tam1++;
		i++;
	}	

	while(str2[j] != '\0')
	{
		tam2++;
		j++;
	}	
	
	if (tam1 == tam2)
	{
		for (i=0; i<tam1; i++)
		{
			for (j=0; j<tam2; j++)
			{
				if (str1[i] == str2[j])
				{
					cont++;
					str2[j]=0;
				}
			}
		}
	}
	
	if (cont == tam1)	printf("Há um anagrama.\n");
	else 				printf("Não há um anagrama.\n");
	
	return 0;	
}
