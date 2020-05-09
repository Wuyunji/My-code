#include <stdio.h>

int main(void)
{
	int i=0,k;
	double sum=0;
	scanf("%d",&k);
	while(sum<=k)
	{	
		i++;
		sum+=1.0/i;
	}
	printf("%d",i);
	return 0;
}
