#include <stdio.h>

int main()
{
	char str[300];
	char palavra[1000][30];
	cursor = 0;
	
	scanf("%s",str);
	cursor = proxima_palavra(str, palavra[inicio], cursor);	
	printf("Cursor: %d\n");
	cursor = proxima_palavra(str, palavra[inicio], cursor);	
	printf("Cursor: %d\n");
	cursor = proxima_palavra(str, palavra[inicio], cursor);	
	printf("Cursor: %d\n");
	cursor = proxima_palavra(str, palavra[inicio], cursor);	
	printf("Cursor: %d\n");
	cursor = proxima_palavra(str, palavra[inicio], cursor);	
	printf("Cursor: %d\n");
	cursor = proxima_palavra(str, palavra[inicio], cursor);	
	printf("Cursor: %d\n");

	return 0;	
}


int proxima_palavra(char frase[], char palavra[], int inicio)
{
	int i;
	i = inicio;
	while ( !(frase[i] >= 'a') && !(frase[i] <= 'z') )
	{
		i++;
	}
	
	while ( (frase[i] >= 'a') && (frase[i] <= 'z') )
	{
		i++;
	}
	
	return i;
}