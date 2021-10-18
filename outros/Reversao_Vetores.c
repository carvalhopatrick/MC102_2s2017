	
#include <stdio.h>
	
int main()
{
		
	int vetor[100]={0};
	int auxI;
	int n, i, f;
	
	scanf("%d",&n);
	f = n-1;
	
	for (i=0; i<n; i++)
		scanf("%d",&vetor[i]);
		
	for (i=0; i<n/2; i++)
	{
		auxI=vetor[f];
		vetor[f]=vetor[i];
		vetor[i]=auxI;
		f--;		
	}
	
	for (i=0; i<n; i++)
		printf("%d ",vetor[i]);
	printf("\n");
}